//
//  main.c
//  171 - silver
//
//  Created by Chang on 2023-04-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
//#include<Windows.h>
#include <pthread.h>

#pragma warning( disable : 4996)

#define MIN_CARS 25 // Minimum number of cars in inventory
#define MAX_CARS 50 // Maximum number of cars in inventory

#define USD_CAD_RATE 1.3;
#define USD_MXN_RATE 18;

#define CAD_USD_RATE 0.75;
#define CAD_MXN_RATE 13.5;

#define MXN_USD_RATE 0.055;
#define MXN_CAD_RATE 0.075;

struct Engine {
    int cylinders;
    double displacement;
    int horsepower;
};


struct Chassis {
    int weight;
    int length;
    int width;
    int height;
};


struct Exterior {
    char Wheels_Rims[50];
    char Roof_racks;
};

struct Seating_Trim {
    int seats;
    char material[50];
};


struct Dimensions {
    int wheelbase;
    int groundClearance;
};


struct Fuel_Economy {
    double city;
    double highway;
};

typedef struct {
    int id;
    char brand[50];
    char model[50];
    char trim[50];
    char color[50];
    int year;
    char newUsed[10];
    char currency[10];
    double price;
    int quantity;
    char branch[50];

    int Mileage;
    char Transmission[50];
    struct Engine;
    struct Chassis;
    struct Exterior;
    struct Seating_Trim;
    struct Dimensions;
    char Airbags;
    int Airbags_Num;
    struct Fuel_Economy;
    char Hybird;
    char Fully_Electrified;
    char Automatic_Parking_Assistance;
    char Night_Vision_Assistance;
    char  Cruise_Control;
    int WD;
    char Hill_assist;
    char Tire_Pressure_Monitoring_System;
    char Voice_Command;
    char Lane_Change_Indicator;
    char Forward_Collision_Warning_Sensor;
    char Blind_spot_warning_sensors;
    int seat_heater;
    char Steering_heater;
}Car ;

typedef struct {
    char address[100];
    char postalCode[30];
    char phoneNumber[30];
    char faxNumber[30];
    char customerServiceEmail[100];
    char generalManagerName[30];
} BranchPublicInfo;

typedef struct {
    char phoneNumber[30];
    char cellPhoneNumber[30];
    char address[100];
    char email[100];
    char dateOfEmployment[30];
    int yearsOfExperience;
} GeneralManagerInfo;

typedef struct {
    char firstName[20];
    char lastName[20];
    char phoneNumber[30];
    char cellPhoneNumber[30];
    char address[100];
    char dateOfEmployment[30];
    int yearsOfExperience;
} FinanceManagerInfo;

typedef struct {
    GeneralManagerInfo generalManager;
    FinanceManagerInfo financeManager;
} BranchConfidentialInfo;



typedef struct {
    BranchPublicInfo publicInfo;
    BranchConfidentialInfo confidentialInfo;
} BranchInfo;

Car cars[MAX_CARS];

Car pendingcars[MAX_CARS];
int pendingNum=0;

int numCars = 0;

BranchInfo branches[5]; // Array to store BranchInfo objects
int numBranch = 0; // Number of branches

void displayCar(Car cars[], int i);
void history(Car cars[], int numCars);
void addSampleCar();
void printSampleCars(Car cars[],int i);
void price(Car cars[], int numCars);
void model(Car cars[], int numCars);
void brand(Car cars[], int numCars);
void newUsed(Car cars[], int numCars);
void mileage(Car cars[], int numCars);
void color(Car cars[], int numCars);
void location(Car cars[], int numCars);
void promotion(Car cars[], int numCars);
void buy(Car cars[], int numCars);
void addCar();
void sell(Car cars[], int numCars);
void customize();
void transfer();
void printBranchInfo(BranchInfo branch);


int main() {
    double choice;

    // Add sample cars to the inventory
    addSampleCar();

    while (1) {
        printf("\033[1;32m");
        printf("\t------------------------------------------------------------\n");
        printf("\t\tWelcome Silver Shen Dealership Inventory System\t\n");
        printf("\t------------------------------------------------------------\n");
        printf("\t\t1.Cars inventory(please choose 1.1 - 1.2)\n");
        printf("\t\t\t1.1 Current In Stock Inventory\n");
        printf("\t\t\t1.2 History\n");

        printf("\t\t2. Branches information (please choose 2.1 - 2.5)\n");
        printf("\t\t\t2.1 Vancouvber Branch\n");
        printf("\t\t\t2.2 Toronto Branch\n");
        printf("\t\t\t2.3 New York Branch\n");
        printf("\t\t\t2.4 Los Angeles Branch\n");
        printf("\t\t\t2.5 Mexico City Branch\n");

        printf("\t\t3.Search cars (please choose 3.1 - 3.7)\n");
        printf("\t\t\t3.1 By Model\n");
        printf("\t\t\t3.2 By Brand\n");
        printf("\t\t\t3.3 By New/Used/Both\n");
        printf("\t\t\t3.4 By Mileage\n");
        printf("\t\t\t3.5 By Price\n");
        printf("\t\t\t3.6 By Color\n");
        printf("\t\t\t3.7 By Location\n");

        printf("\t\t4. Promotion\n");

        printf("\t\t5. Update inventory (please choose 5.1 - 5.4)\n");
        printf("\t\t\t5.1 Sell cars\n");
        printf("\t\t\t   5.11 Customized pending order cars\n");
        printf("\t\t\t5.2 Buy cars\n");
        printf("\t\t\t5.3 Transfer cars\n");
        printf("\t\t\t5.4 Supply cars from dealership\n");
       
        printf("\t\t6. Exit\n");
        printf("\t-----------------------------------------------------------\n");
        printf("\033[1;0m");

        printf("\033\t[1;31m Please enter your choice: \033[1;0m");
        scanf("%lf", &choice);

        printf("\n");
        if (choice == 1.1) {

            displayCar(cars, numCars);

            int totalCars = 0;
            for (int i = 0; i < numCars; i++) {
                totalCars += cars[i].quantity;
            }
            printf("\033[1;33m -----Silver Shen Dealership Inventory total cars amount:°æ %d °ø-----\033[1;0m\n", totalCars);

            int choice1;
            printf("\033[1;31m Please enter the ID view the detail or enter 0 to exit: \033[1;0m");
            scanf("%d", &choice1);
            if (choice1 == 0) {
                return 0;
            }
            else {
                for (int i = 0; i < numCars; i++) {
                    if (choice1 == cars[i].id) {
                        printSampleCars(cars, i);
                    }
                }
            }

        }
        if (choice == 1.2) {

            history(cars, numCars);
           
            
        }

        if (choice == 2.1) {
            BranchInfo branch1 = {
              {
                "123 Main St",
                "V6B 1H6",
                "604-123-4567",
                "604-987-6543",
                "customerservice@vancouverbranch.com",
                "John Smith"
              },
              {
                {
                  "778-604-8877",
                  "778-999-4756",
                  "1125 Kingsway",
                  "JohnSmith@vancouverbranch.com",
                  "01/01/2020",
                  3
                },
                {
                  "Ben",
                  "Cook",
                  "778-787-0223",
                  "689-987-9988",
                  "6677 Gilley Ave",
                  "01/01/2018",
                  5
                }

              }
            };
            branches[numBranch++] = branch1;
            int sum = 0;
            for (int i = 0; i <numCars; i++) {
                if (strcmp(cars[i].branch, "Vancouver") == 0) {

                    sum += cars[i].quantity;
                    
                }
            }

            printf("\033[1;31m-----Vancouver Branch have %d cars in stock----- \033\n\n[1;0m",sum);
            printBranchInfo(branch1);
        }
        if (choice == 2.2) {
            BranchInfo branch2 = {
              {
                "456 Oak St",
                "V6G 2J7",
                "604-555-1212",
                "604-555-1234",
                "customerservice@torontobranch.com",
                "Jane Doe"
              },
              {
                {
                  "604-111-2222",
                  "778-333-4444",
                  "987 Granville St",
                  "JaneDoe@Torontobranch.com",
                  "02/15/2019",
                  3
                },
                {
                  "Tom",
                  "Lee",
                  "604-777-8888",
                  "604-999-0000",
                  "555 Seymour St",
                  "03/01/2017",
                  6
                }
              }
            };
            branches[numBranch++] = branch2;
            int sum = 0;
            for (int i = 0; i <numCars; i++) {
                if (strcmp(cars[i].branch, "Toronto") == 0) {

                    sum += cars[i].quantity;
                 
                  
                }
            }

            printf("\033[1;31m-----Toronto Branch have %d cars in stock----- \033\n\n[1;0m", sum);
         
            printBranchInfo(branch2);
        }
        if (choice == 2.3) {
            BranchInfo branch3 = {
              {
                "789 Broadway St",
                "25649",
                "604-555-5555",
                "604-555-6666",
                "customerservice@newyorkbranch.com",
                "Mike Brown"
              },
              {
                {
                  "604-444-7777",
                  "778-444-8888",
                  "555 West Broadway",
                  "MikeBrown@newyorkbranch.com",
                  "05/01/2018",
                  5
                },
                {
                  "Emily",
                  "Chen",
                  "778-111-2222",
                  "604-666-7777",
                  "1234 Robson St",
                  "06/01/2019",
                  2
                }
              }
            };
            branches[numBranch++] = branch3;
            int sum = 0;
            for (int i = 0; i < numCars; i++) {
                if (strcmp(cars[i].branch, "New York") == 0) {

                    sum += cars[i].quantity;
                }
            }

            printf("\033[1;31m-----New York Branch have %d cars in stock----- \033\n\n[1;0m", sum);
            printBranchInfo(branch3);
        }
        if (choice == 2.4) {

            BranchInfo branch4 = {
              {
                "321 Granville St",
                "V6C 1S4",
                "604-333-4444",
                "604-333-5555",
                "customerservice@LosAngelesbranch.com",
                "David Kim"
              },
              {
                {
                  "604-888-9999",
                  "778-888-0000",
                  "777 Hornby St",
                  "DavidKim@LosAngelesbranch.com",
                  "08/01/2017",
                  4
                },
                {
                  "Grace",
                  "Lee",
                  "778-777-6666",
                  "604-555-3333",
                  "4321 Cambie St",
                  "07/01/2016",
                  7
                }
              }
            };
            branches[numBranch++] = branch4;
            int sum = 0;
            for (int i = 0; i <numCars; i++) {
                if (strcmp(cars[i].branch, "Los Angeles") == 0) {

                    sum += cars[i].quantity;
                }
            }

            printf("\033[1;31m-----Los Angeles Branch have %d cars in stock----- \033\n\n[1;0m", sum);

            printBranchInfo(branch4);
        }
        if (choice == 2.5) {
            BranchInfo branch5 = {
              {
                "789 Main St",
                "V5T 3H7",
                "604-222-3333",
                "604-222-4444",
                "customerservice@MexicoCitybranch.com",
                "Chris Wong"
              },
              {
                {
                  "604-444-4444",
                  "778-222-2222",
                  "3456 Fraser St",
                  "ChrisWong@MexicoCitybranch.com",
                  "10/01/2015",
                  8
                },
                {
                  "Sophie",
                  "Liu",
                  "778-666-6666",
                  "604-777-7777",
                  "5678 Dunbar St",
                  "09/01/2018",
                  3
                }

              }
            };

            branches[numBranch++] = branch5;
            int sum = 0;
            for (int i = 0; i <numCars; i++) {
                if (strcmp(cars[i].branch, "Mexico City") == 0) {

                    sum += cars[i].quantity;
                }
            }

            printf("\033[1;31m-----Mexico City Branch have %d cars in stock----- \033\n\n[1;0m", sum);

            printBranchInfo(branch5);
        }
        if (choice == 3.1) {

            model(cars, numCars);
        }

        if (choice == 3.2) {

            brand(cars, numCars);
        }

        if (choice == 3.3) {

            newUsed(cars, numCars);
        }

        if (choice == 3.4) {

            mileage(cars, numCars);
        }

        if (choice == 3.5) {

            price(cars, numCars);
        }
        if (choice == 3.6) {

            color(cars, numCars);
        }
        if (choice == 3.7) {

            location(cars, numCars);
        }

        if (choice == 4) {

            promotion(cars, numCars);
        }

        if (choice == 5.1) {
            sell(cars, numCars);
        }

        if (choice == 5.11) {
            displayCar(pendingcars, pendingNum);
        }

        if (choice == 5.2) {
            buy(cars, numCars);
        }
        if (choice == 5.3) {
            transfer();
        }
        if (choice == 5.4) {
            buy(cars, numCars);
        }
      
        if (choice == 6) {
            return 0;
        }
    }

}



void displayCar(Car cars[], int i) {
    if (numCars == 0) {
        printf("No cars in inventory.\n");
//        return 0;
    }
    
    
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","ID", "Brand","Model","Trim","Color","Year","Condition","Currency","Price","Quantity","Branch");

    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < numCars; i++) {
        if (cars[i].quantity >0) {
            printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15s%-15s%-15.2f%-15d%-15s\n", cars[i].id, cars[i].brand, cars[i].model, cars[i].trim, cars[i].color, cars[i].year, cars[i].newUsed, cars[i].currency, cars[i].price, cars[i].quantity, cars[i].branch);

        }
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    
}

void history(Car cars[], int numCars) {
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n", "ID", "Brand", "Model", "Trim", "Color", "Year", "Condition", "Currency", "Price", "Quantity", "Branch");

    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < numCars; i++) {
        if (cars[i].quantity == 0) {
            printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15s%-15s%-15.2f%-15d%-15s\n", cars[i].id, cars[i].brand, cars[i].model, cars[i].trim, cars[i].color, cars[i].year, cars[i].newUsed, cars[i].currency, cars[i].price, cars[i].quantity, cars[i].branch);

        }
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void addSampleCar() {
    // Group 1: Toyota, Honda, Mazda, Nissan
    Car car1 = {1, "Toyota", "Camry", "LE", "Blue", 2022,"Used","USD", 25000.0, 1, "New York",
                10000, "Automatic", {4, 2.5, 203}, {3000, 4700, 1800, 1400},
                {"Alloy", 'Y'}, {5, "Leather"}, {2700, 170}, 'Y', 6,
                {28.5, 36.0}, 'N', 'N', 'Y', 'N', 'Y', 2, 'Y', 'Y', 'N', 'Y','Y','Y', 1, 'Y' };
    cars[numCars++] = car1;


    Car car2 = { 2,"Honda", "Civic", "EX", "Red", 2021,"Used", "CAD", 22000.0, 2, "Vancouver",
               8000, "CVT", {4, 1.8, 158}, {2500, 4600, 1700, 1300},
               {"Steel", 'N'}, {5, "Cloth"}, {2600, 160}, 'N', 4,
               {30.0, 38.0}, 'N', 'N', 'N', 'Y', 'Y', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car2;

    Car car3 = { 3,"Honda", "Accord", "LX", "White", 2023,"New", "CAD", 47000.0, 2, "Vancouver", 120, "Automatic", {5, 1.8, 158}, {2800, 5600, 1600, 1800},
               {"Steel", 'N'}, {5, "Cloth"}, {2600, 160}, 'N', 4,
               {32.0, 39.0}, 'N', 'N', 'N', 'Y', 'Y', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car3;

    Car car4 = { 4,"Nissan", "Altima", "SV", "Blue", 2022,"Used", "CAD", 23000.0, 2, "Toronto" , 5000, "Manual", {8, 5.0, 450}, {2700, 5100, 1500, 1400},
             {"Alloy", 'Y'}, {4, "Leather"}, {2500, 165}, 'N', 2,
             {18.0, 25.0}, 'N', 'N', 'N', 'Y', 'N', 2, 'N', 'N', 'N', 'Y', 'Y','Y',1, 'Y' };
    cars[numCars++] = car4;

    Car car5 = { 5,"Mazda", "Silverado", "LT", "Black", 2021,"Used", "CAD", 35000.0, 2, "Toronto", 25000, "Automatic", {8, 6.2, 420}, {2900, 5800, 1800, 1900},
                 {"Alloy", 'Y'}, {6, "Cloth"}, {2800, 170}, 'N', 4,
                 {16.0, 23.0}, 'N', 'Y', 'N', 'N', 'N', 2, 'N', 'N', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car5;

    Car car6 = { 6,"Honda", "Accord", "LX", "White", 2023,"New", "USD", 27000.0, 2, "New York" , 30000, "CVT", {4, 2.5, 182}, {2700, 5500, 1600, 1700},
             {"Alloy", 'N'}, {5, "Cloth"}, {2600, 160}, 'Y', 4,
             {27.0, 39.0}, 'Y', 'N', 'Y', 'N', 'Y', 2, 'Y', 'N', 'Y', 'Y', 'Y','Y',1, 'Y' };
    cars[numCars++] = car6;

    Car car7 = { 7,"Honda", "Accord", "LX-X", "White", 2020,"Used", "USD", 28000.0, 2, "Los Angeles" , 5000, "Automatic", {6, 3.0, 355}, {2600, 5200, 1600, 1500},
             {"Alloy", 'Y'}, {5, "Leather"}, {2500, 155}, 'Y', 4,
             {20.0, 27.0}, 'N', 'Y', 'N', 'N', 'N', 2, 'Y', 'N', 'N', 'N','Y','Y', 0, 'N' };
    cars[numCars++] = car7;

    Car car8 = { 8,"Honda", "Accord", "LX", "Black", 2019,"Used", "MXN", 380000.00, 2, "Mexico City", 10000, "Automatic", {6, 3.0, 335}, {2800, 5400, 1700, 1600},
                 {"Alloy", 'Y'}, {7, "Leather"}, {2700, 160}, 'Y', 4,
                 {19.0, 25.0}, 'Y', 'N', 'N', 'N', 'N', 2, 'N', 'Y', 'N', 'Y','Y', 'Y',1, 'Y' };
    cars[numCars++] = car8;

    Car car9 = { 9,"Mazda", "CX-3", "Touring-1", "White", 2020,"Used", "USD", 30000.0, 3, "Los Angeles", 2000, "Automatic", {4, 2.0, 255}, {2700, 5200, 1500, 1500},
                 {"Alloy", 'Y'}, {5, "Leather"}, {2600, 155}, 'Y', 4,
                 {22.0, 31.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'Y', 'N', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car9;




  

    // Group 2: Ford, Genesis, Volvo, Acura


    Car car10 = { 10,"Ford", "Mustang", "SS-1", "White", 2020, "Used","CAD", 35000.0, 2, "Vancouver", 12000, "Automatic", {6, 3.6, 310}, {2900, 5400, 1800, 1700},
                  {"Alloy", 'Y'}, {7, "Leather"}, {2800, 170}, 'Y', 4,
                  {18.0, 25.0}, 'N', 'Y', 'N', 'N', 'N', 2, 'N', 'N', 'Y', 'Y', 'Y','Y',2, 'Y' };
    cars[numCars++] = car10;

    Car car11 = { 11,"Ford", "Mustang", "SS", "White", 2020,"Used", "USD", 28000.0, 1, "New York", 3000, "Automatic", {4, 2.5, 203}, {2400, 4800, 1300, 1400},
              {"Alloy", 'Y'}, {5, "Cloth"}, {2300, 140}, 'N', 4,
              {28.0, 39.0}, 'N', 'Y', 'N', 'N', 'N', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car11;

    Car car12 = { 12,"Genesis", "G70", "2.0T", "Black", 2023, "New","MXN", 40000.0, 2, "Mexico City" , 150, "Manual", {8, 5.0, 450}, {3200, 6000, 2000, 1800},
                  {"Alloy", 'Y'}, {4, "Leather"}, {2500, 170}, 'Y', 4,
                  {15.0, 24.0}, 'Y', 'N', 'N', 'N', 'N', 2, 'Y', 'N', 'N', 'Y', 'Y','Y',1, 'Y' };
    cars[numCars++] = car12;

    Car car13 = { 13,"Volvo", "XC90", "T6 Inscription", "Silver", 2023,"New", "MXN", 70000.0, 2, "Mexico City", 600, "CVT", {4, 2.5, 188}, {2300, 4600, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Cloth"}, {2200, 130}, 'N', 4,
                  {27.0, 37.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'N', 'N', 'Y', 'N', 'Y','Y',1, 'Y' };
    cars[numCars++] = car13;

    Car car14 = { 14,"Volvo", "XC60", "T8", "Black", 2023, "New","USD", 80000.0, 2, "Los Angeles", 800, "Automatic", {8, 5.3, 355}, {3300, 6100, 2200, 2200},
                  {"Steel", 'N'}, {7, "Leather"}, {2800, 200}, 'Y', 4,
                  {16.0, 23.0}, 'Y', 'N', 'N', 'N', 'Y', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car14;

    Car car15 = { 15,"Acura", "TLX", "Technology", "Blue", 2022, "Used","USD", 45000.0, 1, "Los Angeles", 5000, "Automatic", {6, 2.5, 191}, {2500, 5000, 1600, 1500},
                  {"Alloy", 'Y'}, {6, "Leather"}, {2400, 150}, 'Y', 4,
                  {22.0, 28.0}, 'N', 'N', 'N', 'N', 'N', 2, 'N', 'Y', 'N', 'Y', 'Y','Y',1, 'Y' };
    cars[numCars++] = car15;



    // Group 3: BMW, Audi, Bentley, Ferrari, Aston Martin, Bugatti
  
    Car car16 = { 16,"BMW", "X5", "xDrive40i", "Black", 2020, "Used","CAD", 70000.0, 1, "Vancouver", 2000, "Automatic", {6, 3.0, 382}, {3200, 6000, 2000, 1800},
              {"Alloy", 'Y'}, {5, "Leather"}, {2800, 180}, 'Y', 4,
              {22.0, 30.0}, 'N', 'N', 'N', 'Y', 'N', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car16;

    Car car17 = { 17,"BMW", "X5", "xDrive40i", "White", 2023,"New", "CAD", 70000.0, 1, "Toronto", 300, "Automatic", {4, 2.0, 255}, {2300, 4600, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2200, 130}, 'N', 4,
                  {22.0, 29.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'N', 'N', 'Y', 'N', 'Y','Y',1, 'Y' };
    cars[numCars++] = car17;

    Car car18 = { 18,"BMW", "X3", "xi", "Black", 2022,"Used", "USD", 56000.0, 2, "New York" , 4000, "Automatic", {4, 2.0, 248}, {2400, 4800, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2300, 140}, 'N', 4,
                  {23.0, 28.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car18;

    Car car19 = { 19,"BMW", "X3", "xi", "Black", 2023, "New","MXN", 475000.0, 1, "Mexico City", 700, "Automatic", {6, 3.5, 295}, {3300, 6100, 2200, 2200},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2800, 200}, 'Y', 4,
                  {20.0, 27.0}, 'Y', 'N', 'N', 'N', 'Y', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car19;

    Car car20 = { 20,"Audi", "A4", "Premium", "Gray", 2019, "Used","CAD", 40000.0, 1, "Vancouver", 5000, "Automatic", {4, 2.4, 181}, {2500, 5000, 1600, 1500},
                  {"Alloy", 'Y'}, {5, "Cloth"}, {2400, 150}, 'N', 4,
                  {23.0, 30.0}, 'N', 'N', 'N', 'Y', 'N', 2, 'N', 'Y', 'N', 'N','Y', 'Y',0, 'N' };
    cars[numCars++] = car20;


    Car car21 = { 21,"Audi", "A4", "Premium", "Black", 2023, "Used","MXN", 470000.0, 1, "Mexico City", 1000, "Manual", {8, 5.0, 450}, {3600, 7000, 2400, 2500},
              {"Alloy", 'Y'}, {4, "Leather"}, {3000, 250}, 'Y', 2,
              {15.0, 24.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'Y', 'N', 'Y', 'N', 'Y','Y',1, 'Y' };
    cars[numCars++] = car21;

    Car car22 = { 22,"Bentley", "GT", "V8", "White", 2022,"Used", "USD", 200000.0, 1, "New York" , 8000, "Automatic", {4, 2.5, 203}, {2600, 4800, 1400, 1500},
                  {"Steel", 'N'}, {5, "Cloth"}, {2200, 160}, 'N', 4,
                  {28.0, 39.0}, 'N', 'N', 'Y', 'Y', 'N', 2, 'N', 'Y', 'N', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car22;

    Car car23 = { 23,"Bentley", "GT", "V8", "Black", 2023, "New","USD", 250000.0, 1,"Los Angeles", 600, "Automatic", {4, 2.5, 188}, {2400, 4600, 1300, 1400},
                  {"Steel", 'N'}, {5, "Cloth"}, {2100, 140}, 'N', 4,
                  {27.0, 37.0}, 'N', 'Y', 'Y', 'N', 'N', 2, 'N', 'N', 'Y', 'N', 'Y','Y',1, 'Y' };
    cars[numCars++] = car23;

    Car car24 = { 24,"Ferrari", "488 GTB", "Spider", "Red", 2018,"Used", "USD", 300000.0, 1, "New York" , 3000, "Automatic", {4, 2.4, 181}, {2400, 4800, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2200, 130}, 'N', 4,
                  {22.0, 28.0}, 'N', 'Y', 'N', 'Y', 'N', 2, 'N', 'N', 'Y', 'N', 'Y','Y',0, 'N' };
    cars[numCars++] = car24;

    Car car25 = { 25,"Aston Martin", "DB11", "V12", "Blue", 2020,"Used", "USD", 250000.0, 1, "Los Angeles", 5000, "Automatic", {4, 2.5, 187}, {2400, 4700, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2200, 130}, 'N', 4,
                  {25.0, 31.0}, 'N', 'N', 'N', 'Y', 'N', 2, 'N', 'Y', 'N', 'Y','N','Y', 0, 'N' };
    cars[numCars++] = car25;

    Car car26 = { 26,"Bugatti", "Chiron", "Sport", "Black", 2022,"Used","CAD",60000.0,1,"Vancouver", 6000, "Automatic", {4, 2.7, 187}, {2400, 4700, 1300, 1400},
                  {"Alloy", 'Y'}, {5, "Leather"}, {2200, 130}, 'N', 4,
                  {25.0, 31.0}, 'N', 'N', 'N', 'Y', 'N', 2, 'N', 'Y', 'N', 'N','Y','Y', 0, 'N' };
    cars[numCars++] = car26;
    
   
}

void printSampleCars(Car cars[],int i) {
    
    
        printf("\033[1;36m°æCar %d°ø\033[1;0m\n", cars[i].id);
        printf("Brand: %s\n", cars[i].brand);
        printf("Model: %s\n", cars[i].model);
        printf("Trim: %s\n", cars[i].trim);
        printf("Color: %s\n", cars[i].color);
        printf("Year: %d\n", cars[i].year);
        printf("Condition: %s\n", cars[i].newUsed);
        printf("Currency: %s\n", cars[i].currency);
        printf("Price: %.2f\n", cars[i].price);
        printf("Quantity: %d\n", cars[i].quantity);
        printf("Branch: %s\n", cars[i].branch);
        printf("Mileage: %d\n", cars[i].Mileage);
        printf("Transmission: %s\n", cars[i].Transmission);
        printf("Engine Cylinders: %d\n", cars[i].cylinders);
        printf("Engine Displacement: %.2f\n", cars[i].displacement);
        printf("Engine Horsepower: %d\n", cars[i].horsepower);
        printf("Chassis Weight: %d\n", cars[i].weight);
        printf("Chassis Length: %d\n", cars[i].length);
        printf("Chassis Width: %d\n", cars[i].width);
        printf("Chassis Height: %d\n", cars[i].height);
        printf("Exterior Wheels/Rims: %s\n", cars[i].Wheels_Rims);
        printf("Exterior Roof Racks: %c\n", cars[i].Roof_racks);
        printf("Seating Trim Seats: %d\n", cars[i].seats);
        printf("Seating Trim Material: %s\n", cars[i].material);
        printf("Dimensions Wheelbase: %d\n", cars[i].wheelbase);
        printf("Dimensions Ground Clearance: %d\n", cars[i].groundClearance);
        printf("Airbags: %c\n", cars[i].Airbags);
        printf("Airbags Number: %d\n", cars[i].Airbags_Num);
        printf("Fuel Economy City: %.2f\n", cars[i].city);
        printf("Fuel Economy Highway: %.2f\n", cars[i].highway);
        printf("Hybrid: %c\n", cars[i].Hybird);
        printf("Fully Electrified: %c\n", cars[i].Fully_Electrified);
        printf("Automatic Parking Assistance: %c\n", cars[i].Automatic_Parking_Assistance);
        printf("Night Vision Assistance: %c\n", cars[i].Night_Vision_Assistance);
        printf("Cruise Control: %c\n", cars[i].Cruise_Control);
        printf("WD: %d\n", cars[i].WD);
        printf("Hill Assist: %c\n", cars[i].Hill_assist);
        printf("Tire Pressure Monitoring System: %c\n", cars[i].Tire_Pressure_Monitoring_System);
        printf("Voice Command: %c\n", cars[i].Voice_Command);
        printf("Lane Change Indicator: %c\n", cars[i].Lane_Change_Indicator);
        printf("Forward Collision Warning Sensor: %c\n", cars[i].Forward_Collision_Warning_Sensor);
        printf("Blind Spot Warning Sensors: %c\n", cars[i].Blind_spot_warning_sensors);
        printf("seat heater: %d\n", cars[i].seat_heater);
        printf("Steering heater: %c\n", cars[i].Steering_heater);

       
        printf("-------------------------------------------------------------------------------------\n");
    
}

void printBranchInfo(BranchInfo branch) {

    printf("\033[1;34mBranch Public Info:\033[1;0m\n");
    printf("Address: %s\n", branch.publicInfo.address);
    printf("Postal Code: %s\n", branch.publicInfo.postalCode);
    printf("Phone Number: %s\n", branch.publicInfo.phoneNumber);
    printf("Fax Number: %s\n", branch.publicInfo.faxNumber);
    printf("Customer Service Email: %s\n", branch.publicInfo.customerServiceEmail);
    printf("\n");

    printf("\033[1;34mGeneral Manager Info:\033[1;0m\n");
    printf("General Manager Name: %s\n", branch.publicInfo.generalManagerName);
    printf("Phone Number: %s\n", branch.confidentialInfo.generalManager.phoneNumber);
    printf("Cell Phone Number: %s\n", branch.confidentialInfo.generalManager.cellPhoneNumber);
    printf("Address: %s\n", branch.confidentialInfo.generalManager.address);
    printf("Email: %s\n", branch.confidentialInfo.generalManager.email);
    printf("Date of Employment: %s\n", branch.confidentialInfo.generalManager.dateOfEmployment);
    printf("Years of Experience: %d\n", branch.confidentialInfo.generalManager.yearsOfExperience);
    printf("\n");

    printf("\033[1;34mFinance Manager Info:\033[1;0m\n");
    printf("First Name: %s\n", branch.confidentialInfo.financeManager.firstName);
    printf("Last Name: %s\n", branch.confidentialInfo.financeManager.lastName);
    printf("Phone Number: %s\n", branch.confidentialInfo.financeManager.phoneNumber);
    printf("Cell Phone Number: %s\n", branch.confidentialInfo.financeManager.cellPhoneNumber);
    printf("Address: %s\n", branch.confidentialInfo.financeManager.address);
    printf("Date of Employment: %s\n", branch.confidentialInfo.financeManager.dateOfEmployment);
    printf("Years of Experience: %d\n", branch.confidentialInfo.financeManager.yearsOfExperience);

}

//search functions

void model(Car cars[], int numCars) {

    char input[50];

    printf("\033[1;31mPlease enter the model: \033[1;0m");
    scanf("%s", input);

    int found = 0;

    for (int i = 0; i < numCars; i++) {
        if (strcmp(input, cars[i].model) == 0) {
            printSampleCars(cars, i);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found within the specified model.\n");
    }
}

void brand(Car cars[], int numCars) {

    char input[50];

    printf("\033[1;31mPlease enter the brand (firts letter is uppercase): \033[1;0m");
    scanf("%s", input);

    int found = 0; // flag to track if any cars are found within the price range

    for (int i = 0; i < numCars; i++) {
        if (strcmp(input, cars[i].brand) == 0) {
            printSampleCars(cars, i);
            found = 1; // Set found flag to 1 when a car with the specified model is found
        }
    }

    if (!found) {
        printf("No cars found within the specified brand.\n");
    }
}

void newUsed(Car cars[], int numCars) {
    char input[50];
    printf("Please enter your search (firts letter is uppercase): \n");
    printf("New\n");
    printf("Used\n");
    printf("Both\n");
    printf("\033[1;31mPlease enter the your choice: \033[1;0m");
    scanf("%s", input);

        for (int i = 0; i < numCars; i++) {
            if (strcmp(input, cars[i].newUsed) == 0) {
                printSampleCars(cars, i);
              
            }

        }

     if (strcmp(input, "Both") == 0) {

        for (int i = 0; i < numCars; i++) {

            printSampleCars(cars, i);
         
        }
    }

   
}

void mileage(Car cars[], int numCars) {
    double minMile;
    double maxMile;
    double  input;
    
    printf("Please enter the minimum mileage: ");
    scanf("%lf", &minMile);

    printf("Please enter the maximum mileage: ");
    scanf("%lf", &maxMile);

    printf("Cars within the price range of %.2lf to %.2lf:\n", minMile, maxMile);
    printf("------------------------------------------------------------\n");

    int found = 0; // flag to track if any cars are found within the price range
    

        for (int i = 0; i < numCars; i++) {
            if (cars[i].Mileage >= minMile && cars[i].Mileage <= maxMile) {

                printSampleCars(cars, i);
                found = 1;
            }

        }
    


    if (!found) {
        printf("No cars found within the specified mileage range.\n");
    }
}


void price(Car cars[], int numCars) {
    double minPrice;
    double maxPrice;
    char input[5];
    printf("Please choose the currency: \n");
    printf("Canada: CAD\n");
    printf("United States: USD\n");
    printf("Mexico: MXN\n");
    printf("\033[1;31mPlease enter the currency: \033[1;0m");
    scanf("%s", input);

    printf("Please enter the minimum price: ");
    scanf("%lf", &minPrice);

    printf("Please enter the maximum price: ");
    scanf("%lf", &maxPrice);

    printf("Cars within the price range of %.2lf to %.2lf:\n", minPrice, maxPrice);
    printf("------------------------------------------------------------\n");

    int found = 0; // flag to track if any cars are found within the price range
   

        for (int i = 0; i < numCars; i++) {
            if (strcmp(input, cars[i].currency) == 0 && cars[i].price >= minPrice && cars[i].price <= maxPrice) {

                printSampleCars(cars, i);
                found = 1;
            }

        }
    
  
   
    if (!found) {
        printf("No cars found within the specified currency and price range.\n");
    }
}

void color(Car cars[], int numCars) {

    char input[50];

    printf("\033[1;31mPlease enter the color (firts letter is uppercase): \033[1;0m");
    scanf("%s", input);

    int found = 0;

    for (int i = 0; i < numCars; i++) {
        if (strcmp(input, cars[i].color) == 0) {
            printSampleCars(cars, i);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found within the specified color.\n");
    }
}

void location(Car cars[], int numCars) {

    char input[20];
    printf("\033[1;31m5 location in our dealership: \033[1;0m\n");
    printf("Vancouver\n");
    printf("Toronto\n");
    printf("New York\n");
    printf("Los Angeles\n");
    printf("Mexico City\n");
    printf("\n");
    printf("\033[1;31mPlease enter the location (firts letter is uppercase): \033[1;0m");
    scanf("%s", input);

    int found = 0;

    for (int i = 0; i < numCars; i++) {
        if (strcmp(input, cars[i].branch) == 0) {
            printSampleCars(cars, i);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found within the specified color.\n");
    }
}

void promotion(Car cars[], int numCars) {

    char input[5];
    printf("Please choose the country: \n");
    printf("Canada: CAD\n");
    printf("United States: USD\n");
    printf("Mexico: MXN\n");
    printf("\033[1;31mPlease enter the country code: \033[1;0m");
    scanf("%s", input);

    for (int i = 0; i < numCars; i++) {

        if (strcmp(input, cars[i].currency) == 0) {
            if (strcmp(cars[i].currency, "CAD") == 0 && strcmp(cars[i].brand, "Honda") == 0 && strcmp(cars[i].newUsed, "New") == 0) {

                printf("\033[1;36mAll brand-new Honda in Canada has a 2%%  rebate as a credit : \033[1; 0m\n");
                printf("\033[1;36m ---2%% rebate credit: %.2f---\033[1;0m\n", (cars[i].price) * 0.02);
                printSampleCars(cars, i);
            }

            if (strcmp(cars[i].currency, "MXN") == 0 && strcmp(cars[i].brand, "Volvo") == 0 && strcmp(cars[i].newUsed, "New") == 0) {

                printf("\033[1;36mAll brand-new Volvo above 60,000 in Mexico have a 3%% rebate as credit : \033[1; 0m\n");
                printf("\033[1;36m ---3%% rebate credit: %.2f---\033[1;0m\n", (cars[i].price) * 0.03);
                printSampleCars(cars, i);
            }

            if (strcmp(cars[i].currency, "USD") == 0 && (strcmp(cars[i].brand, "BMW") == 0 || strcmp(cars[i].brand, "Volvo") == 0 || strcmp(cars[i].brand, "Audi") == 0 || strcmp(cars[i].brand, "Bentley") == 0 || strcmp(cars[i].brand, "Ferrari") == 0)) {

                printf("\033[1;36m In the USA, there is a loyalty program for BMW, VOLVO, AUDI, BENTLEY, and Ferrari - If the customer is eligible for the loyalty program then a 2.5%% promotion will be implemented to customer's purchase: \033[1; 0m\n");
                printf("\033[1;36m ---Previous Price:  %.2f . 2.5%% promotion, Current Price: %.2f---\033[1;0m\n", cars[i].price, cars[i].price - (cars[i].price) * 0.025);
                printSampleCars(cars, i);
            }
        }

    }



}

void addCar() {
    Car Car;

    
    printf("Enter car details:\n");
    printf("ID: ");
    scanf("%d", &Car.id);
    printf("Brand: ");
    scanf("%s", Car.brand);
    printf("Model: ");
    scanf("%s", Car.model);
    printf("Trim: ");
    scanf("%s", Car.trim);
    printf("Color: ");
    scanf("%s", Car.color);
    printf("Year: ");
    scanf("%d", &Car.year);
    printf("New/Used: ");
    scanf("%s", Car.newUsed);
    printf("Currency: ");
    scanf("%s", Car.currency);
    printf("Buy Price(not show to customers): ");
    scanf("%lf", &Car.price);
    printf("Sale Price: ");
    scanf("%lf", &Car.price);
    printf("Quantity: ");
    scanf("%d", &Car.quantity);
    printf("Branch: ");
    scanf("%s", Car.branch);
    /*printf("Mileage: ");
    scanf("%d", &Car.Mileage);
    printf("Transmission: ");
    scanf("%s", Car.Transmission);
    printf("Number of Cylinders: ");
    scanf("%d", &Car.cylinders);
    printf("Displacement: ");
    scanf("%lf", &Car.displacement);
    printf("Horsepower: ");
    scanf("%d", &Car.horsepower);
    printf("Weight: ");
    scanf("%d", &Car.weight);
    printf("Length: ");
    scanf("%d", &Car.length);
    printf("Width: ");
    scanf("%d", &Car.width);
    printf("Height: ");
    scanf("%d", &Car.height);
    printf("Wheels and Rims: ");
    scanf("%s", Car.Wheels_Rims);
    printf("Roof Racks (Y/N): ");
    scanf(" %c", &Car.Roof_racks);
    printf("Number of Seats: ");
    scanf("%d", &Car.seats);
    printf("Material of Seats: ");
    scanf("%s", Car.material);
    printf("Wheelbase: ");
    scanf("%d", &Car.wheelbase);
    printf("Ground Clearance: ");
    scanf("%d", &Car.groundClearance);
    printf("Airbags (Y/N): ");
    scanf(" %c", &Car.Airbags);
    printf("Number of Airbags: ");
    scanf("%d", &Car.Airbags_Num);
    printf("City Fuel Economy: ");
    scanf("%lf", &Car.city);
    printf("Highway Fuel Economy: ");
    scanf("%lf", &Car.highway);
    printf("Hybrid (Y/N): ");
    scanf(" %c", &Car.Hybird);
    printf("Fully Electrified (Y/N): ");
    scanf(" %c", &Car.Fully_Electrified);
    printf("Automatic Parking Assistance (Y/N): ");
    scanf(" %c", &Car.Automatic_Parking_Assistance);
    printf("Night Vision Assistance (Y/N): ");
    scanf(" %c", &Car.Night_Vision_Assistance);
    printf("Cruise Control (Y/N): ");
    scanf(" %c", &Car.Cruise_Control);
    printf("WD: ");
    scanf("%d", &Car.WD);
    printf("Hill Assist (Y/N): ");
    scanf(" %c", &Car.Hill_assist);
    printf("Tire Pressure Monitoring System (Y/N): ");
    scanf(" %c", &Car.Tire_Pressure_Monitoring_System);
    printf("Voice Command (Y/N): ");
    scanf(" %c", &Car.Voice_Command);
    printf("Lane Change Indicator (Y/N): ");
    scanf(" %c", &Car.Lane_Change_Indicator);
    printf("Forward Collision Warning Sensor (Y/N): ");
    scanf(" %c", &Car.Forward_Collision_Warning_Sensor);
    printf("Blind Spot Warning Sensors (Y/N): ");
    scanf(" %c", &Car.Blind_spot_warning_sensors);
    printf("Seat Heater (0/1): ");
    scanf("%d", &Car.seat_heater);
    printf("Steering Heater (Y/N): ");
    scanf(" %c", &Car.Steering_heater);*/

    
         
        cars[numCars++] = Car;
        printf("Car added successfully!\n");
    
    
}


void buy(Car cars[], int numCars){

    char input[2];
    int input1;
    int input2;

    printf("Is the new buy car already have in inventory (confirm the brand,model,trim and branch)? (Y/N)\n");
    scanf("%s", input);

    if (strcmp(input, "Y") == 0) {
        printf("please enter the id:\n");
        scanf("%d", &input1);
        for (int i = 0; i < numCars; i++) {
            if (cars[i].id == input1)
            {
                printf("please enter the quantities:\n");
                scanf("%d", &input2);
                cars[i].quantity += input2;
            }
        }
    }

    else if (strcmp(input, "N") == 0) {

        addCar();

    }

    
}

void sell(Car cars[], int numCars) {

    char input[2];
    int input1;
    int input2;

    printf("Is the sell car already have in inventory (confirm the brand,model,trim and branch)? (Y/N)\n");
    scanf("%s", input);

    if (strcmp(input, "Y") == 0) {
        printf("please enter the id:\n");
        scanf("%d", &input1);
        for (int i = 0; i < numCars; i++) {
            if (cars[i].id == input1)
            {
                printf("please enter the quantities:\n");
                scanf("%d", &input2);
                cars[i].quantity -= input2;
            }
        }
    }

    else if (strcmp(input, "N") == 0) {

        printf("please enter the customize request:\n");
      
        customize();
    }


}

void customize() {
    Car Car;


    printf("\033[1;31mEnter customize car details:\033[1;0m\n");
    printf("ID: ");
    scanf("%d", &Car.id);
    printf("Brand: ");
    scanf("%s", Car.brand);
    printf("Model: ");
    scanf("%s", Car.model);
    printf("Trim: ");
    scanf("%s", Car.trim);
    printf("Color: ");
    scanf("%s", Car.color);
    printf("Year: ");
    scanf("%d", &Car.year);
    printf("New/Used: ");
    scanf("%s", Car.newUsed);
    printf("Currency: ");
    scanf("%s", Car.currency);
    printf("Price: ");
    scanf("%lf", &Car.price);
    printf("Quantity: ");
    scanf("%d", &Car.quantity);
    printf("Branch: ");
    scanf("%s", Car.branch);
    //printf("Mileage: ");
    //scanf("%d", &Car.Mileage);
    //printf("Transmission: ");
    //scanf("%s", Car.Transmission);
    //printf("Number of Cylinders: ");
    //scanf("%d", &Car.cylinders);
    //printf("Displacement: ");
    //scanf("%lf", &Car.displacement);
    //printf("Horsepower: ");
    //scanf("%d", &Car.horsepower);
    //printf("Weight: ");
    //scanf("%d", &Car.weight);
    //printf("Length: ");
    //scanf("%d", &Car.length);
    //printf("Width: ");
    //scanf("%d", &Car.width);
    //printf("Height: ");
    //scanf("%d", &Car.height);
    //printf("Wheels and Rims: ");
    //scanf("%s", Car.Wheels_Rims);
    //printf("Roof Racks (Y/N): ");
    //scanf(" %c", &Car.Roof_racks);
    //printf("Number of Seats: ");
    //scanf("%d", &Car.seats);
    //printf("Material of Seats: ");
    //scanf("%s", Car.material);
    //printf("Wheelbase: ");
    //scanf("%d", &Car.wheelbase);
    //printf("Ground Clearance: ");
    //scanf("%d", &Car.groundClearance);
    //printf("Airbags (Y/N): ");
    //scanf(" %c", &Car.Airbags);
    //printf("Number of Airbags: ");
    //scanf("%d", &Car.Airbags_Num);
    //printf("City Fuel Economy: ");
    //scanf("%lf", &Car.city);
    //printf("Highway Fuel Economy: ");
    //scanf("%lf", &Car.highway);
    //printf("Hybrid (Y/N): ");
    //scanf(" %c", &Car.Hybird);
    //printf("Fully Electrified (Y/N): ");
    //scanf(" %c", &Car.Fully_Electrified);
    //printf("Automatic Parking Assistance (Y/N): ");
    //scanf(" %c", &Car.Automatic_Parking_Assistance);
    //printf("Night Vision Assistance (Y/N): ");
    //scanf(" %c", &Car.Night_Vision_Assistance);
    //printf("Cruise Control (Y/N): ");
    //scanf(" %c", &Car.Cruise_Control);
    //printf("WD: ");
    //scanf("%d", &Car.WD);
    //printf("Hill Assist (Y/N): ");
    //scanf(" %c", &Car.Hill_assist);
    //printf("Tire Pressure Monitoring System (Y/N): ");
    //scanf(" %c", &Car.Tire_Pressure_Monitoring_System);
    //printf("Voice Command (Y/N): ");
    //scanf(" %c", &Car.Voice_Command);
    //printf("Lane Change Indicator (Y/N): ");
    //scanf(" %c", &Car.Lane_Change_Indicator);
    //printf("Forward Collision Warning Sensor (Y/N): ");
    //scanf(" %c", &Car.Forward_Collision_Warning_Sensor);
    //printf("Blind Spot Warning Sensors (Y/N): ");
    //scanf(" %c", &Car.Blind_spot_warning_sensors);
    //printf("Seat Heater (0/1): ");
    //scanf("%d", &Car.seat_heater);
    //printf("Steering Heater (Y/N): ");
    //scanf(" %c", &Car.Steering_heater);

    pendingcars[pendingNum++] = Car;

    //printf("\033[1;31mPending order detail:\033[1;0m\n");

    //for (int i = 0; i < pendingNum; i++) {
    //    printSampleCars(pendingcars, i);
    //}
}

 
           
void transfer() {
    int carId;
    int num;
    int input;
    int current;

    printf("\033[1;31m5 locations in our dealership: \033[1;0m\n");
    printf("1. Vancouver\n");
    printf("2. Toronto\n");
    printf("3. New York\n");
    printf("4. Los Angeles\n");
    printf("5. Mexico City\n");

    printf("\n");
    printf("Please enter the ID of the car to transfer: ");
    scanf("%d", &carId);

    // Check if the entered car ID is valid
    if (carId < 1 || carId > numCars) {
        printf("Invalid car ID. Exiting...\n");
        return;
    }

    printf("How many cars to transfer? ");
    scanf("%d", &num);

    // Check if the entered quantity is valid
    if (num <= 0 || num > cars[carId - 1].quantity) {
        printf("Invalid quantity. Exiting...\n");
        return;
    }
    printf("Please enter the current location (1-5) : ");
    scanf("%d", &current);

    printf("Please enter the transfer location (1-5) : ");
    scanf("%d", &input);

    if (input < 1 || input > 5) {
        printf("Invalid location. Exiting...\n");
        return;
    }

    // Update the car information
    Car transCar = cars[carId - 1];
    cars[carId - 1].quantity = cars[carId - 1].quantity - num;
    transCar.quantity = num;
    if (current == 1) {
        switch (input) {
        case 1:
            printf("transfer to the same city,please enter again");

            break;
        case 2:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Toronto");
            break;
        case 3:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "New York");
            strcpy(transCar.currency, "USD");
            transCar.price *= CAD_USD_RATE;
            break;
        case 4:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Los Angeles");
            strcpy(transCar.currency, "USD");
            transCar.price *= CAD_USD_RATE;
            break;
        case 5:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Mexico City");
            strcpy(transCar.currency, "MXN");
            transCar.price *= CAD_MXN_RATE;
            break;
        default:

            break;
        }
    }

    if (current == 2) {
        switch (input) {
        case 1:

            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Vancouver");

            break;
        case 2:
            printf("transfer to the same city,please enter again");

            break;
        case 3:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "New York");
            strcpy(transCar.currency, "USD");
            transCar.price *= CAD_USD_RATE;
            break;
        case 4:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Los Angeles");
            strcpy(transCar.currency, "USD");
            transCar.price *= CAD_USD_RATE;
            break;
        case 5:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Mexico City");
            strcpy(transCar.currency, "MXN");
            transCar.price *= CAD_MXN_RATE;
            break;
        default:

            break;
        }
    }

    if (current == 3) {
        switch (input) {
        case 1:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Vancouver");
            strcpy(transCar.currency, "CAD");
            transCar.price *= USD_CAD_RATE;
            break;
        case 2:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Toronto");
            strcpy(transCar.currency, "CAD");
            transCar.price *= USD_CAD_RATE;
            break;
        case 3:
            printf("transfer to the same city,please enter again");

            break;
        case 4:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Los Angeles");
            break;
        case 5:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Mexico City");
            strcpy(transCar.currency, "MXN");
            transCar.price *= USD_MXN_RATE;
            break;
        default:

            break;
        }
    }

    if (current == 4) {
        switch (input) {
        case 1:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Vancouver");
            strcpy(transCar.currency, "CAD");
            transCar.price *= USD_CAD_RATE;
            break;
        case 2:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Toronto");
            strcpy(transCar.currency, "CAD");
            transCar.price *= USD_CAD_RATE;
            break;
        case 3:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "New York");

            break;
        case 4:
            printf("transfer to the same city,please enter again");

            break;
        case 5:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Mexico City");
            strcpy(transCar.currency, "MXN");
            transCar.price *= USD_MXN_RATE;
            break;
        default:

            break;
        }
    }

    if (current == 5) {
        switch (input) {
        case 1:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Vancouver");
            strcpy(transCar.currency, "CAD");
            transCar.price *= MXN_CAD_RATE;
            break;
        case 2:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Toronto");
            strcpy(transCar.currency, "CAD");
            transCar.price *= MXN_CAD_RATE;
            break;
        case 3:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "New York");
            strcpy(transCar.currency, "USD");
            transCar.price *= MXN_USD_RATE;
            break;
        case 4:
            transCar.id = numCars + 1;
            strcpy(transCar.branch, "Los Angeles");
            strcpy(transCar.currency, "USD");
            transCar.price *= MXN_USD_RATE;
            break;
        case 5:
            printf("transfer to the same city,please enter again");

            break;

        default:

            break;
        }
    }

    // Update the cars array
    cars[numCars++] = transCar;
}











    

