//
//  main.c
//  93
//
//  Created by Chang on 2023-02-22.
//

#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of elements in the matrix: ");
  scanf("%d", &n);

  int matrix[n];

//enter the elements of the matrix
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &matrix[i]);
  }

// Print the original matrix
  printf("Original matrix:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", matrix[i]);
  }
  printf("\n");

// Print the transposed matrix
  printf("Transposed matrix:\n");
  for (int i = 0; i < n; i++) {
    printf("%d\n", matrix[i]);
  }

  return 0;
}
