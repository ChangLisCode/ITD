//
//  main.c
//  58
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    double totalMoney;
    double bookPrice;
    double totalPrice=0;
    int i=0;
    
    printf("please input the money you have:\n");
    scanf("%lf", &totalMoney);
    
    printf("please input the book price:\n");
    scanf("%lf", &bookPrice);
    
    printf("\n\n");
    
    printf("total money is: %lf\n", totalMoney);
    printf("the book price is: %lf\n", bookPrice);

    printf("\n\n");
    
    printf("total money is: %.2f\n", totalMoney);
    printf("the book price is: %.2f\n", bookPrice);

    
    for(i=0; totalPrice < totalMoney; i++){
        totalPrice += bookPrice;
        printf("total Price is %lf.\n", totalPrice);
    }
    
//    do{
//        totalPrice += bookPrice;
//        i++;
//    }
//    while (totalPrice < totalMoney);
    
    printf("\n\n");
    printf("book amount is %d.\n", i-1);
    printf("\n\n");
    
    return i;
}

