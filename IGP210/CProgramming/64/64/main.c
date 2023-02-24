//
//  main.c
//  64
//
//  Created by Chang on 2023-02-13.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y){
    int compute;
    compute = x +y;
    return compute;
}

int main() {
    int a, b;
    int result;
    
    printf("1 - please insert two integers: \n");
    scanf("%d %d", &a, &b); // use space to input two integers.
    
    result = sum(a,b);
    
    printf("The result of a +b is equal %d.\n", result);
    printf("End of the program. \n");
    
    return 0;
    
}
