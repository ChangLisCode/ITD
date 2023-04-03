//
//  main.c
//  158
//
//  Created by Chang on 2023-03-22.
//  Project: an application for grocery stores and their inventories

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// structure define
struct Product {
  char name[100];
  char name_encryption[100];
  char category[10];
  char manufacturer[100];
    
  float purchased_price;
  float sale_price;
  float final_price;
    
  int quantity;
  int purchased_date[3];
  int production_date[3];
  int expiry_date[3];
    
  char barcode[17];
  char currency[10];
};

// function define
void inventory_define(char *string);
void import_information(int new_product, int date[]);
char barcode_generate(char *name, char *group, int purchased_date, struct Product* products);

char* encryption_method_1(char *string);
char encryption_method_2(char* string);
float encryption_method_3(float value);
char encryption_method_4(char *string);
int encryption_method_5(int purchased_date[]);
char encryption_method_6(char *string);
char encryption_method_7(char *string);
int encryption_format(char value);

void price_update(int date[], struct Product* products, int num);
int days_between_dates(int* start_date, int* end_date);

int main(void) {
    
    int start_question, new_product;
    int* date = (int*)malloc(3 * sizeof(int));
    
    printf("Hi, How are you today!\nPlease input the date of today by the format of (yyyy-mm-dd). Thanks.\n");
    scanf("%d%d%d", &date[0], &date[1], &date[2]);
    
    printf("\nWould you like to import any item to your store?\nYes, please input[1]. \nNo, please input[0]\n[1]\n[0]\n");
    scanf("%d", &start_question);
    
    if(start_question == 1){
        printf("\nHow many product will you import to storage?\n");
        scanf("%d", &new_product);
        import_information(new_product, date);
    }
    free(date);
    printf("\n\n\n");
    return 0;
}

void import_information(int new_product, int date[]){
    
    struct Product *products[new_product];
    
    for (int i = 0; i < new_product; i++) {
        
        products[i] = (struct Product*) malloc(sizeof(struct Product));
        
        printf("\nEnter the name of product %d: \n", i+1);
        scanf("%s", products[i]->name);
        
        strcpy(products[i]->name_encryption, encryption_method_1(products[i]->name));
        
        printf("\nEnter the category of product %d: ", i+1);
        printf("\nPlease choose category type:\nGroup [A]: Meat\nGroup [B]: Deli\nGroup [C]: Pharmacy\nGroup [D]: Seafood\nGroup [E]: Beverage\nGroup [F]: Canned\nGroup [G]: Jarred\nGroup [H]: Dry Food\nGroup [I]: Dairy\nGroup [J]: Bakery\nGroup [K]: Personal Care\nGroup [L]: Paper Goods\n");
        scanf("%s", products[i]->category);
        
        printf("\nEnter the company/manufacturer name of product %d: \n", i+1);
        scanf("%s", products[i]->manufacturer);
        
        printf("\nEnter the purchased price of product %d: \n", i+1);
        scanf("%f", &products[i]->purchased_price);
        
        printf("\nEnter the sale price of product %d: \n", i+1);
        scanf("%f", &products[i]->sale_price);
        
        printf("\nEnter the quantity of product %d: \n", i+1);
        scanf("%d", &products[i]->quantity);
        
        printf("\nEnter the purchased date of product %d (yyyy-mm-dd): \n", i+1);
        scanf("%d%d%d", &products[i]->purchased_date[0], &products[i]->purchased_date[1], &products[i]->purchased_date[2]);
        
        printf("\nEnter the production date of product %d (yyyy-mm-dd): \n", i+1);
        scanf("%d%d%d", &products[i]->production_date[0], &products[i]->production_date[1], &products[i]->production_date[2]);
        
        printf("\nEnter the expiry date of product %d (yyyy-mm-dd): \n", i+1);
        scanf("%d%d%d", &products[i]->expiry_date[0], &products[i]->expiry_date[1], &products[i]->expiry_date[2]);
        
        printf("\nEnter the currency of the country for product %d: \n", i+1);
        scanf("%s", products[i]->currency);
        
//      calculate barcode
        barcode_generate(products[i]->name, products[i]->category, products[i]->purchased_date[0], *products);        
    }
    
    //    show all the product list
    printf("\nProduct Information:\n");
    
    for (int i = 0; i < new_product; i++) {
        printf("Product name: %s\n, Category: %s\n, Manufacturer: %s\n, Purchased Price: %.2f\n, Currency: %s\n, Sale Price: %.2f\n, Quantity: %d\n, Purchased Date: %d%d%d\n, Production Date: %d%d%d\n, Expiry Date: %d%d%d\n, Barcode: %s\n\n",
               products[i]->name, products[i]->category,products[i]->manufacturer,  products[i]->purchased_price,  products[i]->currency,  products[i]->sale_price, products[i]->quantity,
               products[i]->purchased_date[0], products[i]->purchased_date[1], products[i]->purchased_date[2], products[i]->production_date[0], products[i]->production_date[1], products[i]->production_date[2],  products[i]->expiry_date[0],products[i]->expiry_date[1],products[i]->expiry_date[2],
               products[i]->barcode);}
    
// shopping part
    int choice;
    printf("new product information has been import successfully. Will you leave or go to shoping?\n[1] I want to leave\n[2] I will have shopping\n\n");
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("Thanks for your job, have a nice day!\n\n");
    }
    else{
//      go to shopping part
        int i, j, amount;
        float balance = 0, balance_original = 0, save_money = 0;
        
        printf("\nWelcome to our market for shopping!\nhow many products would you like to purchase?\n");
        scanf("%d", &amount);
        
        struct Product *shopping_list[amount];
        for (int i = 0; i < amount; i++) {
            
            shopping_list[i] = (struct Product*) malloc(sizeof(struct Product));
            
            /*
             in the actual shopping, barcode is from scanning equipment, in this program we need input it mannually.
             and the barcode is stored in array by pointer.
             */
            printf("\ninput the barcode of purchased product.\n");
            scanf("%s", shopping_list[i]->barcode);
        }
        
/*
 update the price based on date, which is calculate for the gap to expired date
 pass the structure to the price update function
 */
        printf("\nbarcode is received successfully. \nList:\n");
        for (i=0; i<amount; i++) {
            printf("%s\n", shopping_list[i]->barcode);
            for (int j=0; j<new_product; j++) {
                price_update(date, products[i],j);
            }
        }
              
//    get and calculate the price
        for (i=0; i < amount; i++) {
            for (j = 0; j < 36; j++) {
                if (strcmp(shopping_list[i]->barcode, products[j]->barcode) == 0) {
                    strcpy(shopping_list[i]->name, products[j]->name);
                    shopping_list[i]->sale_price = products[j]->sale_price;
                    shopping_list[i]->final_price = products[j]->final_price;
                    break;
                }
            }
            balance += shopping_list[i]->final_price;
            balance_original += shopping_list[i]->sale_price;
        }
        save_money = balance_original - balance;
        
//    receipt print
        printf("\n\n---------supermarket receipt---------\n\n");
        printf("-----------------------------------------\n");
        printf("product barcode | product name | orginal price | disaccount\n");
        for (i=0; i<amount; i++) {
            printf("%s       %s            %.2f           %.2f\n",shopping_list[i]->barcode, shopping_list[i]->name, shopping_list[i]->sale_price,
                   shopping_list[i]->final_price);
            printf("-----------------------------------------\n");
        }
        printf("\n\n");
        printf("total money you saved: %.2f\n", save_money);
        printf("You need pay after disaccount. %.2f\n\n", balance);
        printf("-----------------------------------------\n\n");
        printf("Thanks for shopping at our store!\n");
        
//  free the memory of shopping list
        for (i = 0; i < amount; i++) {
            free(shopping_list[i]);
        }
//        free(shopping_list);
        }
//  free the memeory of products
        for (int i = 0; i < new_product; i++) {
        free(products[i]);
        }
//        free(products);
}
    
//  encryption part
// use name / group / purchased date to generate the barcode, the barcode is 16 digits
char barcode_generate(char *name, char *group, int purchased_date, struct Product* products){
    
    int temp1 = *encryption_method_1(name);
    int temp2 = encryption_method_2(group);
    int temp3 = encryption_method_5(&purchased_date);
    
    char str1[10];
    char str2[10];
    char str3[10];
    char *barcode = malloc(17 * sizeof(char));
    
    sprintf(str1, "%d", temp1);
    sprintf(str2, "%d", temp2);
    sprintf(str3, "%d", temp3);
    
    strcpy(barcode, str1);
    strcat(barcode, str2);
    strcat(barcode, str3);

    if (barcode == NULL) {
        printf("\nBarcode generation failed\n");
        return 1;
    }
    
//    strcpy(barcode, encryption_format(*barcode));
    printf("\nBarcode is generated automatically: %s\n", barcode);
    strcpy(products->barcode, barcode);
    
    free(barcode);
    return *barcode;
}

//  for name and manufacture
char* encryption_method_1(char string[]){
    static char encrypted[100];
      int i;
      for (i = 0; i < strlen(string); i++) {
        encrypted[i] = string[i] + 20230322;
      }
      encrypted[i] = '\0';
      return encrypted;
}

//  for category
char encryption_method_2(char *string){

    int encrypted = 0;
    int ascii_code = (int)*string;
    
    switch(ascii_code){
        case 65:
            encrypted = *encryption_method_1("meat");
            break;
        case 66:
            encrypted = *encryption_method_1("Deli");
            break;
        case 67:
            encrypted = *encryption_method_1("Pharmacy");
            break;
        case 68:
            encrypted = *encryption_method_1("Seafood");
            break;
        case 69:
            encrypted = *encryption_method_1("Beverage");
            break;
        case 70:
            encrypted = *encryption_method_1("Canned");
            break;
        case 71:
            encrypted = *encryption_method_1("Jarred");
            break;
        case 72:
            encrypted = *encryption_method_1("Dry Food");
            break;
        case 73:
            encrypted = *encryption_method_1("Dairy");
            break;
        case 74:
            encrypted = *encryption_method_1("Bakery");
            break;
        case 75:
            encrypted = *encryption_method_1("Personal Care");
            break;
        case 76:
            encrypted = *encryption_method_1("Paper Goods");
            break;
    }
    return encrypted;
}

//  for price, include purchased price, sale price
float encryption_method_3(float value){
    int key = 20230322;
    float encrypted = (int)(value * 1000000) ^ key;
    return encrypted;
}

char encryption_method_4(char *string){
    int encrypted = 0;
    encrypted = *encryption_method_1(string) + 20230322;
    return encrypted;
}
// encryption purchased date
int encryption_method_5(int purchased_date[]){
        int key = 25;
        int encrypted = purchased_date[0] * key + purchased_date[1] * key + purchased_date[2] * key;
        return encrypted;
}

//char encryption_method_6(char *string){
//    int encrypted = 0;
//    int ascii_code = ((int)*string) * 100 + 23;
//    return encrypted;
//}
//
//char encryption_method_7(char *string){
//    int encrypted = 0;
//    int ascii_code = ((int)*string) + 23;
//    return encrypted;
//}

// format the encryption result, first verify whether the code is 16 digits, if not, fill with 0 after last digit, till total digit is 12.
int encryption_format(char encryption){
    int num = (int)encryption;
    int i, temp1= 0 , temp2 = 0, formatted_encryption = 0;
    int count = 0;
//    verify the digits
    while (num != 0) {
        count++;
        num /= 10;
    }
//    format the digits
    if((count < 16) && (count >0)){
//    fill the lack position with 0
        for (i=0; i< 16-count; i++) {
            formatted_encryption *= 10;
        };
    }
    else if(count == 16){
        formatted_encryption = encryption;
    }
    else {
//  cut the digits which is more than 16, add together.
        for (i=0; i< (count - 16); i++) {
            temp1 = encryption / 10;
            temp2 += (encryption % 10) * (10 ^ i);
        };
        formatted_encryption = temp1 + temp1;
        
//  verify the final result meet requirement
        encryption_format(formatted_encryption);
    }
    return formatted_encryption;
}

int days_between_dates(int* start_date, int* end_date) {
    struct tm start_tm = {0};
    struct tm end_tm = {0};
    
    // Set start date
    start_tm.tm_year = *(start_date) - 1900; // year since 1900
    start_tm.tm_mon = *(start_date + 1) - 1; // month (0-11)
    start_tm.tm_mday = *(start_date + 2); // day of the month (1-31)
    
    // Set end date
    end_tm.tm_year = *(end_date) - 1900;
    end_tm.tm_mon = *(end_date + 1) - 1;
    end_tm.tm_mday = *(end_date + 2);
    
    // Calculate difference in days
    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);
    int diff_days = difftime(end_time, start_time) / (60 * 60 * 24);
    
    return diff_days;
}

// base on promotion rule, update the sale price
void price_update(int date[], struct Product* products, int num){
    int group=0, durable_life_period = 0, days_passed = 0;
    float new_price = 0;
    float regular_price = products->sale_price;
    char *tag;
 
    const char* categories[] = {"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};
    
    // find index of category in lookup table

    for (int i = 1; i <= 12; i++) {
        if (strcmp(products->category, categories[i]) == 0) {
            group = i;
            break;
        }
    }
    group = group + 64;
//    printf("value of group: %d\n", group);
    
//    calculate the date of expired shelflife
    days_passed = days_between_dates(date, products->production_date);
    durable_life_period = days_between_dates(products->expiry_date, products->production_date);

//    printf("value of day pass is %d\n, shelf life is %d\n", days_passed, durable_life_period);
    
    
    if (group >=65 && group <=68){
        
        if ((days_passed >= 0.5 * durable_life_period)||(days_passed < 0.65 * durable_life_period)) {
            printf("This item has a yellow Tag.\n");
            tag = "Yellow";
            new_price = regular_price *0.9;
        }
        
        else  if ((days_passed >= 0.65 * durable_life_period)||(days_passed < 0.75 * durable_life_period)){
            printf("This item has a green Tag.\n");
            tag = "Green";
            new_price = regular_price *0.75;
        }
        
        else  if ((days_passed >= 0.75 * durable_life_period)||(days_passed < 0.95 * durable_life_period)) {
            printf("This item has a red Tag.\n");
            tag = "Red";
            new_price = regular_price *0.5;
        }
        
        else  if ((days_passed >= 0.95 * durable_life_period)||(days_passed < durable_life_period)) {
            printf("This item has a Star Tag and it is Final Sale.\n");
            tag = "Star & Final Sale";
            new_price = regular_price *0.95;
        }
        else
        {
            printf("This item must be removed from the shelves and storage to be removed from the inventory.\n");
        }
    }
    else if (group >=69 && group <= 72){
        
        if ((days_passed >= 0.6 * durable_life_period)||(days_passed < 0.70 * durable_life_period)) {
            printf("This item has a yellow Tag.\n");
            tag = "Yellow";
            new_price = regular_price * 0.9;
        }
        
        else  if ((days_passed >= 0.7 * durable_life_period)||(days_passed < 0.8 * durable_life_period)){
            printf("This item has a green Tag.\n");
            tag = "Green";
            new_price = regular_price *0.75;
        }
        
        else  if ((days_passed >= 0.8 * durable_life_period)||(days_passed < 0.95 * durable_life_period)) {
            printf("This item has a red Tag.\n");
            tag = "Red";
            new_price = regular_price *0.5;
        }
        
        else  if ((days_passed >= 0.95 * durable_life_period)||(days_passed < durable_life_period)) {
            printf("This item has a Star Tag and it is Final Sale.\n");
            tag = "Star & Final Sale";
            new_price = regular_price *0.95;
        }
        
        else
        {
            printf("This item must be removed from the shelves and storage to be removed from the inventory.\n");
        }
    }
    else if (group >=73 && group <= 75){
        
        if ((days_passed >= 0.4 * durable_life_period)||(days_passed < 0.50 * durable_life_period)) {
            printf("This item has a yellow Tag.\n");
            tag = "Yellow";
            new_price = regular_price * 0.9;
        }
        
        else  if ((days_passed >= 0.5 * durable_life_period)||(days_passed < 0.6 * durable_life_period)){
            printf("This item has a green Tag.\n");
            tag = "Green";
            new_price = regular_price *0.75;
        }
        
        else  if ((days_passed >= 0.6 * durable_life_period)||(days_passed < 0.95 * durable_life_period)) {
            printf("This item has a red Tag.\n");
            tag = "Red";
            new_price = regular_price *0.5;
        }
        
        else  if ((days_passed >= 0.95 * durable_life_period)||(days_passed < durable_life_period)) {
            printf("This item has a Star Tag and it is Final Sale.\n");
            tag = "Star & Final Sale";
            new_price = regular_price *0.95;
        }
        
        else
        {
            printf("This item must be removed from the shelves and storage to be removed from the inventory.\n");
        }
    }
    else if (group == 76){
        
            if ((days_passed >= 0.7 * durable_life_period)||(days_passed < 0.8 * durable_life_period)) {
                printf("This item has a yellow Tag.\n");
                tag = "Yellow";
                new_price = regular_price * 0.9;
            }
            
            else  if ((days_passed >= 0.8 * durable_life_period)||(days_passed < 0.9 * durable_life_period)){
                printf("This item has a green Tag.\n");
                tag = "Green";
                new_price = regular_price *0.75;
            }
            
            else  if ((days_passed >= 0.9 * durable_life_period)||(days_passed < 0.95 * durable_life_period)) {
                printf("This item has a red Tag.\n");
                tag = "Red";
                new_price = regular_price *0.5;
            }
            
            else  if ((days_passed >= 0.95 * durable_life_period)||(days_passed < durable_life_period)) {
                printf("This item has a Star Tag and it is Final Sale.\n");
                tag = "Star & Final Sale";
                new_price = regular_price *0.95;
            }
        else
        {
            printf("This item must be removed from the shelves and storage to be removed from the inventory.\n");
        }
}
    products->final_price = new_price;
}
