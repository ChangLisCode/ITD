//
//  main.c
//  127
//
//  Created by Chang on 2023-03-08.
//

#include <stdio.h>

int main() {
    
    int sum_odd = 0, sum_even = 0, count_odd = 0, count_even = 0;
    
//    without pointer
    for (int i = 11; i <= 999; i +=2) {
        sum_odd += i;
        count_odd++;
        }
    printf("without pointer:\nOdd sum is %d.\ncount is %d.\n", sum_odd, count_odd);
    
    for (int i = 12; i <= 998; i +=2) {
        sum_even += i;
        count_even++;
        }
    printf("Even sum is %d.\ncount is %d.\n", sum_even, count_even);
    
    printf("\n\n");
    
//    with pointer
    int *ptr_odd = &sum_odd;
    int *ptr_even = &sum_even;
    
    count_odd = 0;
    count_even = 0;
    
        for (int i = 11; i <= 999; i +=2) {
            ptr_odd += i;
            count_odd++;
            }
        printf("with pointer:\nOdd sum is %d.\ncount is %d\n", sum_odd, count_odd);
        
        for (int i = 12; i <= 998; i +=2) {
            ptr_even += i;
            count_even++;
            }
        printf("Even sum is %d.\ncount is %d.\n", sum_even, count_even);
    
    
    printf("\n\n");
    
    return 0;
}
