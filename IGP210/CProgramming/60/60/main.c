//
//  main.c
//  60
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {

    char letter;
    char letter0 = '+';

    int i, j, k;
    int l = 1, m = 9, n = 5;
    
    printf(" **** \033[1;33m Assignment 60 \033 [1;32m *****\n");

    printf("please input the leter:\n");
    scanf("%c", & letter);

    printf("please input the column:\n");
    scanf("%d", &m);

    printf("please input the row:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) {

            if (j == m/2) {
                for (k = 0; k < l; k++) {
                    printf("%c", letter);
                }
                } else {
                    printf("%c", letter0);
                }
        }
        l += 2;
        m -= 2;
        printf("\n");
    }
    return 0;

}
