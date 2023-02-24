//
//  main.c
//  Assignment 73
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

void printFunctionOfMyClass(int a0, int aa, int a2, int a3, int a4);
void printFunctionOfMyClass2(int a0);
void printFunctionOfMyClass3(int array[5]);
int main() {
    int arrayA[] = {10, 20, 30, 40, 50};
    printf("----first method to pass array-----\n");
    printFunctionOfMyClass(arrayA[0], arrayA[1], arrayA[2], arrayA[3], arrayA[4]);
    
    printf("----second method to pass array----- \n");
    printFunctionOfMyClass2(arrayA[0]);
    printFunctionOfMyClass2(arrayA[1]);
    printFunctionOfMyClass2(arrayA[2]);
    printFunctionOfMyClass2(arrayA[3]);
    printFunctionOfMyClass2(arrayA[4]);
    
    printf("----third method to pass array----- \n");
    printFunctionOfMyClass3(arrayA);
    
    
    return 0;
}

void printFunctionOfMyClass(int a0, int aa, int a2, int a3, int a4){
    printf("the first element of my array is %d.\n", a0);
    printf("the first element of my array is %d.\n", aa);
    printf("the first element of my array is %d.\n", a2);
    printf("the first element of my array is %d.\n", a3);
    printf("the first element of my array is %d.\n", a4);
}

void printFunctionOfMyClass2(int a0){
    printf("the value is %d.\n", a0);
}

void printFunctionOfMyClass3(int array[5]){
    for(int i=0; i< 5; i++){
        printf("the value of array is %d.\n", array[i]);
    }
};
