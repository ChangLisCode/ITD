//
//  main.c
//  105-3
//
//  Created by Chang on 2023-02-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_f(double a, double b, double c, double d, double e);
double calculate_g(double a, double b, double c, double d, double e);
double calculate_h(double a, double b, double c, double d, double e);
double calculate_i(double a, double b, double c, double d, double e);
double calculate_j(double a, double b, double c, double d, double e);

int main() {
    double a, b, c, d, e;
    printf("Enter five numbers: ");
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    // version 1: calculations in main function
    double f = a + b + c + d + e;
    double g = a - b - c - d - e;
    double h = a * b * c * d * e;
    double i = a / b / c / d / e;
    double j = pow(pow(a, b), c) + pow(d, e);

    printf("Version 1:\n");
    printf("f = %lf\n", f);
    printf("g = %lf\n", g);
    printf("h = %lf\n", h);
    printf("i = %lf\n", i);
    printf("j = %lf\n", j);

    // version 2: calculations in functions
    double f2 = calculate_f(a, b, c, d, e);
    double g2 = calculate_g(a, b, c, d, e);
    double h2 = calculate_h(a, b, c, d, e);
    double i2 = calculate_i(a, b, c, d, e);
    double j2 = calculate_j(a, b, c, d, e);

    printf("Version 2:\n");
    printf("f = %lf\n", f2);
    printf("g = %lf\n", g2);
    printf("h = %lf\n", h2);
    printf("i = %lf\n", i2);
    printf("j = %lf\n", j2);

    // calculate memory usage for version 1
    int memory_v1 = 0;
    memory_v1 += sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d) + sizeof(e);
    memory_v1 += sizeof(f) + sizeof(g) + sizeof(h) + sizeof(i) + sizeof(j);
    printf("Memory usage for version 1: %d bytes\n", memory_v1);

    // calculate memory usage for version 2
    int memory_v2 = 0;
    memory_v2 += sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d) + sizeof(e);
    memory_v2 += sizeof(f2) + sizeof(g2) + sizeof(h2) + sizeof(i2) + sizeof(j2);
    printf("Memory usage for version 2: %d bytes\n", memory_v2);

    // calculate memory saved as a percentage
    int memory_saved = ((memory_v1 - memory_v2) / memory_v2) * 100;
    printf("Memory saved as a percentage: %d%%\n", memory_saved);

    return 0;
}

double calculate_f(double a, double b, double c, double d, double e)
