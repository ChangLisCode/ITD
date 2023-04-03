//
//  main.c
//  152
//
//  Created by Chang on 2023-03-20.
//

#include <stdio.h>
#include <math.h>

void calculate_change(float *product_price, float *customer_pay){
    float change;
    int dollars, quarters, dimes, nickels, pennies;
    
    change = *customer_pay - *product_price;
    
    dollars = (int) change;
    change -= dollars;
    
    quarters = (int) (change / 0.25);
    change -= quarters * 0.25;
    
    dimes = (int) (change / 0.1);
    change -= dimes * 0.1;
    
    nickels = (int) (change / 0.05);
    change -= nickels * 0.05;
    
    pennies = (int) (change / 0.01);
    
    printf("You need give customer total change: $%.2f\n", *customer_pay - *product_price);
    printf("Dollars: %d\n", dollars);
    printf("Quarters: %d\n", quarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);
}

int main() {
    
    float product_price;
    float customer_pay;
   
    printf("please tell me the price of the product: \n");
    scanf("%f", &product_price);
    
    printf("please tell me the the custome pays: \n");
    scanf("%f", &customer_pay);
    
    
    if (customer_pay > product_price){
        calculate_change(&product_price, &customer_pay);
    }
    
    else if (customer_pay == product_price)
    {
        printf("the payment is same with price, no need for change. Thanks. \n");
    }
    else
    {
        printf("the payment is not enough, please input again. \n");
    }
 
    printf("\n\n\n");
    return 0;
}



    //    int temp = (int)change * 100;
        
    //    bill = change * 100 / 100;
    //    printf("the 1 dollar for customer is: %d \n\n", bill);
    //
    //    bill = temp % 100 / 25;
    //    printf("the 25 cent for customer is: %d \n\n", bill);
    //
    //    bill = temp % 100 % 25 / 10;
    //    printf("the 10 cent for customer is: %d \n\n", bill);
    //
    //    bill = temp % 100 % 25 % 10 / 5;
    //    printf("the 5 cent for customer is: %d \n\n", bill);
    //
    //    bill = temp % 100 % 25 % 10 % 5;
    //    printf("the 1 cent for customer is: %d \n\n", bill);
    }
