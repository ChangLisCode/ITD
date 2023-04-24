//
//  function1.c
//  158 - supermarket inventory system
//
//  Created by Chang on 2023-04-19.
//

#include "function1.h"
void import_information(int new_product, int date[]){
    
    struct Product *products[new_product];
    
//    struct Product *products = (struct Product*) malloc(sizeof(struct Product) * new_product);
    
    for (int i = 0; i < new_product; i++) {
        
        products[i] = (struct Product*) malloc(sizeof(struct Product));
        
        printf("\nEnter the name of product %d: \n", i+1);
        scanf("%s", products[i]->name);
        
        strncpy(products[i]->name_encryption, encryption_method_1(products[i]->name),sizeof(products[i]->name_encryption));
        
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
        barcode_generate(*products);
    }
    
    //    show all the product list
    printf("\nProduct Information:\n");
    
    for (int i = 0; i < new_product; i++) {
        printf("Product name: %s\n, Category: %s\n, Manufacturer: %s\n, Purchased Price: %.2f\n, Currency: %s\n, Sale Price: %.2f\n, Quantity: %d\n, Purchased Date: %d%d%d\n, Production Date: %d%d%d\n, Expiry Date: %d%d%d\n, Barcode: %s\n\n",
               products[i]->name, products[i]->category,products[i]->manufacturer,  products[i]->purchased_price,  products[i]->currency,  products[i]->sale_price, products[i]->quantity,
               products[i]->purchased_date[0], products[i]->purchased_date[1], products[i]->purchased_date[2], products[i]->production_date[0], products[i]->production_date[1], products[i]->production_date[2],  products[i]->expiry_date[0],products[i]->expiry_date[1],products[i]->expiry_date[2],
               products[i]->barcode);}
    
// shopping part should be single function, when basic information is input firstly.
//    in this method, it need be integrated to import function, due to based on memory management method
    
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
