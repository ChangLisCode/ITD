//
//  main.c
//  171
//
//  Created by Chang on 2023-04-12.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BRANDS 6

//struct define

struct BranchConfidentialInfo {
  char gmPhoneNumber[20];
  char gmCellPhoneNumber[20];
  char gmAddress[100];
  char gmEmail[100];
  char gmDateOfEmployment[20];
  int gmYearsOfExperience;

  char fmFirstName[50];
  char fmLastName[50];
  char fmPhoneNumber[20];
  char fmCellPhoneNumber[20];
  char fmAddress[100];
  char fmDateOfEmployment[20];
  int fmYearsOfExperience;
};

struct BranchBasicInfo {
    char country[30];
    char currency[30];
    char address[100];
    char postalCode[10];
    char phoneNumber[20];
    char faxNumber[20];
    char customerServiceEmail[50];
    char generalManagerName[50];
};

struct Car {
    char make[20];
    char category[20];
    char model[50];
    char manufacturer[50];
    char color[20];
    int mileage;
    
    int numAvailableCars;
    float MSRP;
    
//    trim defination
    bool isAutomaticTransmission;
    struct Engine {
        int cylinders;
        double horsepower;
        double torque;
        double displacement;
        char fuelType[20];
    } engine;
    struct Chassis {
        double wheelbase;
        double length;
        double width;
        double height;
        int numberOfDoors;
    } chassis;
    struct Exterior {
        char bodyStyle[20];
        char headlights[20];
        char taillights[20];
        char grille[20];
        char wheels[20];
    } exterior;
    struct SeatingTrim {
        int numberOfSeats;
        char material[20];
        char color[20];
    } seatingTrim;
    struct Dimensions {
        double cargoVolume;
        double passengerVolume;
        double maxCargoVolume;
    } dimensions;
    bool hasAirbags;
    int numberOfAirbags;
    struct Fuel {
        double cityMPG;
        double highwayMPG;
        double combinedMPG;
        double tankCapacity;
    } fuelEconomy;
    bool isHybrid;
    bool isFullyElectrified;
    bool hasAutomaticParkingAssistance;
    bool hasNightVisionAssistance;
    bool hasCruiseControl;
    bool isFourWheelDrive;
    bool hasHillAssist;
    bool hasTirePressureMonitoringSystem;
    bool hasVoiceCommand;
    bool hasLaneChangeIndicator;
    bool hasForwardCollisionWarningSensor;
    bool hasBlindSpotWarningSensors;
    int numberOfSeatHeaters;
    bool hasSteeringHeater;
    
    bool loyaltyProgram;
};

struct Dealership_inventory{
    struct Car cars;
    int num;
    float final_price;
};

struct Dealership {
    struct BranchBasicInfo branchInfo;
    struct BranchConfidentialInfo branchContact;
    struct Car cars;
    struct Dealership_inventory inventory;
};

struct searchItem{
    char make[20];
    char manufacture[20];
    bool new;
    bool bothOfNewUsed;
    float MSRP_MAX;
    float MSRP_MIN;
    int mileageMax;
    int mileageMin;
    char color[10];
    int availability;
    char country[30];
};

//  function define

void sell_car(struct Dealership branches,int *num_cars, char* car_model);
void buy_car(struct Dealership branches, int* num_cars, char* car_model);
void transfer_car(int branchesOut, int branchesIn, int* num_cars, char* car_model, double transfer_expenses);

void searchInventory(struct Dealership item, struct searchItem item2);

float calculate_rebate_or_promotion(char *make, float price, char *country);

double final_price(struct Dealership branches, char currency, float MSRP, int rate_type);



int main() {
    
//    inventory iniaalization
    
//    branch info.

    struct BranchBasicInfo branch1 = {"Canada", "CAD", "123 Main St", "A1B 2C3", "555-1234", "555-5678", "customerservice@branch1.com", "John Smith"};
    struct BranchBasicInfo branch2 = {"Canada","CAD","456 1st Ave", "X1Y 2Z3", "555-4321", "555-8765", "customerservice@branch2.com", "Jane Doe"};
    struct BranchBasicInfo branch3 = {"Canada","CAD","789 Oak Rd", "M4N 5P6", "555-5678", "555-4321", "customerservice@branch3.com", "Bob Johnson"};
    struct BranchBasicInfo branch4 = {"USA","USD","321 Pine St", "L7M 8N9", "555-8765", "555-1234", "customerservice@branch4.com", "Alice Williams"};
    struct BranchBasicInfo branch5 = {"Mexico", "MXN", "654 Elm Blvd", "T2T 3S4", "555-2468", "555-1357", "customerservice@branch5.com", "David Lee"};
    
    struct BranchConfidentialInfo ConfidentialInfo_branch1 = {"123-456-7890","987-654-3210","123 Main St","gm@example.com","01/01/2000",10,"John","Doe","555-555-1234","555-555-5678","456 Elm St","02/01/2005",5};
    struct BranchConfidentialInfo ConfidentialInfo_branch2 = {"111-222-3333", "444-555-6666","456 Main St","gm2@example.com","03/01/2001",15,"Jane","Smith","555-555-7890","555-555-2345","789 Oak St","04/01/2006",6};
    struct BranchConfidentialInfo ConfidentialInfo_branch3 = {"222-333-4444","777-888-9999","789 Main St","gm3@example.com","05/01/2002",12,"Bob","Johnson","555-555-2345","555-555-8901","123 Maple St","06/01/2007",7};
    struct BranchConfidentialInfo ConfidentialInfo_branch4 = {"444-555-6666","111-222-3333","890 Main St","gm4@example.com","07/01/2003",14,"Sarah","Williams",
    "555-555-3456","555-555-7890","345 Pine St","08/01/2008",8};
    struct BranchConfidentialInfo ConfidentialInfo_branch5 = {"555-666-7777","222-333-4444","901 Main St","gm5@example.com","09/01/2004",
    13,"Tom","Lee","555-555-9012","555-555-3456","678 Birch St","10/01/2009",9};
    
//    car info.
//    group1
    struct Car Kia1 = {"Kia", "Sedan", "Optima", "Kia Motors", "White", 0, 10, 25000.0, true, {4, 180.0, 170.0, 2.4, "Gasoline"}, {110.4, 191.1, 73.2, 57.7, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {16.0, 105.3, 119.3}, true, 8, {27.0, 37.0, 31.0, 18.5}, false, false, true, false, true, false, true, true, true, true, 2, true, true};
    struct Car Kia2 = {"Kia", "SUV", "Sorento", "Kia Motors", "Silver", 20000, 8, 35000.0, true, {6, 290.0, 252.0, 3.3, "Gasoline"}, {109.4, 189.0, 74.4, 66.5, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {11.3, 154.2, 73.0}, true, 10, {20.0, 28.0, 23.0, 18.8}, true, false, true, true, true, true, true, true, true, true, 2, true, true};
    struct Car Toyota1 = {"Toyota", "Sedan", "Camry", "Toyota Motors", "Red", 10000, 5, 25000.0, true, {4, 178.0, 170.0, 2.5, "Gasoline"}, {109.3, 192.1, 72.4, 56.5, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {15.1, 102.7, 111.2}, true, 8, {28.0, 39.0, 32.0, 16.0}, false, false, true, true, true, false, true, true, true, false, 2, true, true};
    struct Car Toyota2 = {"Toyota", "SUV", "Highlander", "Toyota Motors", "Black", 150, 3, 35000.0, true, {6, 295.0, 263.0, 3.5, "Gasoline"}, {112.2, 194.9, 75.8, 68.1, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {16.0, 144.9, 84.3}, true, 8, {23.0, 29.0, 25.0, 17.9}, false, false, true, true, true, true, true, true, true, false, 3, true, true};
    struct Car Honda1 = {"Honda","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Honda2 = {"Honda","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Mazda1 = {"Mazda", "Sedan", "Optima", "Kia Motors", "White", 15000, 10, 25000.0, true, {4, 180.0, 170.0, 2.4, "Gasoline"}, {110.4, 191.1, 73.2, 57.7, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {16.0, 105.3, 119.3}, true, 8, {27.0, 37.0, 31.0, 18.5}, false, false, true, false, true, false, true, true, true, true, 2, true, true};
    struct Car Mazda2 = {"Mazdaa", "SUV", "Sorento", "Kia Motors", "Silver", 20000, 8, 35000.0, true, {6, 290.0, 252.0, 3.3, "Gasoline"}, {109.4, 189.0, 74.4, 66.5, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {11.3, 154.2, 73.0}, true, 10, {20.0, 28.0, 23.0, 18.8}, true, false, true, true, true, true, true, true, true, true, 2, true, true};
    struct Car Nissan1 = {"Nissan", "Sedan", "Camry", "Toyota Motors", "Red", 10000, 5, 25000.0, true, {4, 178.0, 170.0, 2.5, "Gasoline"}, {109.3, 192.1, 72.4, 56.5, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {15.1, 102.7, 111.2}, true, 8, {28.0, 39.0, 32.0, 16.0}, false, false, true, true, true, false, true, true, true, false, 2, true, true};
    struct Car Nissan2 = {"Nissan", "SUV", "Highlander", "Toyota Motors", "Black", 15000, 3, 35000.0, true, {6, 295.0, 263.0, 3.5, "Gasoline"}, {112.2, 194.9, 75.8, 68.1, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {16.0, 144.9, 84.3}, true, 8, {23.0, 29.0, 25.0, 17.9}, false, false, true, true, true, true, true, true, true, false, 3, true, true};
   
//  group2
    struct Car Ford1 = {"Ford","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Ford2 = {"Ford","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Genesis1 = {"Genesis", "Sedan", "Optima", "Kia Motors", "White", 15000, 10, 25000.0, true, {4, 180.0, 170.0, 2.4, "Gasoline"}, {110.4, 191.1, 73.2, 57.7, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {16.0, 105.3, 119.3}, true, 8, {27.0, 37.0, 31.0, 18.5}, false, false, true, false, true, false, true, true, true, true, 2, true, true};
    struct Car Genesis2 = {"Genesis", "SUV", "Sorento", "Kia Motors", "Silver", 20000, 8, 35000.0, true, {6, 290.0, 252.0, 3.3, "Gasoline"}, {109.4, 189.0, 74.4, 66.5, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {11.3, 154.2, 73.0}, true, 10, {20.0, 28.0, 23.0, 18.8}, true, false, true, true, true, true, true, true, true, true, 2, true, true};
    struct Car Volvo1 = {"Volvo", "Sedan", "Camry", "Toyota Motors", "Red", 10000, 5, 25000.0, true, {4, 178.0, 170.0, 2.5, "Gasoline"}, {109.3, 192.1, 72.4, 56.5, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {15.1, 102.7, 111.2}, true, 8, {28.0, 39.0, 32.0, 16.0}, false, false, true, true, true, false, true, true, true, false, 2, true, true};
    struct Car Volvo2 = {"Volve", "SUV", "Highlander", "Toyota Motors", "Black", 15000, 3, 35000.0, true, {6, 295.0, 263.0, 3.5, "Gasoline"}, {112.2, 194.9, 75.8, 68.1, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {16.0, 144.9, 84.3}, true, 8, {23.0, 29.0, 25.0, 17.9}, false, false, true, true, true, true, true, true, true, false, 3, true, true};
    struct Car Acura1 = {"Acura","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Acura2 = {"Acura","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    
//    group3
    struct Car BMW1 = {"BMW", "Sedan", "Optima", "Kia Motors", "White", 15000, 10, 25000.0, true, {4, 180.0, 170.0, 2.4, "Gasoline"}, {110.4, 191.1, 73.2, 57.7, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {16.0, 105.3, 119.3}, true, 8, {27.0, 37.0, 31.0, 18.5}, false, false, true, false, true, false, true, true, true, true, 2, true, true};
    struct Car BMW2 = {"BMW", "SUV", "Sorento", "Kia Motors", "Silver", 20000, 8, 35000.0, true, {6, 290.0, 252.0, 3.3, "Gasoline"}, {109.4, 189.0, 74.4, 66.5, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {11.3, 154.2, 73.0}, true, 10, {20.0, 28.0, 23.0, 18.8}, true, false, true, true, true, true, true, true, true, true, 2, true, true};
    struct Car Audi1 = {"Audi", "Sedan", "Camry", "Toyota Motors", "Red", 10000, 5, 25000.0, true, {4, 178.0, 170.0, 2.5, "Gasoline"}, {109.3, 192.1, 72.4, 56.5, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {15.1, 102.7, 111.2}, true, 8, {28.0, 39.0, 32.0, 16.0}, false, false, true, true, true, false, true, true, true, false, 2, true, true};
    struct Car Audi2 = {"Audi", "SUV", "Highlander", "Toyota Motors", "Black", 15000, 3, 35000.0, true, {6, 295.0, 263.0, 3.5, "Gasoline"}, {112.2, 194.9, 75.8, 68.1, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {16.0, 144.9, 84.3}, true, 8, {23.0, 29.0, 25.0, 17.9}, false, false, true, true, true, true, true, true, true, false, 3, true, true};
    struct Car Bentley = {"Bentley","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Bentley2 = {"Bentley","Sedan","Accord","Honda Motor Co., Ltd.","White",5000,10,25000.00,true,{4, 192, 192, 1.5, "Gasoline"},{109.3, 192.2, 73.3, 57.1, 4},{"Sedan", "LED", "LED", "Chrome", "Alloy"},{5, "Leather", "Black"},{16.7, 103.2, 105.6},true,6,{30, 38, 33, 14},false,false,true,true,true,false,true,true,true,false,2,true,true,true};
    struct Car Ferrari1 = {"Ferrari1", "Sedan", "Optima", "Kia Motors", "White", 15000, 10, 25000.0, true, {4, 180.0, 170.0, 2.4, "Gasoline"}, {110.4, 191.1, 73.2, 57.7, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {16.0, 105.3, 119.3}, true, 8, {27.0, 37.0, 31.0, 18.5}, false, false, true, false, true, false, true, true, true, true, 2, true, true};
    struct Car Ferrari2 = {"Ferrari1", "AAA", "Sorento", "Kia Motors", "Silver", 20000, 8, 35000.0, true, {6, 290.0, 252.0, 3.3, "Gasoline"}, {109.4, 189.0, 74.4, 66.5, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {11.3, 154.2, 73.0}, true, 10, {20.0, 28.0, 23.0, 18.8}, true, false, true, true, true, true, true, true, true, true, 2, true, true};
    struct Car AstonMartin1 = {"AstonMartin", "Sedan", "Camry", "Toyota Motors", "Red", 10000, 5, 25000.0, true, {4, 178.0, 170.0, 2.5, "Gasoline"}, {109.3, 192.1, 72.4, 56.5, 4}, {"Sedan", "LED", "LED", "Chrome", "Alloy"}, {5, "Leather", "Black"}, {15.1, 102.7, 111.2}, true, 8, {28.0, 39.0, 32.0, 16.0}, false, false, true, true, true, false, true, true, true, false, 2, true, true};
    struct Car AstonMartin2 = {"AstonMartin", "SUV", "Highlander", "Toyota Motors", "Black", 15000, 3, 35000.0, true, {6, 295.0, 263.0, 3.5, "Gasoline"}, {112.2, 194.9, 75.8, 68.1, 4}, {"SUV", "LED", "LED", "Chrome", "Alloy"}, {7, "Leather", "Black"}, {16.0, 144.9, 84.3}, true, 8, {23.0, 29.0, 25.0, 17.9}, false, false, true, true, true, true, true, true, true, false, 3, true, true};
    
    char group1[MAX_BRANDS][20] = {"Kia", "Toyota", "Honda", "Mazda", "Nissan"};
    char group2[MAX_BRANDS][20] = {"Ford", "Genesis", "Volvo", "Acura"};
    char group3[MAX_BRANDS][20] = {"BMW", "Audi", "Bentley", "Ferrari", "Aston Martin", "Bugatti"};
    
// start part
    
    int start_option;
    printf("----------------------------------------------------------- ");
    printf("----------------------------------------------------------- ");
    printf("-------- Welcome come to ChangLi Auto dealership ---------- ");
    printf("----------------------------------------------------------- ");
    printf("----------------------------------------------------------- ");
    
    printf("please choose what you want to do today?\nHere is the menu:\n[1] update the inventory when you sell a car\n[2] update the inventory when you buy a car\n[3] you want to transfer car between branches\n[4] new car distribution to branches\n[5] search and check the inventory\nPlease input your option number, press any other keys to quit.\n ");
           
    scanf("%d", &start_option);
    
//    struct searchItem items;
    int num_branches = 0;
//    char* branches_num = malloc(sizeof(int));
//    * (int*) branches_num = num_branches;
    struct Dealership* dealer = malloc(num_branches * sizeof(struct Dealership));
    struct Dealership branches[num_branches];

    
    int* num_cars = 0;
    int num_distribution;
    char* car_model = " ";
//    char* arr_distribution[5][30];
    int* branchesOut = 0;
    int* branchesIn = 0;
    double transfer_expenses = 0;
    struct searchItem item;
    
    switch (start_option) {
            
        case 1:
            printf("Congratulation! \nPlease tell me your branch, number, and car model");
            scanf("%d %d %s", &num_branches, num_cars, car_model);
   
            sell_car(branches[num_branches], num_cars, car_model);
            printf("updating for selling car is completed!See you next time.\n");
            break;
            
        case 2:
            printf("Congratulation! \nPlease tell me your branch, number, and car model");
            scanf("%d %d %s", &num_branches, num_cars, car_model);

            buy_car(branches[num_branches], num_cars, car_model);
            printf("updating for buying car is completed!See you next time.\n");
            break;
            
        case 3:
//
            
            printf("Hi, for car transfering, please tell me which branch for transfering from,which branch for transfering to, car number, car model and transfer expenses.\n");
            scanf("%d %d %d %s %lf", branchesOut, branchesIn, num_cars, car_model,&transfer_expenses);
   
            transfer_car(*branchesOut, *branchesIn, num_cars, car_model, transfer_expenses);
            printf("updating for transfering car is completed! See you next time.\n");
            break;
            
        case 4:
            printf("Hi, for car distribution to each branch, please tell me which branch will receive inventory and number seperatly?\nExample: branch, number\n");
            scanf("%d", &num_distribution);
            for(int j=0; j < num_distribution; j++){
                printf("please input the branch and number");
                scanf("%d %d %s", &num_branches, num_cars, car_model);
                buy_car(branches[num_branches], num_cars, car_model);
            }
            break;
            
        case 5:
            printf("Welcome to use search service!\n");
            printf("Please input search keywords: branch\n");
            scanf("%d", &num_branches);
            
            printf("Please input search keywords: make\n");
            scanf("%s", item.make);
            printf("Please input search keywords: manufacture\n");
            scanf("%s", item.manufacture);
            printf("Please input search keywords: new/used\n");
            int input;
            scanf("%d", &input);
            item.new = (bool)input;
            printf("Please input search keywords: msrp max\n");
            scanf("%f", &item.MSRP_MAX);
            printf("Please input search keywords: msrp min\n");
            scanf("%f", &item.MSRP_MIN);
            printf("Please input search keywords: mileage max\n");
            scanf("%d", &item.mileageMax);
            printf("Please input search keywords: mileage min\n");
            scanf("%d", &item.mileageMin);
            
            printf("Please input search keywords: color\n");
            scanf("%s", item.color);
            printf("Please input search keywords: availability\n");
            scanf("%d", &item.availability);
            printf("Please input search keywords: country\n");
            scanf("%s", item.country);
            
            searchInventory(branches[num_branches], item);
            break;
            
        default:
            break;
    }
    
    free(dealer);
    return 0;
}

// external function
float calculate_rebate_or_promotion(char *make, float MSRP, char *country) {
    float rebate_or_promotion = 0.0;
    bool is_usa = strcmp(country, "USA") == 0;

    if (strcmp(make, "Honda") == 0 && strcmp(country, "Canada") == 0) {
        rebate_or_promotion = MSRP * 0.02;
    } else if (strcmp(make, "Volvo") == 0 && strcmp(country, "Mexico") == 0 && MSRP > 60000) {
        rebate_or_promotion = MSRP * 0.03;
    } else if (is_usa && (strcmp(make, "BMW") == 0 || strcmp(make, "Volvo") == 0 ||
                           strcmp(make, "Audi") == 0 || strcmp(make, "Bentley") == 0 ||
                           strcmp(make, "Ferrari") == 0)) {
        // Check if the customer is eligible for the loyalty program (some conditions not specified)
        bool is_loyal_customer = true; // Example only
        if (is_loyal_customer) {
            rebate_or_promotion = MSRP * 0.025;
        }
    }

    return rebate_or_promotion;
};

void searchInventory(struct Dealership dealer, struct searchItem items) {

    
  for(int m = 0; m < 5; m++) {
    for(int n = 0; n < dealer.inventory.num; n++) {
        
      // Check if the car matches the given criteria
      if(strcmp(dealer[m].cars.make, items.make) == 0
         && strcmp(dealer[m].cars.manufacturer, items.manufacture) == 0
         && (strcmp(dealer[m].cars.new, items.new) == 0
         && dealer[m].cars.mileage >= items.mileageMax
         && dealer[m].cars.mileage <= items.mileageMin
         && dealer[m].cars.MSRP >= items.MSRP_MIN
         && dealer[m].cars.MSRP <= items.MSRP_MAX
         && strcmp(dealer[m].cars.seatingTrim.color, items.color) == 0) {
          
        // Print the details of the matching car
        printf("Branch: %s\n", dealer[m].cars[n].name);
        printf("Model: %s\n", dealer[m].cars[n].model);
        printf("Manufacturer: %s\n", dealer[m].cars[j].manufacturer);
        printf("Condition: %s\n", dealer[m].cars[j].condition);
        printf("Mileage: %d\n", dealer[m].cars[j].mileage);
        printf("Price: %d\n", dealer[m].cars[j].price);
        printf("Color: %s\n", dealer[m].cars[j].color);
        printf("\n");
      }
    }
  }
}

 double final_price(struct Dealership branches, char currency, float MSRP, int rate_type) {
  
      double local_MSRP, final_price;
      int rand_int;
     
      if(strcmp(&currency, "CAD") == 0 ){
          if(rate_type == 0){
              //    get random data from 1.2 to 1.4
              rand_int = rand() % 2001;
              double rate_btw_CAD_USD = rand_int * 0.0001 + 1.2;
              local_MSRP = MSRP * rate_btw_CAD_USD;
          }
          else{
              local_MSRP = MSRP * 1.3;
          }
          
          if(strcmp(branches.cars.make, "Honda") ==0){
              final_price = local_MSRP * 0.98;
          }
          
      }
      //    get random data from 1700 to 1900
      else if (strcmp(&currency, "MXN")){
          if(rate_type == 0){
              rand_int = rand() % 201;
              double rate_btw_CAD_USD_MXN = rand_int + 1700;
              local_MSRP = MSRP * rate_btw_CAD_USD_MXN;
          }
          else{
              local_MSRP = MSRP * 1817;
          }
          if((strcmp(branches.cars.make, "Volvo") ==0) && (branches.cars.MSRP >=60000)){
              final_price = local_MSRP * 0.97;
          }
          else if (strcmp(&currency, "MXN")){
              if(((strcmp(branches.cars.make, "BMW") ==0)||(strcmp(branches.cars.make, "VOLVO") ==0)||(strcmp(branches.cars.make, "AUDI") ==0)||(strcmp(branches.cars.make, "ENTLEY") ==0)||(strcmp(branches.cars.make, "Ferrari") ==0) )&& (branches.cars.MSRP >=60000))
              {
                  final_price = MSRP * 0.975;
              }
          }
          else{
              printf("Welcome use currency change system!\n");
          }
      }
      return final_price;
      
    }

void sell_car(struct Dealership branches, int* num_cars, char* car_model){
          int temp = *num_cars;
    for (int i = 0; i < temp; i++) {
        if (strcmp(branches[i].inventory.model, car_model) == 0) {
            if (branches[i].inventory.quantity > 0)
            {
                branch_inventory[i].quantity--;
                printf("Car sold: %s\n", car_model);
                printf("New inventory:\n");
                for (int j = 0; j < num_cars; j++) {
                    printf("%s, %d, $%.2f, %d\n", branch_inventory[j].model, branch_inventory[j].year,
                        branch_inventory[j].price, branch_inventory[j].quantity);
                }
//                return;
            }
            else
            {
                printf("Error: %s is out of stock.\n", car_model);
//                return;
            }
        }
    }
    printf("Error: %s not found in inventory.\n", car_model);
}

// Define a function to buy a car for a branch
void buy_car(struct Dealership branches, int* num_cars, char* car_model) {
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
void transfer_car(int branchesOut, int branchesIn, int* num_cars, char* car_model, double transfer_expenses) {
            
    int rate_type;
    char currency;
          
    printf("Welcome to use car transfer system!\n");
    printf("Please enter which branch will transfer out the car?\n");
    scanf("%d", branchesOut);
    printf("Please enter which branch will transfer in the car?\n");
    scanf("%d", branchesIn);
          
    printf("The branch out use currency: %s", dealer.branchInfo.currency);
    printf("please choose rate type for currency\nfixed rat, press: 0, variable rate choose: 1");
    scanf("%d", &rate_type);

    dealer[branchesIn].inventory.final_price = final_price(dealer,  dealer.branchInfo.currency, dealer.cars.MSRP, rate_type);

    printf("local MSRP will be: %.2f\n", dealer.inventory.final_price + transfer_expenses);

    sell_car(dealer[branchesOut], num_cars, car_model);
    buy_car(dealer[branchesIn], num_cars, car_model);
          
}
