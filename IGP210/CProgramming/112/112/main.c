//
//  main.c
//  112
//
//  Created by Chang on 2023-03-03.
//

#include <stdio.h>

int main() {
    
    int i = 50;
    int *iAdr;
    iAdr = &i;
    
    double a = 5.55;
    double b = 6.66;
    
    double *aAdr = &a;
    double *bAdr = &b;
    
    float c = 1.001;
    float d = 2.002;
    
    float *cAdr = &c;
    float *dAdr = &d;
    
    char e = 'e';
    char f = 'f';
    
    char *eAdr = &e;
    char *fAdr = &f;
    
    printf("The value of the variable i is %d and the address is %p.\n", i, &i);
    
    printf("The value of the variable i is %lf and the address is %p.\n", a, &a);
    printf("The value of the variable i is %lf and the address is %p.\n", b, &b);
    
    printf("The value of the variable i is %lf and the address is %p.\n", c, &c);
    printf("The value of the variable i is %lf and the address is %p.\n", d, &d);
    
    printf("The value of the variable i is %c and the address is %p.\n", e, &e);
    printf("The value of the variable i is %c and the address is %p.\n", f, &f);
    
    *iAdr = 100;
    
    *aAdr = 10.10;
    *bAdr = 20.20;
    
    *cAdr = 30.3030;
    *dAdr = 40.4040;
        
    *eAdr = 'X';
    *fAdr = 'Y';
    
    printf("The value of the variable i is %d and the address is %p.\n", i, &i);
    
    printf("The value of the variable i is %lf and the address is %p.\n", a, &a);
    printf("The value of the variable i is %lf and the address is %p.\n", b, &b);
    
    printf("The value of the variable i is %lf and the address is %p.\n", c, &c);
    printf("The value of the variable i is %lf and the address is %p.\n", d, &d);
    
    printf("The value of the variable i is %c and the address is %p.\n", e, &e);
    printf("The value of the variable i is %c and the address is %p.\n", f, &f);
    
    printf("\n\n\n");
    return 0;
}
