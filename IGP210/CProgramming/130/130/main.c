//
//  main.c
//  130
//
//  Created by Chang on 2023-03-10.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rev_1(char *str1){
    int i, len, temp;
    len = strlen(str1);
      
    for (i = 0; i < len/2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
    
    printf("reverse string solution 1 is:\n %s \n\n", str1);
}

void rev_2(char arr[]){
    char arr_new[30][30];
    int i, j = 0, k = 0, temp;
    
    // initialize arr_new to all zeroes
    memset(arr_new, 0, sizeof(arr_new));
    
    // tear down the sentence to word, by blank as gap
    for(i=0; i < strlen(arr); i++){
        arr_new[j][k] = arr[i];
        if (isspace(arr[i])){
            j++;
            k = 0;
        } else {
            k++;
        }
    }
    
    // reverse each word
    for(i=0; i <= j; i++){
        int len2 = strlen(arr_new[i]);
        for (k = 0; k < len2/2; k++)
        {
            temp = arr_new[i][k];
            arr_new[i][k] = arr_new[i][len2 - k - 1];
            arr_new[i][len2 - k - 1] = temp;
        }
    }
    
    // print the reversed words
    printf("reverse string solution 2 is:\n");
    for(i=0; i <= j; i++){
        printf("%s", arr_new[i]);
    }

}

void rev_3(char **str) {
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
    printf("reverse string solution 3 is:\n %s \n\n", str);
}

int main() {
    char arr[] = {"I AM A PROGRAMMER AND I LIVE IN VANCOUVER BC"};
    char *arr3 = "I AM A PROGRAMMER AND I LIVE IN VANCOUVER BC";

    printf("original string is:\n %s \n\n", arr);
    
    rev_1(arr);
    rev_2(arr);
    rev_3(&arr3);
    
    printf("\n\n\n");
    return 0;
}
