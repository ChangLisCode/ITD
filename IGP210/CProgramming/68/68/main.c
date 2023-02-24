//
//  main.c
//  68
//
//  Created by Chang on 2023-02-10.
//

#include <stdio.h>

int main() {
    int tourists = 10;
    double yuan[tourists];
    double cad[tourists];

    for (int i = 0; i < tourists; i++) {
        printf("Enter the amount in Chinese Yuan for tourist %d: ", i+1);
        scanf("%lf", &yuan[i]);

        cad[i] = yuan[i] * 0.2;
        printf("%.2lf Chinese Yuan is equal to %.3lf Canadian Dollar\n", yuan[i], cad[i]);
    }

  return 0;
}

