//
//  main.c
//  115
//
//  Created by Chang on 2023-03-06.
//

#include <stdio.h>

int main() {
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char* p = letters;

// from A to Z
    printf("A to Z:\n");
    while (p < letters + 26) {
        printf("%c ", *p);
        p++;
    }

// from Z to A
    printf("\n\nZ to A:\n");
    p = letters + 25;
    while (p >= letters) {
        printf("%c ", *p);
        p--;
    }

// from input letter to Z
    char start_letter;
    printf("\n\nEnter a letter to start from (capital letter only): ");
    scanf("%c", &start_letter);
    printf("%c to Z:\n", start_letter);
    p = letters + (start_letter - 'A');
    while (p < letters + 26) {
        printf("%c ", *p);
        p++;
    }

// from input letter to A
    printf("\n\n%c to A:\n", start_letter);
    p = letters + (start_letter - 'A');
    while (p >= letters) {
        printf("%c ", *p);
        p--;
    }

    printf("\n");
    return 0;
}
