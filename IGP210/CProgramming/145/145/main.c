//
//  main.c
//  145
//
//  Created by Chang on 2023-03-16.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int *a;
    a = (int *) malloc(sizeof(int));
    *a = 10;
    
    printf("We stored %d at memory location %p, \n", *a, a);
    
    free(a);
        
    printf("We stored %d at memory location %p. \n", *a, a);

    return 0;
}
