//
//  main.c
//  124
//
//  Created by Chang on 2023-03-07.
//

#include <stdio.h>

void reverse(int *arr, int size) {
  int i;
  printf("The elements of the array in reverse order are:\n");
  for (i = size-1; i >= 0; i--) {
    printf("%d ", *(arr+i) + 3);
  }
}

int main() {
  int size, i;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  reverse(arr, size);

  printf("\n\n ");
  return 0;
}

/*
conclusion:
use pointer is more simple than pass the value directly
*/
