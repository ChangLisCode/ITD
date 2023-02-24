//
//  main.c
//  69
//
//  Created by Chang on 2023-02-10.
//

#include <stdio.h>

int calculatorFunction(int a, int b, int n, int m) {
    int c, d, e;
    c = a * n;
    d = b * m;
    e = 3 * a + 4 * b + 5 * c + 6 * d;
    return e;
}

int main() {
    int a, b, n, m, e;

    printf("Enter values for a, b, n, and m: ");
    scanf("%d %d %d %d", &a, &b, &n, &m);

    e = calculatorFunction(a, b, n, m);

    printf("The value of e is: %d\n\n", e);

    return 0;
}

















//#include <stdio.h>
//
//void calculatorFunction(int a, int b, int n, int m, int *c, int *d, int *e) {
//    *c = a*n;
//    *d = b*m;
//    *e = 3*a + 4*b + 5*(*c) + 6*(*d);
//}
//
//int main() {
//    int a, b, n, m, c, d, e;
//
//    printf("Enter values for a, b, n, and m: ");
//    scanf("%d %d %d %d", &a, &b, &n, &m);
//
//    calculatorFunction(a, b, n, m, &c, &d, &e);
//
//    printf("The value of c is: %d\n\n", c);
//    printf("The value of d is: %d\n\n", d);
//    printf("The value of e is: %d\n\n", e);
//
//    return 0;
//}
