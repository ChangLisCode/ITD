//
//  main.c
//  133
//
//  Created by Chang on 2023-03-10.
//

#include <stdio.h>

int main() {
    int arr[5][5];
    int *ptr = &arr[0][0];
    
    int i, j, val = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            *(ptr + i * 5 + j) = val++;
        }
    }

    printf("Array values:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", *(ptr + i * 5 + j));
        }
        printf("\n");
    }

    printf("\nArray addresses:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%p ", (ptr + i * 5 + j));
        }
        printf("\n");
    }

    int new_value;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            
            printf("Enter new value of array[%d][%d]: ",i,j);
            scanf("%d", &new_value);
            *(ptr + i * 5 + j) = new_value;
        }
    }
    

    printf("\nUpdated array values:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", *(ptr + i * 5 + j));
        }
        printf("\n");
    }

    return 0;
}
