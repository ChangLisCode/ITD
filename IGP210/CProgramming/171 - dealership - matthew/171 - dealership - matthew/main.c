//
//  main.c
//  171 - dealership - matthew
//
//  Created by Chang on 2023-04-21.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int NUM_CARS = 25;           // number of cars
int CURRENT_CAR_INDEX = 25; // current place to insert a car
bool trim;                 // globally sets trim on or off
double exchangeCanada;     // exchanges rate generated in menu() and applied globally
double exchangeMexico;

struct date
{
    int day;
    int month;
    int year;
};

struct branch
{
    // public
    char name[20];
    char address[100];
    char postalCode[6];
    int phoneNumber;
    int faxNumber;
    char email[40];
    char managerName[20];
    // private info
    int managerPhoneNumber;
    int managerCellNumber;
    char managerAddress[100];
    char managerEmail[40];
    struct date managerEmploymentDate;
    int managerExperience;
    char financeName[20];
    int financePhone;
    int financeCell;
    char financeAddress[100];
    struct date financeEmploymentDate;
    int financeExperience;
    int numCars;
};

struct engine
{
    int type;
    int horsepower;
};

struct chassis
{
    int type;
    int model;
};

struct exterior
{
    int model;
    int preset;
};

struct dimensions
{
    double width;
    double length;
    double height;
};

struct fuel
{
    int type;
};
struct car
{
    int id;
    int model;
    char manufacturer[30];
    double price;
    char countryAvailability[20];
    char color[10];
    double milleage;
    bool used;
    bool transmission;
    struct engine carEngine;
    struct chassis carChassis;
    struct exterior carExterior;
    struct dimensions carDimensions;
    bool airBags;
    int numAirbags;
    struct fuel carFuel;
    bool hybrid;
    bool electric;
    bool automatic;
    bool nightVision;
    bool cruiseControl;
    int wheelDrive;
    bool hillAssist;
    bool tpms;
    bool voice;
    bool laneChange;
    bool forwardCollision;
    int seatHeater;
    bool steeringHeater;
    int qty;
    int branch;
};

void showBranches(int branchNum, struct branch *branches, bool private); // show branch info
void carsByBranch(struct car *cars, int branch); // show cars by branch
void showCars(struct car *cars, int searchType, char *searchWord, int searchInt, int minMax[]); // show all cars + search engine
void menu(struct branch *branches, struct car *cars); // repeated menu and submenus
void printRow(struct car *cars, int i); // horizontally print car information
double drand(double low, double high); // generate random exchange rate
void enterCar(struct car **cars, int branch); // sell car
void transferCar(struct car *cars, int first, int second); // transfer from one branch to another
void removeCar(struct car **cars, int id); // buy car

int main()
{
    // branches
    struct branch *branches = (struct branch *)malloc(5 * sizeof(struct branch));
    strcpy((branches + 0)->name, "Hoboken Branch");
    strcpy((branches + 0)->address, "111 1th St NY");
    strcpy((branches + 0)->postalCode, "90210");
    (branches + 0)->phoneNumber = 604938492;
    (branches + 0)->faxNumber = 614938492;
    strcpy((branches + 0)->email, "email@mail.com");
    strcpy((branches + 0)->managerName, "Manuel Gary");
    (branches + 0)->managerPhoneNumber = 604938492;
    (branches + 0)->managerCellNumber = 6042252291;
    strcpy((branches + 0)->managerAddress, "123 4th st");
    strcpy((branches + 0)->managerEmail, "manuel@gary.com");
    struct date employmentDate = {1, 2, 2008};
    (branches + 0)->managerEmploymentDate = employmentDate;
    (branches + 0)->managerExperience = 25;
    strcpy((branches + 0)->financeName, "Finn Gary");
    (branches + 0)->financePhone = 604938492;
    (branches + 0)->financeCell = 6042252291;
    strcpy((branches + 0)->financeAddress, "123 4th st");
    struct date empDate = {1, 2, 2008};
    (branches + 0)->financeEmploymentDate = empDate;
    (branches + 0)->financeExperience = 25;
    (branches + 0)->numCars = 22;

    strcpy((branches + 1)->name, "Opera Branch");
    strcpy((branches + 1)->address, "211 1th St TO");
    strcpy((branches + 1)->postalCode, "54323");
    (branches + 1)->phoneNumber = 677893892;
    (branches + 1)->faxNumber = 656938492;
    strcpy((branches + 1)->email, "email@mail.com");
    strcpy((branches + 1)->managerName, "Manuel Gary");
    (branches + 1)->managerPhoneNumber = 604938492;
    (branches + 1)->managerCellNumber = 6042252291;
    strcpy((branches + 1)->managerAddress, "123 4th st");
    strcpy((branches + 1)->managerEmail, "manuel@gary.com");
    struct date employmentDate1 = {1, 2, 2008};
    (branches + 1)->managerEmploymentDate = employmentDate1;
    (branches + 1)->managerExperience = 25;
    strcpy((branches + 1)->financeName, "Finn Gary");
    (branches + 1)->financePhone = 604938492;
    (branches + 1)->financeCell = 6042252291;
    strcpy((branches + 1)->financeAddress, "123 4th st");
    struct date empDate1 = {1, 2, 2008};
    (branches + 1)->financeEmploymentDate = empDate1;
    (branches + 1)->financeExperience = 25;
    (branches + 1)->numCars = 22;

    
    strcpy((branches + 2)->name, "Hoboken Branch");
    strcpy((branches + 2)->address, "111 1th St NY");
    strcpy((branches + 2)->postalCode, "92212");
    (branches + 2)->phoneNumber = 624938492;
    (branches + 2)->faxNumber = 614938492;
    strcpy((branches + 2)->email, "email@mail.com");
    strcpy((branches + 2)->managerName, "Manuel Gary");
    (branches + 2)->managerPhoneNumber = 624938492;
    (branches + 2)->managerCellNumber = 6242252291;
    strcpy((branches + 2)->managerAddress, "123 4th st");
    strcpy((branches + 2)->managerEmail, "manuel@gary.com");
    struct date employmentDate2 = {1, 2, 2228};
    (branches + 2)->managerEmploymentDate = employmentDate;
    (branches + 2)->managerExperience = 25;
    strcpy((branches + 2)->financeName, "Finn Gary");
    (branches + 2)->financePhone = 624938492;
    (branches + 2)->financeCell = 6242252291;
    strcpy((branches + 2)->financeAddress, "123 4th st");
    struct date empDate2 = {1, 2, 2228};
    (branches + 2)->financeEmploymentDate = empDate;
    (branches + 2)->financeExperience = 25;
    (branches + 2)->numCars = 22;

    strcpy((branches + 3)->name, "Hoboken Branch");
    strcpy((branches + 3)->address, "111 1th St NY");
    strcpy((branches + 3)->postalCode, "93313");
    (branches + 3)->phoneNumber = 633938393;
    (branches + 3)->faxNumber = 613938393;
    strcpy((branches + 3)->email, "email@mail.com");
    strcpy((branches + 3)->managerName, "Manuel Gary");
    (branches + 3)->managerPhoneNumber = 633938393;
    (branches + 3)->managerCellNumber = 6333353391;
    strcpy((branches + 3)->managerAddress, "133 3th st");
    strcpy((branches + 3)->managerEmail, "manuel@gary.com");
    struct date employmentDate3 = {1, 3, 3338};
    (branches + 3)->managerEmploymentDate = employmentDate;
    (branches + 3)->managerExperience = 35;
    strcpy((branches + 3)->financeName, "Finn Gary");
    (branches + 3)->financePhone = 633938393;
    (branches + 3)->financeCell = 6333353391;
    strcpy((branches + 3)->financeAddress, "133 3th st");
    struct date empDate3 = {1, 3, 3338};
    (branches + 3)->financeEmploymentDate = empDate;
    (branches + 3)->financeExperience = 35;
    (branches + 3)->numCars = 33;

    strcpy((branches + 4)->name, "Hoboken Branch");
    strcpy((branches + 4)->address, "111 1th St NY");
    strcpy((branches + 4)->postalCode, "94414");
    (branches + 4)->phoneNumber = 644948494;
    (branches + 4)->faxNumber = 614948494;
    strcpy((branches + 4)->email, "email@mail.com");
    strcpy((branches + 4)->managerName, "Manuel Gary");
    (branches + 4)->managerPhoneNumber = 644948494;
    (branches + 4)->managerCellNumber = 6444454491;
    strcpy((branches + 4)->managerAddress, "144 4th st");
    strcpy((branches + 4)->managerEmail, "manuel@gary.com");
    struct date employmentDate4 = {1, 4, 4448};
    (branches + 4)->managerEmploymentDate = employmentDate;
    (branches + 4)->managerExperience = 45;
    strcpy((branches + 4)->financeName, "Finn Gary");
    (branches + 4)->financePhone = 644948494;
    (branches + 4)->financeCell = 6444454491;
    strcpy((branches + 4)->financeAddress, "144 4th st");
    struct date empDate4 = {1, 4, 4448};
    (branches + 4)->financeEmploymentDate = empDate;
    (branches + 4)->financeExperience = 45;
    (branches + 4)->numCars = 44;
    // cars

    struct car *cars = (struct car *)malloc(50 * sizeof(struct car));

    (cars + 0)->id = 0;
    (cars + 0)->model = 1121;
    strcpy((cars + 0)->manufacturer, "Honda");
    (cars + 0)->price = 21121.00;
    strcpy((cars + 0)->countryAvailability, "Canada");
    strcpy((cars + 0)->color, "Green");
    (cars + 0)->milleage = 121.00;
    (cars + 0)->used = true;
    (cars + 0)->transmission = false;
    struct engine carEngine = {1, 12};
    (cars + 0)->carEngine = carEngine;
    struct chassis carChassis = {2, 5};
    (cars + 0)->carChassis = carChassis;
    struct exterior carExterior = {10, 3};
    (cars + 0)->carExterior = carExterior;
    struct dimensions carDimensions = {43.4, 23.3, 45.5};
    (cars + 0)->carDimensions = carDimensions;
    (cars + 0)->airBags = false;
    (cars + 0)->numAirbags = false;
    struct fuel carFuel = {1};
    (cars + 0)->carFuel = carFuel;
    (cars + 0)->hybrid = false;
    (cars + 0)->electric = false;
    (cars + 0)->automatic = false;
    (cars + 0)->nightVision = false;
    (cars + 0)->cruiseControl = false;
    (cars + 0)->wheelDrive = 2;
    (cars + 0)->tpms = false;
    (cars + 0)->voice = false;
    (cars + 0)->laneChange = false;
    (cars + 0)->forwardCollision = false;
    (cars + 0)->seatHeater = 2;
    (cars + 0)->steeringHeater = false;
    (cars + 0)->qty = 1;
    (cars + 0)->branch = 0;

    (cars + 1)->id = 1;
    (cars + 1)->model = 434;
    strcpy((cars + 1)->manufacturer, "Hyundai");
    (cars + 1)->price = 241121.00;
    strcpy((cars + 1)->countryAvailability, "Canada");
    strcpy((cars + 1)->color, "Red");
    (cars + 1)->milleage = 3321.00;
    (cars + 1)->used = false;
    (cars + 1)->transmission = true;
    struct engine carEngine1 = {1, 12};
    (cars + 1)->carEngine = carEngine1;
    struct chassis carChassis1 = {2, 5};
    (cars + 1)->carChassis = carChassis1;
    struct exterior carExterior1 = {10, 3};
    (cars + 1)->carExterior = carExterior1;
    struct dimensions carDimensions1 = {43.4, 23.3, 45.5};
    (cars + 1)->carDimensions = carDimensions1;
    (cars + 1)->airBags = true;
    (cars + 1)->numAirbags = true;
    struct fuel carFuel1 = {1};
    (cars + 1)->carFuel = carFuel1;
    (cars + 1)->hybrid = true;
    (cars + 1)->electric = true;
    (cars + 1)->automatic = false;
    (cars + 1)->nightVision = true;
    (cars + 1)->cruiseControl = true;
    (cars + 1)->wheelDrive = 2;
    (cars + 1)->tpms = false;
    (cars + 1)->voice = true;
    (cars + 1)->laneChange = true;
    (cars + 1)->forwardCollision = true;
    (cars + 1)->seatHeater = 2;
    (cars + 1)->steeringHeater = true;
    (cars + 1)->qty = 2;
    (cars + 1)->branch = 1;

    (cars + 2)->id = 2;
    (cars + 2)->model = 434;
    strcpy((cars + 2)->manufacturer, "Ferrari");
    (cars + 2)->price = 242222.00;
    strcpy((cars + 2)->countryAvailability, "Canada");
    strcpy((cars + 2)->color, "Red");
    (cars + 2)->milleage = 3322.00;
    (cars + 2)->used = false;
    (cars + 2)->transmission = true;
    struct engine carEngine2 = {2, 22};
    (cars + 2)->carEngine = carEngine2;
    struct chassis carChassis2 = {2, 5};
    (cars + 2)->carChassis = carChassis2;
    struct exterior carExterior2 = {10, 3};
    (cars + 2)->carExterior = carExterior2;
    struct dimensions carDimensions2 = {43.4, 23.3, 45.5};
    (cars + 2)->carDimensions = carDimensions2;
    (cars + 2)->airBags = true;
    (cars + 2)->numAirbags = true;
    struct fuel carFuel2 = {1};
    (cars + 2)->carFuel = carFuel2;
    (cars + 2)->hybrid = true;
    (cars + 2)->electric = true;
    (cars + 2)->automatic = false;
    (cars + 2)->nightVision = true;
    (cars + 2)->cruiseControl = true;
    (cars + 2)->wheelDrive = 2;
    (cars + 2)->tpms = false;
    (cars + 2)->voice = true;
    (cars + 2)->laneChange = true;
    (cars + 2)->forwardCollision = true;
    (cars + 2)->seatHeater = 2;
    (cars + 2)->steeringHeater = true;
    (cars + 2)->qty = 2;
    (cars + 2)->branch = 2;


    (cars + 3)->id = 3;
    (cars + 3)->model = 434;
    strcpy((cars + 3)->manufacturer, "Ferrari");
    (cars + 3)->price = 343333.00;
    strcpy((cars + 3)->countryAvailability, "Canada");
    strcpy((cars + 3)->color, "Red");
    (cars + 3)->milleage = 3333.00;
    (cars + 3)->used = false;
    (cars + 3)->transmission = true;
    struct engine carEngine3 = {3, 33};
    (cars + 3)->carEngine = carEngine3;
    struct chassis carChassis3 = {3, 5};
    (cars + 3)->carChassis = carChassis3;
    struct exterior carExterior3 = {10, 3};
    (cars + 3)->carExterior = carExterior3;
    struct dimensions carDimensions3 = {43.4, 33.3, 45.5};
    (cars + 3)->carDimensions = carDimensions3;
    (cars + 3)->airBags = true;
    (cars + 3)->numAirbags = true;
    struct fuel carFuel3 = {1};
    (cars + 3)->carFuel = carFuel3;
    (cars + 3)->hybrid = true;
    (cars + 3)->electric = true;
    (cars + 3)->automatic = false;
    (cars + 3)->nightVision = true;
    (cars + 3)->cruiseControl = true;
    (cars + 3)->wheelDrive = 3;
    (cars + 3)->tpms = false;
    (cars + 3)->voice = true;
    (cars + 3)->laneChange = true;
    (cars + 3)->forwardCollision = true;
    (cars + 3)->seatHeater = 3;
    (cars + 3)->steeringHeater = true;
    (cars + 3)->qty = 3;
    (cars + 3)->branch = 3;

    (cars + 4)->id = 4;
    (cars + 4)->model = 444;
    strcpy((cars + 4)->manufacturer, "Ferrari");
    (cars + 4)->price = 444444.00;
    strcpy((cars + 4)->countryAvailability, "Canada");
    strcpy((cars + 4)->color, "Green");
    (cars + 4)->milleage = 4444.00;
    (cars + 4)->used = false;
    (cars + 4)->transmission = true;
    struct engine carEngine4 = {4, 44};
    (cars + 4)->carEngine = carEngine4;
    struct chassis carChassis4 = {4, 5};
    (cars + 4)->carChassis = carChassis4;
    struct exterior carExterior4 = {10, 4};
    (cars + 4)->carExterior = carExterior4;
    struct dimensions carDimensions4 = {44.4, 44.4, 45.5};
    (cars + 4)->carDimensions = carDimensions4;
    (cars + 4)->airBags = true;
    (cars + 4)->numAirbags = true;
    struct fuel carFuel4 = {1};
    (cars + 4)->carFuel = carFuel4;
    (cars + 4)->hybrid = true;
    (cars + 4)->electric = true;
    (cars + 4)->automatic = false;
    (cars + 4)->nightVision = true;
    (cars + 4)->cruiseControl = true;
    (cars + 4)->wheelDrive = 4;
    (cars + 4)->tpms = false;
    (cars + 4)->voice = true;
    (cars + 4)->laneChange = true;
    (cars + 4)->forwardCollision = true;
    (cars + 4)->seatHeater = 4;
    (cars + 4)->steeringHeater = true;
    (cars + 4)->qty = 4;
    (cars + 4)->branch = 4;
    
    (cars + 5)->id = 5;
    (cars + 5)->model = 555;
    strcpy((cars + 5)->manufacturer, "Acura");
    (cars + 5)->price = 555555.00;
    strcpy((cars + 5)->countryAvailability, "Canada");
    strcpy((cars + 5)->color, "Green");
    (cars + 5)->milleage = 5555.00;
    (cars + 5)->used = false;
    (cars + 5)->transmission = true;
    struct engine carEngine5 = {5, 55};
    (cars + 5)->carEngine = carEngine5;
    struct chassis carChassis5 = {5, 5};
    (cars + 5)->carChassis = carChassis5;
    struct exterior carExterior5 = {10, 5};
    (cars + 5)->carExterior = carExterior5;
    struct dimensions carDimensions5 = {55.5, 55.5, 55.5};
    (cars + 5)->carDimensions = carDimensions5;
    (cars + 5)->airBags = true;
    (cars + 5)->numAirbags = true;
    struct fuel carFuel5 = {1};
    (cars + 5)->carFuel = carFuel5;
    (cars + 5)->hybrid = true;
    (cars + 5)->electric = true;
    (cars + 5)->automatic = false;
    (cars + 5)->nightVision = true;
    (cars + 5)->cruiseControl = true;
    (cars + 5)->wheelDrive = 5;
    (cars + 5)->tpms = false;
    (cars + 5)->voice = true;
    (cars + 5)->laneChange = true;
    (cars + 5)->forwardCollision = true;
    (cars + 5)->seatHeater = 5;
    (cars + 5)->steeringHeater = true;
    (cars + 5)->qty = 5;
    (cars + 5)->branch = 0;
    
    (cars + 6)->id = 6;
    (cars + 6)->model = 666;
    strcpy((cars + 6)->manufacturer, "Acura");
    (cars + 6)->price = 666666.00;
    strcpy((cars + 6)->countryAvailability, "Canada");
    strcpy((cars + 6)->color, "Green");
    (cars + 6)->milleage = 6666.00;
    (cars + 6)->used = false;
    (cars + 6)->transmission = true;
    struct engine carEngine6 = {6, 66};
    (cars + 6)->carEngine = carEngine6;
    struct chassis carChassis6 = {6, 5};
    (cars + 6)->carChassis = carChassis6;
    struct exterior carExterior6 = {10, 6};
    (cars + 6)->carExterior = carExterior6;
    struct dimensions carDimensions6 = {66.6, 66.6, 66.6};
    (cars + 6)->carDimensions = carDimensions6;
    (cars + 6)->airBags = true;
    (cars + 6)->numAirbags = true;
    struct fuel carFuel6 = {1};
    (cars + 6)->carFuel = carFuel6;
    (cars + 6)->hybrid = true;
    (cars + 6)->electric = true;
    (cars + 6)->automatic = false;
    (cars + 6)->nightVision = true;
    (cars + 6)->cruiseControl = true;
    (cars + 6)->wheelDrive = 6;
    (cars + 6)->tpms = false;
    (cars + 6)->voice = true;
    (cars + 6)->laneChange = true;
    (cars + 6)->forwardCollision = true;
    (cars + 6)->seatHeater = 6;
    (cars + 6)->steeringHeater = true;
    (cars + 6)->qty = 6;
    (cars + 6)->branch = 1;

    
    (cars + 7)->id = 7;
    (cars + 7)->model = 777;
    strcpy((cars + 7)->manufacturer, "Volvo");
    (cars + 7)->price = 777777.00;
    strcpy((cars + 7)->countryAvailability, "Canada");
    strcpy((cars + 7)->color, "Green");
    (cars + 7)->milleage = 7777.00;
    (cars + 7)->used = false;
    (cars + 7)->transmission = true;
    struct engine carEngine7 = {7, 77};
    (cars + 7)->carEngine = carEngine7;
    struct chassis carChassis7 = {7, 5};
    (cars + 7)->carChassis = carChassis7;
    struct exterior carExterior7 = {10, 7};
    (cars + 7)->carExterior = carExterior7;
    struct dimensions carDimensions7 = {77.7, 77.7, 77.7};
    (cars + 7)->carDimensions = carDimensions7;
    (cars + 7)->airBags = true;
    (cars + 7)->numAirbags = true;
    struct fuel carFuel7 = {1};
    (cars + 7)->carFuel = carFuel7;
    (cars + 7)->hybrid = true;
    (cars + 7)->electric = true;
    (cars + 7)->automatic = false;
    (cars + 7)->nightVision = true;
    (cars + 7)->cruiseControl = true;
    (cars + 7)->wheelDrive = 7;
    (cars + 7)->tpms = false;
    (cars + 7)->voice = true;
    (cars + 7)->laneChange = true;
    (cars + 7)->forwardCollision = true;
    (cars + 7)->seatHeater = 7;
    (cars + 7)->steeringHeater = true;
    (cars + 7)->qty = 7;
    (cars + 7)->branch = 2;

    
    (cars + 8)->id = 8;
    (cars + 8)->model = 888;
    strcpy((cars + 8)->manufacturer, "Volvo");
    (cars + 8)->price = 888888.00;
    strcpy((cars + 8)->countryAvailability, "Canada");
    strcpy((cars + 8)->color, "Blue");
    (cars + 8)->milleage = 8888.00;
    (cars + 8)->used = false;
    (cars + 8)->transmission = true;
    struct engine carEngine8 = {8, 88};
    (cars + 8)->carEngine = carEngine8;
    struct chassis carChassis8 = {8, 5};
    (cars + 8)->carChassis = carChassis8;
    struct exterior carExterior8 = {10, 8};
    (cars + 8)->carExterior = carExterior8;
    struct dimensions carDimensions8 = {88.8, 88.8, 88.8};
    (cars + 8)->carDimensions = carDimensions8;
    (cars + 8)->airBags = true;
    (cars + 8)->numAirbags = true;
    struct fuel carFuel8 = {1};
    (cars + 8)->carFuel = carFuel8;
    (cars + 8)->hybrid = true;
    (cars + 8)->electric = true;
    (cars + 8)->automatic = false;
    (cars + 8)->nightVision = true;
    (cars + 8)->cruiseControl = true;
    (cars + 8)->wheelDrive = 8;
    (cars + 8)->tpms = false;
    (cars + 8)->voice = true;
    (cars + 8)->laneChange = true;
    (cars + 8)->forwardCollision = true;
    (cars + 8)->seatHeater = 8;
    (cars + 8)->steeringHeater = true;
    (cars + 8)->qty = 8;
    (cars + 8)->branch = 3;

    
    (cars + 9)->id = 9;
    (cars + 9)->model = 999;
    strcpy((cars + 9)->manufacturer, "Genesis");
    (cars + 9)->price = 999999.00;
    strcpy((cars + 9)->countryAvailability, "Canada");
    strcpy((cars + 9)->color, "Blue");
    (cars + 9)->milleage = 9999.00;
    (cars + 9)->used = false;
    (cars + 9)->transmission = true;
    struct engine carEngine9 = {9, 99};
    (cars + 9)->carEngine = carEngine9;
    struct chassis carChassis9 = {9, 5};
    (cars + 9)->carChassis = carChassis9;
    struct exterior carExterior9 = {10, 9};
    (cars + 9)->carExterior = carExterior9;
    struct dimensions carDimensions9 = {99.9, 99.9, 99.9};
    (cars + 9)->carDimensions = carDimensions9;
    (cars + 9)->airBags = true;
    (cars + 9)->numAirbags = true;
    struct fuel carFuel9 = {1};
    (cars + 9)->carFuel = carFuel9;
    (cars + 9)->hybrid = true;
    (cars + 9)->electric = true;
    (cars + 9)->automatic = false;
    (cars + 9)->nightVision = true;
    (cars + 9)->cruiseControl = true;
    (cars + 9)->wheelDrive = 9;
    (cars + 9)->tpms = false;
    (cars + 9)->voice = true;
    (cars + 9)->laneChange = true;
    (cars + 9)->forwardCollision = true;
    (cars + 9)->seatHeater = 9;
    (cars + 9)->steeringHeater = true;
    (cars + 9)->qty = 9;
    (cars + 9)->branch = 4;

    
    (cars + 10)->id = 10;
    (cars + 10)->model = 101010;
    strcpy((cars + 10)->manufacturer, "Genesis");
    (cars + 10)->price = 101010101010.00;
    strcpy((cars + 10)->countryAvailability, "Canada");
    strcpy((cars + 10)->color, "Blue");
    (cars + 10)->milleage = 10101010.00;
    (cars + 10)->used = false;
    (cars + 10)->transmission = true;
    struct engine carEngine10 = {10, 1010};
    (cars + 10)->carEngine = carEngine10;
    struct chassis carChassis10 = {10, 5};
    (cars + 10)->carChassis = carChassis10;
    struct exterior carExterior10 = {10, 10};
    (cars + 10)->carExterior = carExterior10;
    struct dimensions carDimensions10 = {1010.10, 1010.10, 1010.10};
    (cars + 10)->carDimensions = carDimensions10;
    (cars + 10)->airBags = true;
    (cars + 10)->numAirbags = true;
    struct fuel carFuel10 = {1};
    (cars + 10)->carFuel = carFuel10;
    (cars + 10)->hybrid = true;
    (cars + 10)->electric = true;
    (cars + 10)->automatic = false;
    (cars + 10)->nightVision = true;
    (cars + 10)->cruiseControl = true;
    (cars + 10)->wheelDrive = 10;
    (cars + 10)->tpms = false;
    (cars + 10)->voice = true;
    (cars + 10)->laneChange = true;
    (cars + 10)->forwardCollision = true;
    (cars + 10)->seatHeater = 10;
    (cars + 10)->steeringHeater = true;
    (cars + 10)->qty = 10;
    (cars + 10)->branch = 0;

    
    (cars + 11)->id = 11;
    (cars + 11)->model = 111111;
    strcpy((cars + 11)->manufacturer, "Ford");
    (cars + 11)->price = 111111111111.00;
    strcpy((cars + 11)->countryAvailability, "Canada");
    strcpy((cars + 11)->color, "Blue");
    (cars + 11)->milleage = 11111111.00;
    (cars + 11)->used = false;
    (cars + 11)->transmission = true;
    struct engine carEngine11 = {11, 1111};
    (cars + 11)->carEngine = carEngine11;
    struct chassis carChassis11 = {11, 5};
    (cars + 11)->carChassis = carChassis11;
    struct exterior carExterior11 = {10, 11};
    (cars + 11)->carExterior = carExterior11;
    struct dimensions carDimensions11 = {1111.11, 1111.11, 1111.11};
    (cars + 11)->carDimensions = carDimensions11;
    (cars + 11)->airBags = true;
    (cars + 11)->numAirbags = true;
    struct fuel carFuel11 = {1};
    (cars + 11)->carFuel = carFuel11;
    (cars + 11)->hybrid = true;
    (cars + 11)->electric = true;
    (cars + 11)->automatic = false;
    (cars + 11)->nightVision = true;
    (cars + 11)->cruiseControl = true;
    (cars + 11)->wheelDrive = 11;
    (cars + 11)->tpms = false;
    (cars + 11)->voice = true;
    (cars + 11)->laneChange = true;
    (cars + 11)->forwardCollision = true;
    (cars + 11)->seatHeater = 11;
    (cars + 11)->steeringHeater = true;
    (cars + 11)->qty = 11;
    (cars + 11)->branch = 1;

    (cars + 12)->id = 12;
    (cars + 12)->model = 121212;
    strcpy((cars + 12)->manufacturer, "Ford");
    (cars + 12)->price = 121212121212.00;
    strcpy((cars + 12)->countryAvailability, "Canada");
    strcpy((cars + 12)->color, "Blue");
    (cars + 12)->milleage = 12121212.00;
    (cars + 12)->used = false;
    (cars + 12)->transmission = true;
    struct engine carEngine12 = {12, 1212};
    (cars + 12)->carEngine = carEngine12;
    struct chassis carChassis12 = {12, 5};
    (cars + 12)->carChassis = carChassis12;
    struct exterior carExterior12 = {10, 12};
    (cars + 12)->carExterior = carExterior12;
    struct dimensions carDimensions12 = {1212.12, 1212.12, 1212.12};
    (cars + 12)->carDimensions = carDimensions12;
    (cars + 12)->airBags = true;
    (cars + 12)->numAirbags = true;
    struct fuel carFuel12 = {1};
    (cars + 12)->carFuel = carFuel12;
    (cars + 12)->hybrid = true;
    (cars + 12)->electric = true;
    (cars + 12)->automatic = false;
    (cars + 12)->nightVision = true;
    (cars + 12)->cruiseControl = true;
    (cars + 12)->wheelDrive = 12;
    (cars + 12)->tpms = false;
    (cars + 12)->voice = true;
    (cars + 12)->laneChange = true;
    (cars + 12)->forwardCollision = true;
    (cars + 12)->seatHeater = 12;
    (cars + 12)->steeringHeater = true;
    (cars + 12)->qty = 12;
    (cars + 12)->branch = 2;
    (cars + 13)->id = 13;
    (cars + 13)->model = 131313;
    strcpy((cars + 13)->manufacturer, "Nissan");
    (cars + 13)->price = 131313131313.00;
    strcpy((cars + 13)->countryAvailability, "Canada");
    strcpy((cars + 13)->color, "Blue");
    (cars + 13)->milleage = 13131313.00;
    (cars + 13)->used = false;
    (cars + 13)->transmission = true;
    struct engine carEngine13 = {13, 1313};
    (cars + 13)->carEngine = carEngine13;
    struct chassis carChassis13 = {13, 5};
    (cars + 13)->carChassis = carChassis13;
    struct exterior carExterior13 = {10, 13};
    (cars + 13)->carExterior = carExterior13;
    struct dimensions carDimensions13 = {1313.13, 1313.13, 1313.13};
    (cars + 13)->carDimensions = carDimensions13;
    (cars + 13)->airBags = true;
    (cars + 13)->numAirbags = true;
    struct fuel carFuel13 = {1};
    (cars + 13)->carFuel = carFuel13;
    (cars + 13)->hybrid = true;
    (cars + 13)->electric = true;
    (cars + 13)->automatic = false;
    (cars + 13)->nightVision = true;
    (cars + 13)->cruiseControl = true;
    (cars + 13)->wheelDrive = 13;
    (cars + 13)->tpms = false;
    (cars + 13)->voice = true;
    (cars + 13)->laneChange = true;
    (cars + 13)->forwardCollision = true;
    (cars + 13)->seatHeater = 13;
    (cars + 13)->steeringHeater = true;
    (cars + 13)->qty = 13;
    (cars + 13)->branch = 3;
    (cars + 14)->id = 14;
    (cars + 14)->model = 141414;
    strcpy((cars + 14)->manufacturer, "Nissan");
    (cars + 14)->price = 141414141414.00;
    strcpy((cars + 14)->countryAvailability, "Canada");
    strcpy((cars + 14)->color, "Black");
    (cars + 14)->milleage = 14141414.00;
    (cars + 14)->used = false;
    (cars + 14)->transmission = true;
    struct engine carEngine14 = {14, 1414};
    (cars + 14)->carEngine = carEngine14;
    struct chassis carChassis14 = {14, 5};
    (cars + 14)->carChassis = carChassis14;
    struct exterior carExterior14 = {10, 14};
    (cars + 14)->carExterior = carExterior14;
    struct dimensions carDimensions14 = {1414.14, 1414.14, 1414.14};
    (cars + 14)->carDimensions = carDimensions14;
    (cars + 14)->airBags = true;
    (cars + 14)->numAirbags = true;
    struct fuel carFuel14 = {1};
    (cars + 14)->carFuel = carFuel14;
    (cars + 14)->hybrid = true;
    (cars + 14)->electric = true;
    (cars + 14)->automatic = false;
    (cars + 14)->nightVision = true;
    (cars + 14)->cruiseControl = true;
    (cars + 14)->wheelDrive = 14;
    (cars + 14)->tpms = false;
    (cars + 14)->voice = true;
    (cars + 14)->laneChange = true;
    (cars + 14)->forwardCollision = true;
    (cars + 14)->seatHeater = 14;
    (cars + 14)->steeringHeater = true;
    (cars + 14)->qty = 14;
    (cars + 14)->branch = 4;
    
    (cars + 15)->id = 15;
    (cars + 15)->model = 151515;
    strcpy((cars + 15)->manufacturer, "Mazda");
    (cars + 15)->price = 151515151515.00;
    strcpy((cars + 15)->countryAvailability, "Canada");
    strcpy((cars + 15)->color, "Black");
    (cars + 15)->milleage = 15151515.00;
    (cars + 15)->used = false;
    (cars + 15)->transmission = true;
    struct engine carEngine15 = {15, 1515};
    (cars + 15)->carEngine = carEngine15;
    struct chassis carChassis15 = {15, 5};
    (cars + 15)->carChassis = carChassis15;
    struct exterior carExterior15 = {10, 15};
    (cars + 15)->carExterior = carExterior15;
    struct dimensions carDimensions15 = {1515.15, 1515.15, 1515.15};
    (cars + 15)->carDimensions = carDimensions15;
    (cars + 15)->airBags = true;
    (cars + 15)->numAirbags = true;
    struct fuel carFuel15 = {1};
    (cars + 15)->carFuel = carFuel15;
    (cars + 15)->hybrid = true;
    (cars + 15)->electric = true;
    (cars + 15)->automatic = false;
    (cars + 15)->nightVision = true;
    (cars + 15)->cruiseControl = true;
    (cars + 15)->wheelDrive = 15;
    (cars + 15)->tpms = false;
    (cars + 15)->voice = true;
    (cars + 15)->laneChange = true;
    (cars + 15)->forwardCollision = true;
    (cars + 15)->seatHeater = 15;
    (cars + 15)->steeringHeater = true;
    (cars + 15)->qty = 15;
    (cars + 15)->branch = 0;
    
    (cars + 16)->id = 16;
    (cars + 16)->model = 161616;
    strcpy((cars + 16)->manufacturer, "Mazda");
    (cars + 16)->price = 161616161616.00;
    strcpy((cars + 16)->countryAvailability, "Canada");
    strcpy((cars + 16)->color, "Black");
    (cars + 16)->milleage = 16161616.00;
    (cars + 16)->used = true;
    (cars + 16)->transmission = true;
    struct engine carEngine16 = {16, 1616};
    (cars + 16)->carEngine = carEngine16;
    struct chassis carChassis16 = {16, 5};
    (cars + 16)->carChassis = carChassis16;
    struct exterior carExterior16 = {10, 16};
    (cars + 16)->carExterior = carExterior16;
    struct dimensions carDimensions16 = {1616.16, 1616.16, 1616.16};
    (cars + 16)->carDimensions = carDimensions16;
    (cars + 16)->airBags = true;
    (cars + 16)->numAirbags = true;
    struct fuel carFuel16 = {1};
    (cars + 16)->carFuel = carFuel16;
    (cars + 16)->hybrid = true;
    (cars + 16)->electric = true;
    (cars + 16)->automatic = false;
    (cars + 16)->nightVision = true;
    (cars + 16)->cruiseControl = true;
    (cars + 16)->wheelDrive = 16;
    (cars + 16)->tpms = false;
    (cars + 16)->voice = true;
    (cars + 16)->laneChange = true;
    (cars + 16)->forwardCollision = true;
    (cars + 16)->seatHeater = 16;
    (cars + 16)->steeringHeater = true;
    (cars + 16)->qty = 16;
    (cars + 16)->branch = 1;
    
    (cars + 17)->id = 17;
    (cars + 17)->model = 171717;
    strcpy((cars + 17)->manufacturer, "Honda");
    (cars + 17)->price = 171717171717.00;
    strcpy((cars + 17)->countryAvailability, "Canada");
    strcpy((cars + 17)->color, "Black");
    (cars + 17)->milleage = 17171717.00;
    (cars + 17)->used = true;
    (cars + 17)->transmission = true;
    struct engine carEngine17 = {17, 1717};
    (cars + 17)->carEngine = carEngine17;
    struct chassis carChassis17 = {17, 5};
    (cars + 17)->carChassis = carChassis17;
    struct exterior carExterior17 = {10, 17};
    (cars + 17)->carExterior = carExterior17;
    struct dimensions carDimensions17 = {1717.17, 1717.17, 1717.17};
    (cars + 17)->carDimensions = carDimensions17;
    (cars + 17)->airBags = true;
    (cars + 17)->numAirbags = true;
    struct fuel carFuel17 = {1};
    (cars + 17)->carFuel = carFuel17;
    (cars + 17)->hybrid = true;
    (cars + 17)->electric = true;
    (cars + 17)->automatic = false;
    (cars + 17)->nightVision = true;
    (cars + 17)->cruiseControl = true;
    (cars + 17)->wheelDrive = 17;
    (cars + 17)->tpms = false;
    (cars + 17)->voice = true;
    (cars + 17)->laneChange = true;
    (cars + 17)->forwardCollision = true;
    (cars + 17)->seatHeater = 17;
    (cars + 17)->steeringHeater = true;
    (cars + 17)->qty = 17;
    (cars + 17)->branch = 2;
    
    (cars + 18)->id = 18;
    (cars + 18)->model = 181818;
    strcpy((cars + 18)->manufacturer, "Honda");
    (cars + 18)->price = 181818181818.00;
    strcpy((cars + 18)->countryAvailability, "Canada");
    strcpy((cars + 18)->color, "White");
    (cars + 18)->milleage = 18181818.00;
    (cars + 18)->used = true;
    (cars + 18)->transmission = true;
    struct engine carEngine18 = {18, 1818};
    (cars + 18)->carEngine = carEngine18;
    struct chassis carChassis18 = {18, 5};
    (cars + 18)->carChassis = carChassis18;
    struct exterior carExterior18 = {10, 18};
    (cars + 18)->carExterior = carExterior18;
    struct dimensions carDimensions18 = {1818.18, 1818.18, 1818.18};
    (cars + 18)->carDimensions = carDimensions18;
    (cars + 18)->airBags = true;
    (cars + 18)->numAirbags = true;
    struct fuel carFuel18 = {1};
    (cars + 18)->carFuel = carFuel18;
    (cars + 18)->hybrid = true;
    (cars + 18)->electric = true;
    (cars + 18)->automatic = false;
    (cars + 18)->nightVision = true;
    (cars + 18)->cruiseControl = true;
    (cars + 18)->wheelDrive = 18;
    (cars + 18)->tpms = false;
    (cars + 18)->voice = true;
    (cars + 18)->laneChange = true;
    (cars + 18)->forwardCollision = true;
    (cars + 18)->seatHeater = 18;
    (cars + 18)->steeringHeater = true;
    (cars + 18)->qty = 18;
    (cars + 18)->branch = 3;
    
    (cars + 19)->id = 19;
    (cars + 19)->model = 191919;
    strcpy((cars + 19)->manufacturer, "Toyota");
    (cars + 19)->price = 191919191919.00;
    strcpy((cars + 19)->countryAvailability, "Canada");
    strcpy((cars + 19)->color, "White");
    (cars + 19)->milleage = 19191919.00;
    (cars + 19)->used = true;
    (cars + 19)->transmission = true;
    struct engine carEngine19 = {19, 1919};
    (cars + 19)->carEngine = carEngine19;
    struct chassis carChassis19 = {19, 5};
    (cars + 19)->carChassis = carChassis19;
    struct exterior carExterior19 = {10, 19};
    (cars + 19)->carExterior = carExterior19;
    struct dimensions carDimensions19 = {1919.19, 1919.19, 1919.19};
    (cars + 19)->carDimensions = carDimensions19;
    (cars + 19)->airBags = true;
    (cars + 19)->numAirbags = true;
    struct fuel carFuel19 = {1};
    (cars + 19)->carFuel = carFuel19;
    (cars + 19)->hybrid = true;
    (cars + 19)->electric = true;
    (cars + 19)->automatic = false;
    (cars + 19)->nightVision = true;
    (cars + 19)->cruiseControl = true;
    (cars + 19)->wheelDrive = 19;
    (cars + 19)->tpms = false;
    (cars + 19)->voice = true;
    (cars + 19)->laneChange = true;
    (cars + 19)->forwardCollision = true;
    (cars + 19)->seatHeater = 19;
    (cars + 19)->steeringHeater = true;
    (cars + 19)->qty = 19;
    (cars + 19)->branch = 4;
    
    (cars + 20)->id = 20;
    (cars + 20)->model = 202020;
    strcpy((cars + 20)->manufacturer, "Toyota");
    (cars + 20)->price = 202020202020.00;
    strcpy((cars + 20)->countryAvailability, "Canada");
    strcpy((cars + 20)->color, "White");
    (cars + 20)->milleage = 20202020.00;
    (cars + 20)->used = true;
    (cars + 20)->transmission = true;
    struct engine carEngine20 = {20, 2020};
    (cars + 20)->carEngine = carEngine20;
    struct chassis carChassis20 = {20, 5};
    (cars + 20)->carChassis = carChassis20;
    struct exterior carExterior20 = {10, 20};
    (cars + 20)->carExterior = carExterior20;
    struct dimensions carDimensions20 = {2020.20, 2020.20, 2020.20};
    (cars + 20)->carDimensions = carDimensions20;
    (cars + 20)->airBags = true;
    (cars + 20)->numAirbags = true;
    struct fuel carFuel20 = {1};
    (cars + 20)->carFuel = carFuel20;
    (cars + 20)->hybrid = true;
    (cars + 20)->electric = true;
    (cars + 20)->automatic = false;
    (cars + 20)->nightVision = true;
    (cars + 20)->cruiseControl = true;
    (cars + 20)->wheelDrive = 20;
    (cars + 20)->tpms = false;
    (cars + 20)->voice = true;
    (cars + 20)->laneChange = true;
    (cars + 20)->forwardCollision = true;
    (cars + 20)->seatHeater = 20;
    (cars + 20)->steeringHeater = true;
    (cars + 20)->qty = 20;
    (cars + 20)->branch = 0;
    
    (cars + 21)->id = 21;
    (cars + 21)->model = 212121;
    strcpy((cars + 21)->manufacturer, "Toyota");
    (cars + 21)->price = 212121212121.00;
    strcpy((cars + 21)->countryAvailability, "Canada");
    strcpy((cars + 21)->color, "White");
    (cars + 21)->milleage = 21212121.00;
    (cars + 21)->used = true;
    (cars + 21)->transmission = true;
    struct engine carEngine21 = {21, 2121};
    (cars + 21)->carEngine = carEngine21;
    struct chassis carChassis21 = {21, 5};
    (cars + 21)->carChassis = carChassis21;
    struct exterior carExterior21 = {10, 21};
    (cars + 21)->carExterior = carExterior21;
    struct dimensions carDimensions21 = {2121.21, 2121.21, 2121.21};
    (cars + 21)->carDimensions = carDimensions21;
    (cars + 21)->airBags = true;
    (cars + 21)->numAirbags = true;
    struct fuel carFuel21 = {1};
    (cars + 21)->carFuel = carFuel21;
    (cars + 21)->hybrid = true;
    (cars + 21)->electric = true;
    (cars + 21)->automatic = false;
    (cars + 21)->nightVision = true;
    (cars + 21)->cruiseControl = true;
    (cars + 21)->wheelDrive = 21;
    (cars + 21)->tpms = false;
    (cars + 21)->voice = true;
    (cars + 21)->laneChange = true;
    (cars + 21)->forwardCollision = true;
    (cars + 21)->seatHeater = 21;
    (cars + 21)->steeringHeater = true;
    (cars + 21)->qty = 21;
    (cars + 21)->branch = 1;
    
    (cars + 22)->id = 22;
    (cars + 22)->model = 222222;
    strcpy((cars + 22)->manufacturer, "Kia");
    (cars + 22)->price = 222222222222.00;
    strcpy((cars + 22)->countryAvailability, "Canada");
    strcpy((cars + 22)->color, "White");
    (cars + 22)->milleage = 22222222.00;
    (cars + 22)->used = true;
    (cars + 22)->transmission = true;
    struct engine carEngine22 = {22, 2222};
    (cars + 22)->carEngine = carEngine22;
    struct chassis carChassis22 = {22, 5};
    (cars + 22)->carChassis = carChassis22;
    struct exterior carExterior22 = {10, 22};
    (cars + 22)->carExterior = carExterior22;
    struct dimensions carDimensions22 = {2222.22, 2222.22, 2222.22};
    (cars + 22)->carDimensions = carDimensions22;
    (cars + 22)->airBags = true;
    (cars + 22)->numAirbags = true;
    struct fuel carFuel22 = {1};
    (cars + 22)->carFuel = carFuel22;
    (cars + 22)->hybrid = true;
    (cars + 22)->electric = true;
    (cars + 22)->automatic = false;
    (cars + 22)->nightVision = true;
    (cars + 22)->cruiseControl = true;
    (cars + 22)->wheelDrive = 22;
    (cars + 22)->tpms = false;
    (cars + 22)->voice = true;
    (cars + 22)->laneChange = true;
    (cars + 22)->forwardCollision = true;
    (cars + 22)->seatHeater = 22;
    (cars + 22)->steeringHeater = true;
    (cars + 22)->qty = 22;
    (cars + 22)->branch = 2;
    
    (cars + 23)->id = 23;
    (cars + 23)->model = 232323;
    strcpy((cars + 23)->manufacturer, "Kia");
    (cars + 23)->price = 232323232323.00;
    strcpy((cars + 23)->countryAvailability, "Canada");
    strcpy((cars + 23)->color, "White");
    (cars + 23)->milleage = 23232323.00;
    (cars + 23)->used = false;
    (cars + 23)->transmission = true;
    struct engine carEngine23 = {23, 2323};
    (cars + 23)->carEngine = carEngine23;
    struct chassis carChassis23 = {23, 5};
    (cars + 23)->carChassis = carChassis23;
    struct exterior carExterior23 = {10, 23};
    (cars + 23)->carExterior = carExterior23;
    struct dimensions carDimensions23 = {2323.23, 2323.23, 2323.23};
    (cars + 23)->carDimensions = carDimensions23;
    (cars + 23)->airBags = true;
    (cars + 23)->numAirbags = true;
    struct fuel carFuel23 = {1};
    (cars + 23)->carFuel = carFuel23;
    (cars + 23)->hybrid = true;
    (cars + 23)->electric = true;
    (cars + 23)->automatic = false;
    (cars + 23)->nightVision = true;
    (cars + 23)->cruiseControl = true;
    (cars + 23)->wheelDrive = 23;
    (cars + 23)->tpms = false;
    (cars + 23)->voice = true;
    (cars + 23)->laneChange = true;
    (cars + 23)->forwardCollision = true;
    (cars + 23)->seatHeater = 23;
    (cars + 23)->steeringHeater = true;
    (cars + 23)->qty = 23;
    (cars + 23)->branch = 3;
    (cars + 24)->id = 24;
    (cars + 24)->model = 242424;
    strcpy((cars + 24)->manufacturer, "Kia");
    (cars + 24)->price = 242424242424.00;
    strcpy((cars + 24)->countryAvailability, "Canada");
    strcpy((cars + 24)->color, "White");
    (cars + 24)->milleage = 24242424.00;
    (cars + 24)->used = true;
    (cars + 24)->transmission = true;
    struct engine carEngine24 = {24, 2424};
    (cars + 24)->carEngine = carEngine24;
    struct chassis carChassis24 = {24, 5};
    (cars + 24)->carChassis = carChassis24;
    struct exterior carExterior24 = {10, 24};
    (cars + 24)->carExterior = carExterior24;
    struct dimensions carDimensions24 = {2424.24, 2424.24, 2424.24};
    (cars + 24)->carDimensions = carDimensions24;
    (cars + 24)->airBags = true;
    (cars + 24)->numAirbags = true;
    struct fuel carFuel24 = {1};
    (cars + 24)->carFuel = carFuel24;
    (cars + 24)->hybrid = true;
    (cars + 24)->electric = true;
    (cars + 24)->automatic = false;
    (cars + 24)->nightVision = true;
    (cars + 24)->cruiseControl = true;
    (cars + 24)->wheelDrive = 24;
    (cars + 24)->tpms = false;
    (cars + 24)->voice = true;
    (cars + 24)->laneChange = true;
    (cars + 24)->forwardCollision = true;
    (cars + 24)->seatHeater = 24;
    (cars + 24)->steeringHeater = true;
    (cars + 24)->qty = 24;
    (cars + 24)->branch = 4;
    while (1)
    { // aways run the menu
        menu(branches, cars);
    }
    // malloc heap ONLY during runtime
    // no code no data
    // once code at bottom, struct removed from heap
    free(branches);
    free(cars);

    return 0;
}

void menu(struct branch *branches, struct car *cars)
{
    // random exchange rates
    exchangeCanada = drand(1.2, 1.4);
    exchangeMexico = drand(17.0, 19.0);
    int selection;      // menu selection
    char *trimText[10]; // trim toggle text
    if (trim)
    {
        *trimText = "Advanced";
    }
    else
    {
        *trimText = "Regular";
    }
    printf("Welcome to Matthew Gruman Cars\n");
    printf("Canada Exchange: %.2f\n", exchangeCanada);
    printf("Mexico Exchange: %.2f\n", exchangeMexico);
    printf("Please select an option:\n");
    printf("********************\n");
    printf("1. Show Branch 1\n");
    printf("2. Show Branch 2\n");
    printf("3. Show Branch 3\n");
    printf("4. Show Branch 4\n");
    printf("5. Show Branch 5\n");
    printf("------------------\n");
    printf("6. Show all cars\n");
    printf("7. Search cars\n");
    printf("8. Transfer cars\n");
    printf("9. Toggle Current Trim: %s\n", *trimText);
    scanf("%d", &selection);
    int searchSelection;
    char searchTerm[20];
    int searchInt;
    int range[2];
    if (selection == 1 || selection == 2 || selection == 3 || selection == 4 || selection == 5)
    {
        int sel;                                      // show branches
        showBranches(selection - 1, branches, false); // public info

        printf("Please select an option:\n");
        printf("********************\n");
        printf("1. Show Cars\n");
        printf("2. Private Info\n");
        printf("3. Buy Car\n");  // remove from inventory
        printf("4. Sell Car\n"); // add to inventory
        scanf("%d", &sel);
        if (sel == 1)
        { // show cards by branch
            carsByBranch(cars, selection - 1);
        }
        else if (sel == 2)
        { // show private info

            showBranches(selection - 1, branches, true); // public info
        }
        else if (sel == 3)
        { // remove from inventory
            int id;
            printf("Please enter a car ID:\n");
            scanf("%d", &id);
            removeCar(&cars, id);
        }
        else if (sel == 4)
        { // add to inventory
            enterCar(&cars, selection - 1);
        }
    }
    else if (selection == 6)
    { // show all cars
        showCars(cars, 0, "", "", range);
    }
    else if (selection == 7)
    { // search cars
        printf("1. By Model (int)\n");
        printf("2. By Manufacturer (str)\n");
        printf("3. Show All Used\n");
        printf("4. Show All New\n");
        printf("5. By Milleage Range (dbl dbl)\n");
        printf("6. By Color (str)\n");
        printf("7. By Country (str)\n");
        scanf("%d", &searchSelection);
        if (searchSelection == 1)
        {
            printf("Please enter a number:\n");
            scanf("%d", &searchInt);
        }
        else if (searchSelection == 2)
        {
            printf("Please enter a word:\n");
            scanf_s("%s", searchTerm);
        }
        else if (searchSelection == 3)
        {
            searchInt = 0;
        }
        else if (searchSelection == 4)
        {
            searchInt = 1;
        }
        else if (searchSelection == 5)
        {
            int min;
            int max;
            printf("Please enter min and max separated by a space:\n");
            scanf("%d %d", &min, &max);
            range[0] = min;
            range[1] = max;
        }
        else if (searchSelection == 6)
        {
            printf("Please enter a word:\n");
            scanf("%s", searchTerm);
        }
        else if (searchSelection == 7)
        {
            printf("Please enter a word:\n");
            scanf("%s", searchTerm);
        }
        showCars(cars, searchSelection, searchTerm, searchInt, range);
    }
    else if (selection == 8)
    { // transfer car
        int one, two;
        printf("Please enter one car ID and one new branch, separated by a space:\n");
        scanf("%d %d", &one, &two);
        transferCar(cars, one, two);
    }
    else if (selection == 9)
    { // toggle trim
        trim = !trim;
    }
}

void removeCar(struct car **cars, int id)
{
    for (int i = 0; i < NUM_CARS; i++)
    {
        if ((*cars + i)->id == id)
        {
            (*cars + i)->qty = (*cars + i)->qty - 1;
        }
    }
}

void transferCar(struct car *cars, int id, int branch)
{ // transfer from one branch to another
    for (int i = 0; i < NUM_CARS; i++)
    {
        if ((cars + i)->id == id)
        {
            (cars + i)->branch = branch;
        }
    }
}
void enterCar(struct car **cars, int branch)
{ // sell car
    int tempInt1, tempInt2;
    double tempDbl1, tempDbl2, tempDbl3;
    (*cars + CURRENT_CAR_INDEX)->id = CURRENT_CAR_INDEX;
    printf("Model (int):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->model);
    printf("Manufacturer (str):\n");
    scanf("%s", (*cars + CURRENT_CAR_INDEX)->manufacturer);

    printf("Price (dbl):\n");
    scanf("%lf", &(*cars + CURRENT_CAR_INDEX)->price);
    printf("Country (str):\n");
    scanf("%s", (*cars + CURRENT_CAR_INDEX)->countryAvailability);
    
    printf("Color (str):\n");
    scanf("%s", (*cars + CURRENT_CAR_INDEX)->color);
    
    printf("Milleage (dbl):\n");
    scanf("%lf", &(*cars + CURRENT_CAR_INDEX)->milleage);
    
    printf("Used? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->used);
    
    printf("Automatic? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->automatic);
    
    printf("Engine specs (two ints) separated by a space.\n");
    scanf("%d %d", &tempInt1, &tempInt2);
    struct engine carEngine = {tempInt1, tempInt2};
    (*cars + CURRENT_CAR_INDEX)->carEngine = carEngine;
    
    printf("Chassis specs (two ints) separated by a space.\n");
    
    scanf("%d %d", &tempInt1, &tempInt1);
    struct chassis carChassis = {tempInt1, tempInt1};
    (*cars + CURRENT_CAR_INDEX)->carChassis = carChassis;

    printf("Exterior specs (two ints) separated by a space.\n");
    
    scanf("%d %d", &tempInt1, &tempInt2);
    struct exterior carExterior = {tempInt1, tempInt2};
    (*cars + CURRENT_CAR_INDEX)->carExterior = carExterior;

    printf("Exterior Dimensions (three doubles) separater by a space.\n");
    
    scanf("%lf %lf %lf", &tempDbl1, &tempDbl2, &tempDbl3);
    struct dimensions carDimensions = {tempDbl1, tempDbl2, tempDbl3};
    (*cars + CURRENT_CAR_INDEX)->carDimensions = carDimensions;

    printf("Airbags? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->airBags);
    printf("Automatic? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->numAirbags);
    printf("Fuel Type (int):\n");
    scanf("%d", &tempInt1);
    struct fuel carFuel = {tempInt1};
    (*cars + CURRENT_CAR_INDEX)->carFuel = carFuel;
    printf("Hybrid? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->hybrid);
    printf("Electric? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->electric);
    printf("Automatic? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->automatic);
    printf("Night Vision? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->nightVision);
    printf("Cruise Control? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->cruiseControl);
    printf("Wheel Drive: (int)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->wheelDrive);
    printf("TPMS? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->tpms);
    printf("Voice control? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->voice);
    printf("Auto Lane Change? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->laneChange);
    printf("Forward Collision? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->forwardCollision);
  
    printf("Seat Heaters: (int):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->seatHeater);
    printf("Steering Wheel Heater? (1 (true) /0 (false)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->steeringHeater);
    printf("Quantity? (int)):\n");
    scanf("%d", &(*cars + CURRENT_CAR_INDEX)->qty);
    (*cars + CURRENT_CAR_INDEX)->branch = branch;

    CURRENT_CAR_INDEX++;
    NUM_CARS++;
}

void printRow(struct car *cars, int i)
{ // print row for cars if there's at least 1
    if ((cars + i)->qty > 0)
    {
        double newPrice = (cars + i)->price;
        printf("%d|", (cars + i)->id);
        printf("%d|", (cars + i)->model);
        printf("%s|", (cars + i)->manufacturer);
        if ((cars + i)->transmission || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if (strcmp((cars + i)->countryAvailability, "Canada") == 0)
        { // in Canada
            newPrice *= exchangeCanada;
            if (strcmp((cars + i)->manufacturer, "Honda") == 0)
            {
                newPrice *= 0.98;
            }
        }
        else if (strcmp((cars + i)->countryAvailability, "Mexico") == 0)
        { // in Mexico
            newPrice *= exchangeMexico;
            if (strcmp((cars + i)->manufacturer, "Volvo") == 0)
            {
                if ((cars + i)->milleage > 60000)
                {
                    newPrice *= 0.97;
                }
            }
        }
        else
        { // usa
            if (strcmp((cars + i)->manufacturer, "Volvo") == 0 || strcmp((cars + i)->manufacturer, "BMW") == 0 || strcmp((cars + i)->manufacturer, "Audi") == 0 || strcmp((cars + i)->manufacturer, "Bentley") == 0 || strcmp((cars + i)->manufacturer, "Ferrari") == 0)
            {
                newPrice *= 0.975;
            }
        }
        printf("%.2lf|", newPrice);
        printf("%s|", (cars + i)->countryAvailability);
        printf("%s|", (cars + i)->color);
        printf("%.2lf|", (cars + i)->milleage);
        if ((cars + i)->used)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        printf("%d/%d|", (cars + i)->carEngine.type, (cars + i)->carEngine.horsepower);
        printf("%d/%d|", (cars + i)->carChassis.model, (cars + i)->carChassis.type);
        printf("%d/%d|", (cars + i)->carExterior.preset, (cars + i)->carExterior.preset);
        printf("%.2lf/%.2lf/%.2lf|", (cars + i)->carDimensions.height, (cars + i)->carDimensions.width, (cars + i)->carDimensions.length);
        if ((cars + i)->airBags || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        printf("%d|", (cars + i)->numAirbags);
        printf("%d|", (cars + i)->carFuel.type);
        if ((cars + i)->hybrid || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->electric || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->automatic || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->nightVision || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->cruiseControl || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        printf("%d|", (cars + i)->wheelDrive);
        if ((cars + i)->hillAssist || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->tpms || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->voice || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->laneChange || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        if ((cars + i)->forwardCollision || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        printf("%d|", (cars + i)->seatHeater);
        if ((cars + i)->steeringHeater || trim)
        {
            printf("Yes|");
        }
        else
        {
            printf("No|");
        }
        printf("%d|", (cars + i)->qty);
        printf("%d\n", (cars + i)->branch);
    }
}

void carsByBranch(struct car *cars, int branch)
{ // show cars by branch
    printf("ID|Mod|Man|Aut|$Pr|Cou|Col|Use|Mil|Tra|Eng|Cha|Ext|Dim|Air|Fue|Hyb|Ele|Aut|Ngh|Cru|WD|TMP|Voi|Lan|For|Hea|Ste|Qty|Bra\n");
    for (int i = 0; i < NUM_CARS; i++)
    {
        if ((cars + i)->branch == branch)
        {
            printRow(cars, i);
        }
    }
}

void showBranches(int branchNum, struct branch *branches, bool private)
{ // show branch info
    char *temp[20];
    if (private)
    {
        *temp = "Private";
    }
    else
    {
        *temp = "Public";
    }
    printf("%s Information\n", *temp);
    printf("Name: %s\n", (branches + branchNum)->name);
    printf("Address: %s\n", (branches + branchNum)->address);
    printf("Postal Code: %s\n", (branches + branchNum)->postalCode);
    printf("Phone: %d\n", (branches + branchNum)->phoneNumber);
    printf("Email: %s\n", (branches + branchNum)->email);
    printf("Manager: %s\n", (branches + branchNum)->managerName);
    if (private)
    {
        printf("Private Information\n");
        printf("Manager Phone: %d\n", (branches + branchNum)->managerPhoneNumber);
        printf("Manager Cell: %d\n", (branches + branchNum)->managerCellNumber);
        printf("Manger Address: %s\n", (branches + branchNum)->managerAddress);
        printf("Manger Email: %s\n", (branches + branchNum)->managerEmail);
        printf("Manger Employment Data: %d-%d-%d\n", (branches + branchNum)->managerEmploymentDate.day, (branches + branchNum)->managerEmploymentDate.month, (branches + branchNum)->managerEmploymentDate.year);
        printf("Manager Experience: %d\n", (branches + branchNum)->managerExperience);
        printf("Finanace Manager: %s\n", (branches + branchNum)->financeName);
        printf("Finanace Manager Phone: %d\n", (branches + branchNum)->financePhone);
        printf("Finanace Manager Cell: %d\n", (branches + branchNum)->financeCell);
        printf("Finanace Manger Address: %s\n", (branches + branchNum)->financeAddress);
        printf("Finanace Manger Employment Data: %d-%d-%d\n", (branches + branchNum)->financeEmploymentDate.day, (branches + branchNum)->financeEmploymentDate.month, (branches + branchNum)->financeEmploymentDate.year);
        printf("Finanace Manager Experience: %d\n", (branches + branchNum)->financeExperience);
        printf("Total Cars: %d\n", (branches + branchNum)->numCars);
    }
}

void showCars(struct car *cars, int searchType, char *searchWord, int searchInt, int minMax[])
{ // show all cars + search engine
    printf("ID|Mod|Man|Aut|$Pr|Cou|Col|Use|Mil|Tra|Eng|Cha|Ext|Dim|Air|Fue|Hyb|Ele|Aut|Ngh|Cru|WD|TMP|Voi|Lan|For|Hea|Ste|Qty|Bra\n");

    for (int i = 0; i < NUM_CARS; i++)
    {
        if (searchType == 1)
        {
            if ((cars + i)->model == searchInt)
            { // search by model

                printRow(cars, i);
            }
        }
        else if (searchType == 2)
        {
            if (strcmp((cars + i)->manufacturer, searchWord) == 0)
            { // search by model
                printRow(cars, i);
            }
        }
        else if (searchType == 3)
        {
            if ((cars + i)->used)
            { // search by used

                printRow(cars, i);
            }
        }
        else if (searchType == 4)
        {
            if ((cars + i)->used)
            { // search by new
            }
            else
            {
                printRow(cars, i);
            }
        }
        else if (searchType == 5)
        {
            if ((cars + i)->milleage > minMax[0] && (cars + i)->milleage < minMax[1])
            { // milleage range

                printRow(cars, i);
            }
        }

        else if (searchType == 6)
        {
            if (strcmp((cars + i)->color, searchWord) == 0)
            { // search by color

                printRow(cars, i);
            }
        }

        else if (searchType == 7)
        {
            if (strcmp((cars + i)->countryAvailability, searchWord) == 0)
            { // search by model

                printRow(cars, i);
            }
        }
        else
        { // show all
            printRow(cars, i);
        }
    }
    printf("\n\n");
}

double drand(double low, double high)
{ // generate random double for exchange rate
    return ((double)rand() * (high - low)) / (double)RAND_MAX + low;
}
