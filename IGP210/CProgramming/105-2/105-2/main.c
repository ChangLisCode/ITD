//
//  main.c
//  105-2
//
//  Created by Chang on 2023-02-28.
//



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//version 2
double calculate_f(double a, double b, double c, double d, double e) {
    return a + b + c + d + e;
}

double calculate_g(double a, double b, double c, double d, double e) {
    return a - b - c - d - e;
}

double calculate_h(double a, double b, double c, double d, double e) {
    return a * b * c * d * e;
}

double calculate_i(double a, double b, double c, double d, double e) {
    return a / b / c / d / e;
}

double calculate_j(double a, double b, double c, double d, double e) {
    return pow(pow(a, b), c) + pow(d, e);
}


int main() {
    
//version 1
    
    double a, b, c, d, e;
    double f, g, h, i, j;

    printf("Enter five numbers (separated by spaces): ");
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    f = a + b + c + d + e;
    g = a - b - c - d - e;
    h = a * b * c * d * e;
    i = a / b / c / d / e;
    j = pow(pow(a, b), c) + pow(d, e);
  
    printf("The amount of f is: %lf\n", f);
    printf("The amount of g is: %lf\n", g);
    printf("The amount of h is: %lf\n", h);
    printf("The amount of i is: %lf\n", i);
    printf("The amount of j is: %lf\n", j);

    double mem_use1 = sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d) + sizeof(e) + sizeof(f) + sizeof(g) + sizeof(h) + sizeof(i) + sizeof(j);
    
    printf("Memory usage: %lf bytes\n", mem_use1);
        
//version 2

    f = calculate_f(a, b, c, d, e);
    g = calculate_g(a, b, c, d, e);
    h = calculate_h(a, b, c, d, e);
    i = calculate_i(a, b, c, d, e);
    j = calculate_j(a, b, c, d, e);

    printf("The amount of \"f\" is: %lf\n", f);
    printf("The amount of \"g\" is: %lf\n", g);
    printf("The amount of \"h\" is: %lf\n", h);
    printf("The amount of \"i\" is: %lf\n", i);
    printf("The amount of \"j\" is: %lf\n", j);

    double mem_use2 = sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d) + sizeof(e) + sizeof(f) + sizeof(g) + sizeof(h) + sizeof(i) + sizeof(j);
    
    printf("Memory usage: %lf bytes\n", mem_use2);
       
//percenage calculate
    
    printf("Memory Saved as a Percentage: %lf %% \n", ((mem_use1 - mem_use2) / mem_use2) * 100);
    
    return 0;
}
