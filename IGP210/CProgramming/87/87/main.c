//
//  main.c
//  87
//
//  Created by Chang on 2023-02-17.
//

#include <stdio.h>

void fibonacci(int num) {
    int i, m = 0, n = 1, temp = 0;
    
    printf("%d, %d", m, n);
    
    for (i = 0; i < num - 2; i++) {
        temp = m + n;
        m = n;
        n = temp;
        printf(", %d", temp);
    }
}

int main() {
    int num;
    
    printf("Enter the number : \n");
    scanf("%d", &num);
    
    fibonacci(num);
    
    printf(" \n\n");
    return 0;
}
