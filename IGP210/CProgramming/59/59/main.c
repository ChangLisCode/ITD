//
//  main.c
//  59
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    int totalCement;
    int totalBag;
    int purchasedCement = 0;
    double cementPerPound;
    int i;
    
    printf("please input the total cement you need:\n");
    scanf("%d", &totalCement);
    printf("\n\n");
    
    totalBag = (int)totalCement/120 + 1;
    
    cementPerPound = 45.00/120.00;
    printf("cement per pound is %lf:\n", cementPerPound);
    
    printf("\n\n");
    
    for(i=0; purchasedCement < totalCement; i++){
        purchasedCement += 120;
        printf("total purchased cement is %d.\n", purchasedCement);
    }
    
    printf("\n\n");
    printf("the cement bags %d bags.\n", purchasedCement);
    printf("the actual cost of cement %lf dollars.\n", cementPerPound * totalCement);
    printf("the cement bags you have to purchase %d dollars.\n", totalBag * 45);
    
    printf("\n\n");
    
    return i;
}
