//
//  main.c
//  97
//
//  Created by Chang Li on 2023-02-24.
//

#include <stdio.h>

int sumOfDigits(int x){
    int sum = 0;

    while(x != 0){
            sum += x % 10;
            x /= 10;     
    }
    return sum;
}

int main() {
    int a;
    printf("please input your number. \n");
    scanf("%d", &a);
    
    printf("the sum of digits is %d. \n", sumOfDigits(a));
}
