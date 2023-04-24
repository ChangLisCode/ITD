//
//  main.c
//  154
//
//  Created by Chang on 2023-03-20.
//

#include <stdio.h>
#include <string.h>
void average_amount(int array[], int len){
    
    int average = 0;
    
//    printf("%d", len);
    
    for(int i=0; i<len; i++){
        average += array[i];
    }
    
    printf("average precipitation is %d.\n", average/len);

}

void limit_value(int array[], int array_b[], int len){
    int min = array[0], max = array[0], m = 0, n = 0;
    
    for (int i = 0; i < len; ++i)
    {
        if(array[i] > max){
            max = array[i];
            m = i;
            }
        else{
            continue;;
        }
    }
    printf("the max amount of precipitation is: %d. \n", max);
    
    for (int j = 0; j < len; ++j)
    {
        if(array[j] < min){
            min = array[j];
            n = j;
            }
        else{
            continue;;
        }
    }
    printf("the min amount of precipitation is: %d \n", min);
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



int main(int argc, const char * argv[]) {

    char city_list[3];
    int precipitation[3];
        
    for(int i = 0; i < 3; i++){
        printf("please input city name.\n");
        scanf("%s", &city_list[i]);
        printf("please input precipitation of this city.\n");
        scanf("%d", &precipitation[i]);
    }
    
    int len = sizeof(precipitation)/sizeof(int);
    average_amount(precipitation, len);
    limit_value(precipitation, &city_list, len);
    rank_result(precipitation, &city_list, len);
    
    printf("\n\n");
    return 0;
}
