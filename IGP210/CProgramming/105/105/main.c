//
//  main.c
//  105
//
//  Created by Chang on 2023-02-28.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/resource.h>

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
    double a, b, c, d, e, f, g, h, i, j;
    struct rusage usage1, usage2;

    printf("Enter five numbers:\n");
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    getrusage(RUSAGE_SELF, &usage1);

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

    getrusage(RUSAGE_SELF, &usage2);
    printf("Memory usage: %ld KB\n", (usage2.ru_maxrss - usage1.ru_maxrss) / 1024);

    return 0;
}
