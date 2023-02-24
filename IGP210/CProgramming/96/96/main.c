//
//  main.c
//  96
//
//  Created by Chang on 2023-02-23.
//

#include <stdio.h>
//!showMemory(star-65520)


int main(void) {
    int age;
    int number1;
    int number2;
    int number3;
    
    double height;
    
    float weight;
    int weight1;
    
    char first_nameAc;
    char last_nameAc;
    char char3;
    char char4;
    char char5;
    
    int *p1;
    int *p2;
    int *p3;
    int *p4;
    
    double *p5;
    float *p6;
    
    int *p7;
    
    char *p8;
    char *p9;
    char *p10;
    char *p11;
    char *p12;
    
    p8 = &first_nameAc;
    p9 = &last_nameAc;
    p10 = &char3;
    p11 = &char4;
    p12 = &char5;
    
    printf("the value of variable age is %d.\n", age);
    printf("the value of the variable address is %p.\n", age);
    printf("the pointer of the variable age is p1.\n");
    printf("the address of p1 is %p.\n", &p1);
    printf("the value of p1 as the pointer of the variable age is %p.\n", &age);
    
    int n1;
    int n2;
    
    n1 = 10;
    n2 = 20;
    
    int *pointer1;
    int *pointer2;
    
    pointer1 = &n1;
    pointer2 = &n2;
    pointer1 = &n2;
    pointer2 = &n1;
    
    printf("the value of variable age is %d.\n", age);
    printf("the value of the pointer is %p.\n", &*p8);
    printf("the pointer of the pointer is p1.\n");
    printf("the address of p9 is %p.\n", &p9);
    printf("the value of p10 as the pointer is %p.\n", &p10);
    
    return 0;
}
