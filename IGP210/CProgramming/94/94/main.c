//
//  main.c
//  94
//
//  Created by Chang on 2023-02-22.
//

#include <stdio.h>

int main() {
    int age = 10, *p1;
    char name[10] = "hello", *p2;
    char address[10] = {"vancouver"}, *p3;

    
    p1 = &age;
    *p1 = age;
    
    p2 = &name[1];
    *p2 = name[1];
    
    p3 = &address[10];
    *p3 = address[3];
    
    
    printf("the age of the person is %d. \n", age);
    printf("the age of the person is %d. \n", *p1);
    printf("the age of the person is %p. \n", &p1);
    
    printf("\n\n\n");
    
    printf("the name of the person is %c. \n", name[1]);
    printf("the name of the person is %c. \n", *p2);
    printf("the name of the person is %p. \n", &p2);
    
    printf("\n\n\n");
    
    printf("the name of the person is %c. \n", address[1]);
    printf("the name of the person is %c. \n", *p3);
    printf("the name of the person is %p. \n", &p3);
    
    printf("\n\n\n");
    
    return 0;
}
