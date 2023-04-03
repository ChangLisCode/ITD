//
//  main.c
//  148
//
//  Created by Chang on 2023-03-17.
//

#include <stdio.h>
#include <stdlib.h>

void create_matrix(int n, int m){
    if (n < 3 || m < 4 || n > 500 || m > 500) {
        printf("Invalid matrix size\n");
    }
    
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    
    printf("Please enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
//            matrix[i][j] = 1;
        }
    }
    
    printf("input is finished, the matrix is: \n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    
//    check whether it is identity matrix
    int is_identity = 1;
    
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j && matrix[i][j] != 1) {
                    is_identity = 0;
                    break;
                }
                if (i != j && matrix[i][j] != 0) {
                    is_identity = 0;
                    break;
                }
            }
            if (!is_identity) {
                break;
            }
        }
    } else {
        is_identity = 0;
    }
   
//    How can you convert a matrix in which n and m are not equal, not a square matrix, to a square matrix?
//Answer: my method is comparing the n and m, choosing the samll one to create the matrix and output.
    
        
        if(n < m){
            n = m;
        }
        else{
            m = n;
        }
    
//    convert to identity matrix
    if (!is_identity) {
        printf("Converting the matrix to an identity matrix...\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
    } else {
        printf("Surprise! Your matrix is an identity matrix!\n");
    }
    
//    print the converted identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    
//   free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    
    free(matrix);
}

int main() {
    int n, m;
    
    printf("Please enter the number of rows and columns of the matrix (separated by a space): ");
    scanf("%d %d", &n, &m);

    create_matrix(n, m);
    
    return 0;
}
