//
//  main.c
//  85
//
//  Created by Chang on 2023-02-17.
//
#include <stdio.h>

void upward_triangle(int n, char sym) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", sym);
        }
        printf("\n");
    }
}

void downward_triangle(int n, char sym) {
    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("%c ", sym);
        }
        printf("\n");
    }
}

void rectangle(int n, char sym) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c ", sym);
        }
        printf("\n");
    }
}

int main() {
    int n_up, n_down, n_rect;
    char sym1, sym2, sym3;

    printf("Enter the number of lines for the upward triangle: ");
    scanf("%d", &n_up);
    printf("Enter the symbol to be used: ");
    scanf(" %c", &sym1);
    
    printf("Enter the number of lines for the downward triangle: ");
    scanf("%d", &n_down);
    printf("Enter the symbol to be used: ");
    scanf(" %c", &sym2);
    
    printf("Enter the number of lines for the rectangle: ");
    scanf("%d", &n_rect);
    printf("Enter the symbol to be used: ");
    scanf(" %c", &sym3);

    printf("Upward triangle:\n");
    upward_triangle(n_up, sym1);

    printf("Downward triangle:\n");
    downward_triangle(n_down, sym2);

    printf("Rectangle:\n");
    rectangle(n_rect, sym3);

    return 0;
}
