//
//  main.c
//  61
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>
int main() {
    int arrayH[3][3][2];
    int i, j, k;
    printf("\n\n\n");
    printf("please insert 18 intetger.\n");
    for (i=0; i<3; i++){
        for ( j=0; j<3; j++){
            for ( k=0; k<3; k++ ){
                scanf("%d", &arrayH[i][j][k]);
            }
        }
    }
    for (i=0; i<3; i++){
        for ( j=0; j<3; j++){
            for ( k=0; k<3; k++ ){
                printf("%d", arrayH[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
 
