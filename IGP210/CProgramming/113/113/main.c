//
//  main.c
//  113
//
//  Created by Chang on 2023-03-03.
//

#include <stdio.h>

//version 1
void myFunction1(int x){
    x *= 2;
    printf("the value of x is %d. \n", x);
}

//version 2
int myFunction2(int *ptr){
    int y = *ptr * 3;
    printf("the value of y is %d.\n %d is passed to this function as parameter in this address 'ptr'. \n", y, *ptr);
    return  *ptr;
}

int main() {
    
    int a = 5;
    int b = 6;
    
    int *ptr = &b;
    
    myFunction1(a);
    myFunction2(ptr);
    
    return 0;
}
