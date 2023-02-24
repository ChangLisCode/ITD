//
//  main.c
//  66 version2
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

// Function declaration
void functionA(int *a, int *b){
    *a *= 10;
    *b *= 20;
  }

int main() {
  int a, b;
  printf("Enter two integers: ");
  scanf("%d%d", &a, &b);

  functionA(&a, &b);
  printf("The original values of a and b are: %d, %d\n", a, b);
  printf("The multiplied values of a and b are: %d, %d\n", a * 10, b * 20);
  return 0;
}
