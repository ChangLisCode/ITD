//
//  main.c
//  98
//
//  Created by Chang Li on 2023-02-24.
//

#include <stdio.h>
 
#include <stdio.h>
 
int main()
{
    int *ptr;
    int x;
 
    ptr = &x;
    *ptr = 0;
 
    printf(" x = %dn", x);
    printf(" *ptr = %dn", *ptr);
 
    *ptr += 5;
    printf(" x  = %dn", x);
    printf(" *ptr = %dn", *ptr);
 
    (*ptr)++;
    printf(" x = %dn", x);
    printf(" *ptr = %dn", *ptr);
 
    return 0;
}

1)
x = 0
*ptr = 0
x = 5
*ptr = 5
x = 6
*ptr = 6


2)

x = garbage value
*ptr = 0
x = garbage value
*ptr = 5
x = garbage value
*ptr = 6


3)
x = 0
*ptr = 0
x = 5
*ptr = 5
x = garbage value
*ptr = garbage value



4)
x = 0
*ptr = 0
x = 0
*ptr = 0
x = 0
*ptr = 0
