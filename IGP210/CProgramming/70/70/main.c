//  main.c
//  69
//
//  Created by Chang on 2023-02-10.
//

#include <stdio.h>

int functionA(int a, int b, int *e) {
    int c, d;
    c = a * 10;
    printf("c is %d.\n", c);
    d = b * 20;
    printf("d is %d.\n", d);
    *e = a + b + c + d;
    return  *e;
    }

int main() {
    int a, b, c, d, e, m, n;

    printf("Enter values for a, b, e: ");
    scanf("%d %d", &a, &b);

    functionA(a, b, &e);

    printf("The value of a1 is: %d\n\n", a);
    printf("The value of b1 is: %d\n\n", b);
    printf("The value of e1 is: %d\n\n", e);

    
    
    m = functionA(a, b, &e) * 10;

    printf("The value of a2 is: %d\n\n", a);
    printf("The value of b2 is: %d\n\n", b);
    printf("The value of e2 is: %d\n\n", e);
    printf("The value of m2 is: %d\n\n", m);
    return 0;
}

