//
//  main.c
//  95
//
//  Created by Chang on 2023-02-23.
//

#include <stdio.h>

int main() {
    int m, n;
    int i, j, k;
    int arr1[100][100];
    int arr2[100][100];
    int arr3[100][100];

    printf("Input the size of the matrix (MxN): ");
    scanf("%d %d", &m, &n);


//    input the data to array
    printf("Input the elements of the arr1:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\n");
    
    printf("Input the elements of the arr2:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("\n");
        
//    calculate to arr3
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            arr3[i][j] = 0;
            for (k = 0; k < n; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
           }
        }
    }
    printf("calculate is done. \n");
    
// Print the arr3
      printf("arr3:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", arr3[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}
