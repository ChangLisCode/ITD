//
//  main.c
//  Assignment 72
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

void positiveNegative(int num) {
    if (num >= 0) {
        printf("Positive");
    } else {
        printf("Negative");
    }
}

void evenOdd(int num) {
    if (num % 2 == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }
}

void compare(int num1, int num2) {
    if (num1 == num2) {
        printf("Both numbers are equal.");
    } else if (num1 < num2) {
        printf("Your first inserted number %d is less than your second inserted number %d.", num1, num2);
    } else {
        printf("Your first inserted number %d is greater than your second inserted number %d.", num1, num2);
    }
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("First number is ");
    positiveNegative(num1);
    printf(", Second number is ");
    positiveNegative(num2);
    printf(".\n");

    printf("First number is ");
    evenOdd(num1);
    printf(", Second number is ");
    evenOdd(num2);
    printf(".\n");

    compare(num1, num2);

    return 0;
}
