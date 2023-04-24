//
//  main.c
//  test
//
//  Created by Chang on 2023-04-13.
//

#include <stdio.h>

// Define a structure to represent a car
struct Car {
    char model[20];
    int year;
    double price;
    int quantity;
};

// Define a function to sell a car from a branch
void sell_car(struct Car* branch_inventory, int num_cars, char* car_model) {
    for (int i = 0; i < num_cars; i++) {
        if (strcmp(branch_inventory[i].model, car_model) == 0) {
            if (branch_inventory[i].quantity > 0) {
                branch_inventory[i].quantity--;
                printf("Car sold: %s\n", car_model);
                printf("New inventory:\n");
                for (int j = 0; j < num_cars; j++) {
                    printf("%s, %d, $%.2f, %d\n", branch_inventory[j].model, branch_inventory[j].year,
                        branch_inventory[j].price, branch_inventory[j].quantity);
                }
                return;
            } else {
                printf("Error: %s is out of stock.\n", car_model);
                return;
            }
        }
    }
    printf("Error: %s not found in inventory.\n", car_model);
}

// Define a function to buy a car for a branch
void buy_car(struct Car* branch_inventory, int num_cars, char* car_model, int quantity) {
    for (int i = 0; i < num_cars; i++) {
        if (strcmp(branch_inventory[i].model, car_model) == 0) {
            branch_inventory[i].quantity += quantity;
            printf("%d %s bought.\n", quantity, car_model);
            printf("New inventory:\n");
            for (int j = 0; j < num_cars; j++) {
                printf("%s, %d, $%.2f, %d\n", branch_inventory[j].model, branch_inventory[j].year,
                    branch_inventory[j].price, branch_inventory[j].quantity);
            }
            return;
        }
    }
    printf("Error: %s not found in inventory.\n", car_model);
}

// Define a function to transfer a car from one branch to another
void transfer_car(struct Car* source_inventory, int num_cars, struct Car* dest_inventory, int dest_num_cars, char* car_model, double transfer_expenses, double currency_rate) {
    for (int i = 0; i < num_cars; i++) {
        if (strcmp(source_inventory[i].model, car_model) == 0) {
            if (source_inventory[i].quantity > 0) {
                source_inventory[i].quantity--;
                for (int j = 0; j < dest_num_cars; j++) {
                    if (strcmp(dest_inventory[j].model, car_model) == 0) {
                        dest_inventory[j].quantity++;
                        printf("%s transferred from source to destination branch.\n", car_model);
                        printf("New inventory for source branch:\n");
                        for (int k = 0; k < num_cars; k++) {
                            printf("%s, %d, $%.2f, %d\n", source_inventory[k].model, source_inventory[k].year,
                                source_inventory[k].price, source_inventory[k].quantity);
                        }
                        printf("New inventory for destination branch:\n");
                        for (int k = 0; k < dest_num_cars; k++) {
                            printf("%s, %d, $%.2f, %d\n", dest_inventory[k].model, dest_inventory[k].year
