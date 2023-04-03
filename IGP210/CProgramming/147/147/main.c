//
//  main.c
//  147
//
//  Created by Chang on 2023-03-16.
//

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void insert_function(int *arr, int val, int idx) {
    arr[idx] = val;
}

void print_function(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr1[ARRAY_SIZE];
    int *ptr1 = arr1;
    insert_function(ptr1, 1, 0);
    insert_function(ptr1, 2, 1);
    insert_function(ptr1, 3, 2);
    insert_function(ptr1, 4, 3);
    insert_function(ptr1, 5, 4);
    print_function(ptr1);

    int *arr2 = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int *ptr2 = arr2;
    insert_function(ptr2, 1, 0);
    insert_function(ptr2, 2, 1);
    insert_function(ptr2, 3, 2);
    insert_function(ptr2, 4, 3);
    insert_function(ptr2, 5, 4);
    print_function(ptr2);

    int stack_memory_usage = (5 * sizeof(int)) + (sizeof(int*)); 
    printf("Stack memory usage: %d bytes\n", stack_memory_usage);

    free(arr2);
    return 0;
}

