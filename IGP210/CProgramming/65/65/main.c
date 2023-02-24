//
//  main.c
//  65
//
//  Created by Chang on 2023-02-13.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int function1(int *x, int *y, char m[], char n[]){

    int sumOfTripled;

    printf("please insert two integers %s and %s. \n", m, n);
    scanf("%d %d", &*x, &*y);
    printf("%s = %d, %s = %d. \n\n", m, *x, n, *y);

    sumOfTripled = *x + *y;

    return  sumOfTripled;
}

int main(void) {
    int a=0, b=0, c=0, d=0, e=0, f=0;

    int sum, sumOfTripled;

    sumOfTripled = function1(&a, &b, "a", "b");
    printf("sum of a and b is %d.\n", sum = a + b);
    printf("difference of sumOfTripled and sum is %d.\n\n", sumOfTripled - sum);
    
    sumOfTripled = function1(&c, &d, "c", "d");
    printf("sum of c and d is %d.\n", sum = c + d);
    printf("difference of sumOfTripled and sum is %d.\n\n", sumOfTripled - sum);

    sumOfTripled = function1(&e, &f, "e", "f");
    printf("sum of e and f is %d.\n", sum = e + f);
    printf("sumOfTripled is %d.\n\n", sumOfTripled);
    printf("difference of sumOfTripled and sum is %d.\n\n", sumOfTripled - sum);

    return 0;
 }
