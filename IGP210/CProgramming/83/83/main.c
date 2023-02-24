//
//  main.c
//  83
//
//  Created by Chang on 2023-02-16.
//

#include <stdio.h>

int main() {
    int i, j, k, m=0;
    
    printf("how many lines/letters will be printed?\n");
    scanf("%i", &m);
        
    for(i = 0; i<m; i++){
        for(j=0; j<i+1; j++){
            for(k=0; k<j+1; k++){
                printf("%c%c", (char)(k+65), 32);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
