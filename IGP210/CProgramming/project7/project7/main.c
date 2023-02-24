//
//  main.c
//  project7
//
//  Created by Chang on 2023-02-09.


// the conclusion is that the value of a and b in version 1 did not change. but the value will change in version 1


//Q66 - version 2
/*
#include <stdio.h>

// Function declaration
int functionA(int *a, int *b){
    *a *= 10;
    *b *= 20;
  };

int main() {
  int a, b;
  printf("Enter two integers: ");
  scanf("%d%d", &a, &b);

  functionA(&a, &b);
  printf("The original values of a and b are: %d, %d\n", a, b);
  printf("The multiplied values of a and b are: %d, %d\n", a * 10, b * 20);
  return 0;
}
*/

//Q66 - version 1


#include <stdio.h>


void functionA(int a, int b){
    a *= 10;
    b *= 20;
  };

int main() {
  int a, b;
  printf("Enter two integers: ");
  scanf("%d%d", &a, &b);

  functionA(a, b);

  printf("The original values of a and b are: %d, %d\n", a, b);
  printf("The multiplied values of a and b are: %d, %d\n", a * 10, b * 20);
  return 0;
}


/*
#include <stdio.h>

int function1(int a, int b) {
    printf("Inserted integers inside function1: a = %d, b = %d\n", a, b);

    int c = a * 2;
    int d = b * 2;
    printf("Doubled values inside function1: c = %d, d = %d\n", c, d);

    int e = a * 3;
    int f = b * 3;
    printf("Tripled values inside function1: e = %d, f = %d\n", e, f);

    int sumOfTripled = e + f;
    printf("Sum of tripled values inside function1: %d\n", sumOfTripled);

    return sumOfTripled;
}

int main(void) {
    int a, b;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    int sumOfTripled = function1(a, b);
    printf("Sum of tripled values returned from function1: %d\n", sumOfTripled);

    int sum = a + b;
    printf("Sum of the inserted integers: %d\n", sum);

    int difference = sumOfTripled - sum;
    printf("Difference between sumOfTripled and sum: %d\n", difference);

    return 0;
}

*/


/*Q65

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
*/
