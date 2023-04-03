//
//  main.c
//  123
//
//  Created by Chang on 2023-03-07.
//

#include <stdio.h>

int main() {
  int size, i;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("The elements of the array in reverse order are:\n");
  int *ptr = arr + size - 1;
  for (i = 0; i < size; i++) {
    printf("%d ", *ptr);
    ptr--;
  }
    printf("\n\n ");
  return 0;
}
