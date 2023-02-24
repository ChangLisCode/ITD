//
//  main.c
//  76
//
//  Created by Chang on 2023-02-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int a=0, i, j, temp, num;
    int even_count = 0, odd_count = 0;
    int arr[a];

    // Ask the user to input integers
    printf("How many integers would you like to enter? \n");
    scanf("%d", &a);
    printf("\n");
        
    printf("please input the integers.\n");
        
    for (i = 0; i < a; i++) {
        
        while (scanf("%d", &num) != 1) {
            printf("the system accept the non-integer, but please re-enter an integer for next number.\n\n");
            while (getchar() != '\n'){ // Clear input buffer
            //               exit(1);
            continue;
                
            }
               arr[i] = (int)num;

           }

        arr[i] = num;
       }
    
    //Determine whether each number is even or odd
    for (i = 0; i < a; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d is even.\n", arr[i]);
            even_count++;
        }
        else {
            printf("%d is odd.\n", arr[i]);
            odd_count++;
        }
    }
    printf("The total even number is %d.\n", even_count);
    printf("The total odd number is %d.\n", odd_count);

    // Sort the numbers in ascending order
    for (i = 0; i < a-1; i++) {
        for (j = i+1; j < a; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Output the sorted array
    printf("The numbers in ascending order are:\n");

    for (i = 0; i < a; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
