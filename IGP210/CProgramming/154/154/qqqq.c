//
//  qqqq.c
//  154
//
//  Created by Chang on 2023-04-22.
//

#include <stdio.h>

void rank_result(int array[], int array_b[], int len){
    int i, j;
    int key;
    for (i = 0; i < len; i++){
        key=0;
        for (j = 0; j+1<len-i; j++){
            if (array[j] > array[j+1]){
                key=1;
                swap(&array[j], &array[j+1]);
            }
        }
        if (key==0) {
            break;
        }
    }
    for (i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
}
