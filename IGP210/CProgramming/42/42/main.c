//
//  main.c
//  42
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    // a) State that a program will calculate the product of three integers.
    printf("This program will calculate the product of three integers\n\n");
    
    // b) Prompt the user to enter three integers.
    printf("Please enter the integers: \n\n");
    
    // c) Define the variable x to be of type int and initialize it to 0.
    int x = 0;
    
    // d) Define the variable y to be of type int and initialize it to 0.
    int y = 0;
    
    // e) Define the variable z to be of type int and initialize it to 0.
    int z = 0;
    
    int product;
    
    // f) Read three integers from the keyboard and store them in variables x, y, and z.
    
    scanf("%d", &x);
    printf("Please enter the integers: \n\n");
    scanf("%d", &y);
    printf("Please enter the integers: \n\n");
    scanf("%d", &z);
    
    // g) Define the variable result, compute the product of the integers in the variables x, y, and z, and use that product to initialize the variable result.
    product = x * y * z;
    
    // h) Display "The product is" followed by the value of the int variable result.
    printf("The product is %d \n", product);
}
