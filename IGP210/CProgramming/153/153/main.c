//
//  main.c
//  153
//
//  Created by Chang on 2023-03-20.
//

#include <stdio.h>
#include <math.h>

void calculate_change(int money){
    int bill;
    
    bill = money / 100;
    printf("the 100 bill for customer is: %d \n\n", bill);
    
    bill = (money % 100) / 50;
    printf("the 50 bill for customer is: %d \n\n", bill);
    
    bill = money % 100 % 50 / 20;
    printf("the 20 bill for customer is: %d \n\n", bill);
    
    bill = money % 100 % 50 % 20 / 10;
    printf("the 10 bill for customer is: %d \n\n", bill);
    
    bill = money % 100 % 50 % 20 % 10 / 5;
    printf("the 5 bill for customer is: %d \n\n", bill);
    
    bill = money % 100 % 50 % 20 % 10 % 5 / 2;
    printf("the 2 coin for customer is: %d \n\n", bill);
    
    bill = money % 100 % 50 % 20 % 10 % 5 % 2;
    printf("the 1 coin for customer is: %d \n\n", bill);
}

int main() {
    
    int money = 0;
 
    printf("please tell me how many money do you need: \n");
    scanf("%d", &money);
    
    calculate_change(money);
 
    printf("\n\n\n");
    return 0;
}
