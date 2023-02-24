//
//  main.c
//  79
//
//  Created by Chang on 2023-02-16.
//

#include <stdio.h>

int main() {
    int i, j;
    for(i = 0; i<27; i++){
        for(j=0; j<i+1; j++){
            printf("%c", (char)(i+65));
            printf("%c%c  %c", 32, 95, 32);
//            printf("%c", 95);
//            printf("%c", 32);
            printf("%c", (char)(i+48));
            printf("%c%c%c", 32, 47, 32);
        }
        printf("\n");
        printf("here is integer:   %d\n", i+64);
        printf("here is integer2:   %d\n", (int)(i+64));
        printf("here is double:   %lf\n", (double)(i+64));
//            printf("here is integer:   %s", (char)(i+64));

      
        printf("\n\n\n");
        }
    return 0;
}
