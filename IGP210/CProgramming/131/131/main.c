//
//  main.c
//  131
//
//  Created by Chang on 2023-03-10.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char **str) {
    int len = strlen(*str);
    char *temp = (char*) malloc(len+1);
    char **words = (char**) malloc(len * sizeof(char*));
    int i, j, start = 0, count = 0;

    // break string into words and store in array
    for (i = 0; i <= len; i++) {
        if ((*str)[i] == ' ' || (*str)[i] == '\0') {
            int wordlen = i - start;
            words[count] = (char*) malloc(wordlen+1);
            strncpy(words[count], &((*str)[start]), wordlen);
            words[count][wordlen] = '\0';
            count++;
            start = i + 1;
        }
    }

    // reverse order of words in array
    for (i = 0, j = count-1; i < j; i++, j--) {
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // copy reversed words back into original string
    start = 0;
    for (i = 0; i < count; i++) {
        int wordlen = strlen(words[i]);
        strncpy(&((*str)[start]), words[i], wordlen);
        start += wordlen + 1;
        (*str)[start-1] = ' ';
        free(words[i]);
    }
    (*str)[len] = '\0';

    free(words);
    free(temp);
}

int main() {
    char *str = "I AM A PROGRAMMER AND I LIVE IN VANCOUVER BC";
    printf("Original string: %s\n", str);
    reverseWords(&str);
    printf("Reversed words: %s\n", str);
    return 0;
}
