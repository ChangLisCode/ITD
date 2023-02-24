//
//  main.c
//  91
//
//  Created by Chang on 2023-02-21.
//

#include <stdio.h>
int main(){
    int m, n;
    int i, j;
    int arr[100][100];

    printf("Input the size of the matrix (MxN): ");
    scanf("%d %d", &m, &n);
    printf("Input the elements of the matrix:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
        printf("The transposed matrix is:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
