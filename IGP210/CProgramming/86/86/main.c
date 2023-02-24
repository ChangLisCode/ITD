//
//  main.c
//  86
//
//  Created by Chang on 2023-02-17.
//

#include <stdio.h>

void factorial(int n) {
    int i, result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    for(i = n; i > 1; i--){
        printf("%d * ", i);
        
    }
    
    printf(" 1 = %d", result);
}

int main() {
    int num = 1;
    
    printf("Enter the number : \n");
    scanf("%d", &num);

    factorial(num);
    
    printf(" \n\n");
    
    return 0;
}
