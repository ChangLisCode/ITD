//
//  main.c
//  125
//
//  Created by Chang on 2023-03-07.
//

#include <stdio.h>

int main() {
    int arrayA[6] = {6,5,4,3,2,1};
    
    printf("ArrayA  contains %d,%d,%d,%d,%d,%d", arrayA[0],arrayA[1],arrayA[2],arrayA[3],arrayA[4],arrayA[5],arrayA[6]);
    printf("\n\n");
    
    printf("ArrayA  contains %p,%p,%p,%p,%p,%p", arrayA[0],arrayA[1],arrayA[2],arrayA[3],arrayA[4],arrayA[5],arrayA[6]);
    
    
    printf("\n\n");
    
    int *ptr;
    int *ptr1;
    int *ptr2;
    int *ptr3;
    int *ptr4;
    int *ptr5;
    int *ptr6;
    
    
    ptr = arrayA;
    ptr1 = &arrayA[0];
    ptr2 = &arrayA[1];
    ptr3 = &arrayA[2];
    ptr4 = &arrayA[3];
    ptr5 = &arrayA[4];
    ptr6 = &arrayA[5];
    
    printf("ArrayA  contains %d,%d,%d,%d,%d,%d", ptr, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6);
        
    printf("\n\n");
    
    *ptr = 9;
    
    *(ptr+0) = 10;
    *(ptr+1) = 20;
    *(ptr+2) = 30;
    *(ptr+3) = 40;
    *(ptr+4) = 50;
    *(ptr+5) = 60;

    printf("ArrayA  contains %d,%d,%d,%d,%d,%d", *ptr, *(ptr+0), *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5));
    printf("\n\n");
    
    
    *arrayA = 100;
    
    *(arrayA + 0) = 150;
    *(arrayA + 1) = 250;
    *(arrayA + 2) = 350;
    *(arrayA + 3) = 450;
    *(arrayA + 4) = 550;
    *(arrayA + 5) = 650;
    
    ptr++;
    *ptr = 100;
    
    printf("ArrayA  contains %d,%d,%d,%d,%d,%d", *(arrayA + 0), *(arrayA + 1), *(arrayA + 2), *(arrayA + 3), *(arrayA + 4), *(arrayA + 5));
    printf("\n\n");
    
    return 0;
}
