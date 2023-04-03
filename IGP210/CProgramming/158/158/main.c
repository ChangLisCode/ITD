//
//  main.c
//  158
//
//  Created by Chang on 2023-03-22.
//  Project: an application for grocery stores and their inventories

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// structure define
struct Product {
  char name[100];
  char category[50];
  char manufacturer[100];
  float purchased_price;
  float sale_price;
  float final_price;
  int quantity;
  int purchased_date;
  int production_date;
  int expiry_date;
  int barcode;
  char currency[10];
  int sale_date;
};

// function define

void inventory_define(char *string);
void import_information(int new_product, int date);
char encryption_method_1(char *string);
char encryption_method_2(char *string);
float encryption_method_3(float value);
char encryption_method_4(char *string);
int encryption_method_5(char *string);
char encryption_method_6(char *string);
char encryption_method_7(char *string);
int encryption_format(int value);

int price_update(int date);
void inventory_update(int purchaed_list);

void writeExcel(char *string);
void openExcel(char *string);

// main function
int main(void) {
    
    int start_question, new_product, date;
    
    printf("Hi, How are you today!\nPlease input the date of today by the format of YYYY/MM/DD. Thanks.\n");
    scanf("%d", &date);
    
    printf("\nWould you like to import any item to your store?\nYes, please input[1]. \nNo, please input[0]\n[1]\n[0]\n");
    scanf("%d", &start_question);
    
    if(start_question == 1){
        printf("\nHow many product will you import to storage?\n");
        scanf("%d", &new_product);
        import_information(new_product, date);
    }
    
    printf("\n\n\n");
    return 0;
}


void openExcel(char *string){
    FILE* fp;
    char str[32];
    memset(str, 0, sizeof(str));
    size_t len=0;
    fp = fopen("inventory.csv", "r+");
    if (fp == NULL)
    {
    printf("fail to open the file.\n");
    exit(0);
    }
    while (!feof(fp))
    {
    len=fread(str, 1, 31, fp);
    printf("%s\n", str);
    }
    fclose(fp);
}

void writeExcel(char *string)
{
    char chy[4]={ 'x' ,'a' ,'h','w' } ;
    int data[4]={ 1 , 3 , 6 ,9    };
    int i ;
    FILE *fp = NULL ;
    fp = fopen("/Users/chang/Desktop/test.csv","w") ;
    for (i=36 ; i<40 ;i++)
        fprintf(fp,"%c\t%d\n",chy[i],data[i] ) ;
    fclose(fp);
}

void import_information(int new_product, int date){
    
    struct Product *products[new_product];
    
    
    for (int i = 0; i < new_product; i++) {
        
        products[i] = (struct Product*) malloc(sizeof(struct Product));
        
        printf("Enter the name of product %d: ", i+1);
        scanf("%s", products[i]->name);
        
        printf("Enter the category of product %d: ", i+1);
        printf("Please choose category type:\nGroup [A]: Meat\nGroup [B]: Deli\nGroup [C]: Pharmacy\nGroup [D]: Seafood\nGroup [E]: Beverage\nGroup [F]: Canned\nGroup [G]: Jarred\nGroup [H]: Dry Food\nGroup [I]: Dairy\nGroup [J]: Bakery\nGroup [K]: Personal Care\nGroup [L]: Paper Goods\n");
        scanf("%s", products[i]->category);
        
        printf("Enter the company/manufacturer name of product %d: ", i+1);
        scanf("%s", products[i]->manufacturer);
        
        printf("Enter the purchased price of product %d: ", i+1);
        scanf("%f", &products[i]->purchased_price);
        
        printf("Enter the sale price of product %d: ", i+1);
        scanf("%f", &products[i]->sale_price);
        
        printf("Enter the quantity of product %d: ", i+1);
        scanf("%d", &products[i]->quantity);
        
        printf("Enter the purchased date of product %d (yyyy-mm-dd): ", i+1);
        scanf("%d", &products[i]->purchased_date);
        
        printf("Enter the production date of product %d (yyyy-mm-dd): ", i+1);
        scanf("%d", &products[i]->production_date);
        
        printf("Enter the expiry date of product %d (yyyy-mm-dd): ", i+1);
        scanf("%d", &products[i]->expiry_date);
        
        printf("Enter the store code of product %d (4-digit number): ", i+1);
        scanf("%d", &products[i]->barcode);
        
        printf("Enter the currency of the country for product %d: ", i+1);
        scanf("%s", products[i]->currency);
    }
    
    //    show all the product list
    printf("\nProduct Information:\n");
    
    for (int i = 0; i < new_product; i++) {
        printf("Product name: %s\n, Category: %s\n, Manufacturer: %s\n, Purchased Price: %.2f\n, Currency: %s\n, Sale Price: %.2f\n, Quantity: %d\n, Purchased Date: %d\n, Production Date: %d\n, Expiry Date: %d\n, Barcode: %d\n\n",
               products[i]->name, products[i]->category,products[i]->manufacturer,  products[i]->purchased_price,  products[i]->currency,  products[i]->sale_price, products[i]->quantity,
               products[i]->purchased_date, products[i]->production_date,  products[i]->expiry_date,
               products[i]->barcode);}
    
    // shopping part
    int choice;
    printf("new product information has been import successfully. Will you leave or go to shoping?\n[1] leave\n[2]go to shopping\n");
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("Thanks for your job, have a nice day!");
    }
    else{
        
        int i, j, amount;
        //    int date;
        float sale_price = 0, final_price = 0, balance = 0, balance_original = 0, save_money = 0;
        
        printf("Welcome to our market for shopping!\n how many product would you like to purchase?\n");
        scanf("%d", &amount);
        
        struct Product *shopping_list[amount];
        
        for (int i = 0; i < amount; i++) {
            
            shopping_list[i] = (struct Product*) malloc(sizeof(struct Product));
        /*
         for actual shopping, barcode is from scanning instrument, now we need input it mannually.
         and the barcode is stored in array by pointer.
         */
            printf("input the barcode of purchased good list.\n");
            scanf("%d",&shopping_list[i]->barcode);
        }
        /*
         update the price based on date, which is calculate for the gap to expired date
         pass the structure to the price update function
         */
        price_update(date);
        
        //    get and calculate the price
        for (i=0; i < amount; i++) {
            for (j = 0; j < 36; j++) {
                if ((shopping_list[i]->barcode) == (products[j]->barcode)) {
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
        printf("---------supermarket receipt---------\n");
        printf("product barcode ****** product name ******* orginal price ******* price after disaccount\n");
        for (i=0; i<amount; i++) {
            printf("%d   %s    %.2f     %.2f\n"
                           ,shopping_list[i]->barcode, shopping_list[i]->name, shopping_list[i]->sale_price,
                   shopping_list[i]->final_price);
            printf("-----------------------------------\n");
        }
        printf("\n\n");
        printf("total money you saved: %.2f\n", save_money);
        printf("You need pay after diaccount. %.2f\n", balance);
        
        printf("Welcome shopping at our store!\n");
        
        
    }
}

//  encryption part
//  for name and manufacture
char encryption_method_1(char *string){
    int encrypted = 0;
    int i;
    for (i = 0; i < strlen(string); i++) {
        encrypted += string[i] + 20230322;
    }
    return encrypted;
}

//  for category
char encryption_method_2(char *string){

    int encrypted = 0;
    int ascii_code = (int)*string;
    
    switch(ascii_code){
        case 65:
            encrypted = encryption_method_1("meat");
            break;
        case 66:
            encrypted = encryption_method_1("Deli");
            break;
        case 67:
            encrypted = encryption_method_1("Pharmacy");
            break;
        case 68:
            encrypted = encryption_method_1("Seafood");
            break;
        case 69:
            encrypted = encryption_method_1("Beverage");
            break;
        case 70:
            encrypted = encryption_method_1("Canned");
            break;
        case 71:
            encrypted = encryption_method_1("Jarred");
            break;
        case 72:
            encrypted = encryption_method_1("Dry Food");
            break;
        case 73:
            encrypted = encryption_method_1("Dairy");
            break;
        case 74:
            encrypted = encryption_method_1("Bakery");
            break;
        case 75:
            encrypted = encryption_method_1("Personal Care");
            break;
        case 76:
            encrypted = encryption_method_1("Paper Goods");
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
    encrypted = encryption_method_1(string) + 20230322;
    return encrypted;
}
//
//int encryption_method_5(int value){
//        int key = 25;
//        int encrypted = value * 25;
//        return encrypted;
//}

char encryption_method_6(char *string){
    int encrypted = 0;
    int ascii_code = ((int)*string) * 100 + 23;
    return encrypted;
}

char encryption_method_7(char *string){
    int encrypted = 0;
    int ascii_code = ((int)*string) + 23;
    return encrypted;
}

// format the encryption result, first verify whether the code is 16 digits, if not, fill with 0 after last digit, till total digit is 12.
int encryption_format(int encryption){
    int num = encryption;
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


// base on promotion rule, update the sale price
int price_update(int date){
    float new_price = 0;
    float regular_price = 0;
    
    char *tag, group = 'A';
    
    int durable_life_period = 0, days_passed = 0;
    
    printf("Enter the durable life period (in days): ");
    scanf("%d", &durable_life_period);
    
    printf("Enter the number of days passed since the item was put on the shelf: ");
    scanf("%d", &days_passed);
    
    
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
  
    return new_price;
}


