//
//  main.c
//  75
//
//  Created by Chang on 2023-02-14.
//

#include <stdio.h>
#include <string.h>

int main() {
    int m = 0, n = 0, i = 0;
    
    printf("please input two integer.\n");
    scanf("%d%d", &m, &n);

    int array[4];
    char *arrayA[20] = {"multiplication", "subtraction", "addition", "division"};
    
    array[0] = m * n;
    array[1] = m - n;
    array[2] = m + n;
    array[3] = m / n;
    
    for(i=0; i<4; i++){
        
        printf("the %s of %d and %d is %d.\n", arrayA[i], m, n, array[i]);
        
        if(array[i] > 0){
            printf("the number is positive, and second number is %d.\n", array[i] * array[i]);
        }
        else if(array[i] < 0){
            printf("the number is negative");
            printf(", and the number 1 is %d.\n", array[i] * 10);
            printf(", and the number 2 is %d.\n", array[i] * 20);
            printf(", and the number 3 is %d.\n", array[i] * 30);
        }
        else {
            printf("the number is zero.\n");
        }
    }
    return 0;
}
