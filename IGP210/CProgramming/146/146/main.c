//
//  main.c
//  146
//
//  Created by Chang on 2023-03-16.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int *array;
    array = (int *)malloc(5*sizeof(int));
    
    array[0] = 3;
    array[1] = 33;
    array[2] = 333;
    array[3] = 3333;
    array[4] = 33333;
    
    printf("%d \n", array[0]);
    
    *(array + 0) = 10;
    *(array + 1) = 100;
    *(array + 2) = 1000;
    *(array + 3) = 10000;
    *(array + 4) = 100000;
    
    printf("%d \n", array[0]);
    free(array);
    printf("%d \n", array[0]);

    return 0;
}
