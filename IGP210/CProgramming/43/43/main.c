//
//  main.c
//  43
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    int x = 0;
    
//    7 + 3 * 6 / 2 - 1, first: 3*6, second: /2, third: +7 -1
    printf("the value of x-1 is: %d\n", 7 + 3 * 6 / 2 - 1);
    
//    2 % 2 + 2 * 2 - 2 / 2, first: 2%2, 2*2, 2/2, second: + and -
    printf("the value of x-2 is: %d\n", 2 % 2 + 2 * 2 - 2 / 2);
    
//    (3 * 9 * (3 + (9 * 3 / (3)))), first: 9*3/3, second 3+(), third:3*9*()
    printf("the value of x-3 is: %d\n",  (3 * 9 * (3 + (9 * 3 / (3)))));
}
