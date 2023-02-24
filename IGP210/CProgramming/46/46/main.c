//
//  main.c
//  46
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main(){
    printf("5.0/2 is %d.\n", 5.0/2);
    printf("5.0/2 is %lf.\n", 5.0/2);
    printf("\n\n");
    
    printf("5/2.0 is %d.\n", 5/2.0);
    printf("5/2.0 is %lf.\n", 5/2.0);
    printf("\n\n");
    
    printf("5/2 is %d.\n", 5/2);
    printf("5/2 is %lf.\n", 5/2);
    printf("\n\n");
        
    int intFive = 5;
    int intTwo =2;
    double doubleFive = 5.0;
    double doubleTwo = 2.0;
    
    double doubleFive1 = 5.2;
    double doubleTwo1 = 2.2;
    
    printf("intFive / inTwo is %d.\n", intFive/intTwo);
    printf("intFive / intTwo is %lf.\n", intFive/intTwo);
    printf("\n\n");
    
    printf("doubleFive / doubleTwo is %d.\n", doubleFive/doubleTwo);
    printf("doubleFive / doubleTwo is %lf.\n", doubleFive/doubleTwo);
    printf("\n\n");
    
    printf("doubleFive1 / doubleTwo1 is %d.\n", doubleFive1/doubleTwo1);
    printf("doubleFive1 / doubleTwo1 is %lf.\n", doubleFive/doubleTwo1);
    printf("\n\n");
    
    int twenties = 166/20;
    
    printf(" pay %d number \n ", twenties);
    printf("bills is %d \n", twenties*20);
    printf("pay %d CAD. \n", 166-twenties*20);
}
