//
//  main.c
//  139
//
//  Created by Chang on 2023-03-14.
//

#include <stdio.h>

void swap(int *num1, int *num2); // function prototype

int main(void) {
    int num1, num2;
    
    printf("Enter two integer values: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    swap(&num1, &num2);
    
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}

// function definition for swap
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/*

For each of the following, write a statement that performs the specified task. Assume that float variables number1 and number2 are defined and that number1 is initialized to 7.3.

1. Define the variable fPtr to be a pointer to an object of type float.

float *fPtr;

2. Assign the address of variable number1 to pointer variable fPtr.

fPtr = &number1;

3. Print the value of the object pointed to by fPtr.

printf(“ %f”, fPtr);

4. Assign the value of the object pointed to by fPtr to the variable number2.

float number2 = *fPtr;

5. Print the value of number2.

printf(“%f”, number2);

6. Print the address of number1. Use the %p conversion specification.

printf(“%p”, &number1);

7. Print the address stored in fPtr. Use the %p conversion specifier. Is the value printed the same as the address of number1?

printf("%p", fPtr);
yes ,it is same.

*/
