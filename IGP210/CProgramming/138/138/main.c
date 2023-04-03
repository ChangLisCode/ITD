//
//  main.c
//  138
//
//  Created by Chang on 2023-03-14.
//

#include <stdio.h>

void elixir(int *ageAddr);

#include <stdio.h>

int main(void) {
    int age;
    int *ageptr; // declare an integer pointer named "ageptr"
    int *ageAddr;
    
    scanf("%d", &age);
    ageptr = &age; // store the address of age in ageptr
    ageAddr = &age;
    
    elixir(ageAddr);
        
    printf("The secret address is... %p\n", ageptr); // print out the address stored in ageptr
    
    
    printf("Now take three drops of the magic elixir. \n");
    printf("Did the elixir work? You are %d years old!\n\n", age);
        
    return 0;
}


void elixir(int *ageAddr) {
    if (*ageAddr >= 21) {
        *ageAddr -= 10;
    } else {
        *ageAddr *= 2;
    }
}
