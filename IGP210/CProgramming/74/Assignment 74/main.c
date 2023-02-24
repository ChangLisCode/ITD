//
//  main.c
//  Assignment 74
//
//  Created by Chang on 2023-02-13.
//


#include <stdio.h>

int sumcalculator(int array[5]);

int main() {
    int sum;
    int arrayA[5] = {10, 20, 30, 40, 50};
    sum = sumcalculator(arrayA);
    printf("print from main, the sum of array is %d.\n", sum);
    return 0;
}

int sumcalculator(int array[5]){
    int sum = 0;
    for(int i=0; i< 5; i++){
        sum += array[i];
    }
    printf("print from sumcalculator, the sum of array is %d.\n", sum);
    return sum;
};
