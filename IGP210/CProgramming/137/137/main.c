//
//  main.c
//  137
//
//  Created by Chang on 2023-03-14.
//

#include <stdio.h>

int main(void) {
int age;
int *ageptr; // declare an integer pointer named "ageptr"
    
scanf("%d", &age);
ageptr = &age; // store the address of age in ageptr
    
printf("The secret address is... %p\n", ageptr); // print out the address stored in ageptr
*ageptr -= 5; // use only ageptr to lower the age by 5 years
    
printf("Now take three drops of the magic elixir. \n");
printf("Did the elixir work? You are %d years old!\n\n", age);
    
return 0;
}
