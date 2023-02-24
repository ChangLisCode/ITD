//
//  main.c
//  81
//
//  Created by Chang on 2023-02-16.
//

#include <stdio.h>

int main() {
    int i, j;
    for(i = 0; i<27; i++){
        for(j=27; j > i+1; j--){
            printf("%c", (char)i+65);
        }
        printf("\n");
        }
    return 0;
}
