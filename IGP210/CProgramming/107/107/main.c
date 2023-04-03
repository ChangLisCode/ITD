//
//  main.c
//  107
//
//  Created by Chang on 2023-03-01.
//

#include <stdio.h>
#include <math.h>

//iteration method
double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

//recursive method
double factorial_recursive(int n) {
    double fact = 1;
    int m = 1;
    
    if(n <=0){
        return 1;
    }
    else{
        m = n * factorial_recursive(n-1);
       return m;
    }
}

double eCalculate(int n) {
    double currentSum = 1;

    for(int i=1; i<=n; i++) {
        currentSum += 1.0 / factorial(i);
    }
    return currentSum;
}

int main() {
    int n = 483600;
//    int n = 2147483600;
    double e = eCalculate(n);
    printf("Estimated value of e: %.18f\n", e);
    return 0;
}
