//
//  main.c
//  109
//
//  Created by Chang on 2023-03-01.
//

#include <stdio.h>

// iterative method
int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

//recursive method
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}


int main() {
    for (int i = 0; i < 100; i++) {
        printf("%d ", fibonacci_iterative(i));
    }
    printf("\n\n");
    
    for (int i = 0; i < 100; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n\n");
    
    return 0;
}

// comparison
/*
 
Iterative method has less function call, and less calculation task.
 
Recursive method is easy to understand, and the code is simply and clear. In the processing time, Recursive method need far larger time than iterative method.

If the project is small, recursive method is good. but when the project is giant task, iterative is good for memeroy and efficency reason.

 */
