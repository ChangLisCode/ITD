//
//  main.c
//  136
//
//  Created by Chang on 2023-03-13.
//

#include <stdio.h>

int main() {
    char words [3][10];

    for(int i=0; i<3; i++){
        scanf("%s", words[i]);
    }
    
    for(int i=0; i<3; i++){
        printf("%s\n", words[i]);
    }
        
    printf("The first letters of the inserted strings are:");
    
    for(int i=0; i<3; i++){
        printf("\"%s\" starts with the letter %c. \n", words[i], words[i][0]);
    }
    
//   new method
    
    char *p = &words[0][0]; // pointer to the first element of the 2D array

    for(int i=0; i<3; i++){
        scanf("%s", p + i*10); // using pointer arithmetic to access the ith row of the 2D array
    }
    
    for(int i=0; i<3; i++){
        printf("%s\n", *(words+i)); // using pointer arithmetic to access the ith row of the 2D array
    }
        
    printf("The first letters of the inserted strings are:");
    
    for(int i=0; i<3; i++){
        printf("\"%s\" starts with the letter %c. \n", *(words+i), *(*(words+i))); // using pointer arithmetic to access the first character of the ith string in the 2D array
    }
    
    return 0;
}
