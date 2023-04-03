//
//  main.c
//  110
//
//  Created by Chang on 2023-03-02.
//

#include <stdio.h>

void myFunction(int a, int *aAtr, double d, double *dAdr, float e, float *eAdr, char g, char *gAdr, char h, char *hAdr){
    printf("My Function is receiveing %p\n, %p\n,%p\n, %p\n,%p\n, %p\n", a, aAtr, d, dAdr, e, eAdr, g, &*gAdr, h, &*hAdr);
}

int main() {
    int a = 122;
    int *aAdr = &a;
    
    double d = 84.4;
    double *dAdr =&d;
    
    float e = 94.494994;
    float *eAdr = &e;
    
    char g = 'g';
    char *gAdr = &g;
    
    char h = 'h';
    char *hAdr = &h;
    
    myFunction(a, aAdr, d, dAdr, e, eAdr, g, gAdr, h, hAdr);

    printf("\n\n");
    return 0;
}


