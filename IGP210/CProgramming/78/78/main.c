//
//  main.c
//  78
//
//  Created by Chang on 2023-02-16.
//

#include <stdio.h>

int main() {
    int num, originalNum, reversedNum = 0, remainder;

    printf("please in the data: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    if (originalNum == reversedNum) {
        printf("Reversed: %d is the same.\n", originalNum);
    }
    else {
        printf("Reversed: %d is NOT the same.\n", originalNum);
    }

    return 0;
}

