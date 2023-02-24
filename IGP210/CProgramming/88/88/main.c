//
//  main.c
//  88
//
//  Created by Chang on 2023-02-21.
//

#include <stdio.h>

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter the value of element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int transposed[cols][rows];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    printf("Transposed Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*

1. Can we transpose a 1D matrix? why/how?
 yes, array[1][n] transpose to array[n][1].
 
2. Can we transpose a 3D and 4D matrix? why/how?
 yes, the next layer of array is as one element. in this element, it can be transpose as requirement.
 
3. What is the meaning and the use of a transposed matrix?
 it is used in data analysis, data management.
 
*/
