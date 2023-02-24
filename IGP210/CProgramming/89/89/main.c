//
//  main.c
//  89
//
//  Created by Chang on 2023-02-21.
//

#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d", &rows);
    scanf("%d", &cols);

    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

// read values
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter the value of element at [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter the value of element at [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

// sum
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

// print
    printf("Result:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
