//
//  main.c
//  135
//
//  Created by Chang on 2023-03-13.
//

#include <stdio.h>

int main() {
    char a[4];
    char b[6];
    char c[9];

    char *words[3] = {a, b, c};

    printf("Please insert a word with maximum 3/4 letters:\n");
    scanf("%s",a);
    
    printf("Please insert a word with maximum 5/6 letters:");
    scanf("%s", b);
    
    printf("Please insert a word with maximum 8/9 letters: ");
    scanf("%s", c);
    
    printf("You inserted:");
    printf("%s \n %s \n %s \n", a, b, c);
    
    printf("The other to print the inserted words: \n");
    printf("%s \n %s \n %s \n", words[0], words[1], words[2]);
    
    return 0;
}
