//
//  main.c
//  95-2
//
//  Created by Chang on 2023-02-23.
//

#include <stdio.h>

int main() {
    // Define the matrices
    int array1[2][2] = {{1, 3}, {5, 7}};
    int array2[2][2] = {{2, 4}, {6, 8}};
    int array3[2][2];

    // Perform the multiplication and store the result in array3
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            array3[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    // Print the result
    printf("The result of the multiplication is:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
