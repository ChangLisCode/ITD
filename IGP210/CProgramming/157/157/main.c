//
//  main.c
//  157
//
//  Created by Chang on 2023-03-21.
//

#include <stdio.h>

void swap(int *elementPtr_1, int *elementPtr_2)
{
    int temp = *elementPtr_1;
    *elementPtr_1 = *elementPtr_2;
    *elementPtr_2 = temp;
}

void bubbleSort(int array[], int size, int (*sort)(int a, int b)){
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1; j++) {
            if ((*sort)(array[j], array[j + 1])) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    

}

int ascending(int a, int b){
    return b < a;
}

int descending(int a, int b){
    return b > a;
}

int main(int argc, const char * argv[]) {

    int order,i;
    int data[10] = {2, 6, 4, 8, 10,12, 89, 68, 45, 37};
    
    printf("please input choice about sort type: \n[1].ascending order\n[2].descending\n");
    scanf("%d", &order);
    
    if(order == 1){
        printf("Data in ascending order:\n");
        bubbleSort(data, 10, ascending);
        for (i = 0; i < 10; i++) {
            printf("%d, ", data[i]);
        }
    }
    else
    {
        bubbleSort(data, 10, descending);
        printf("Datain descending order\n");
        for (i = 0; i < 10; i++) {
            printf("%d, ", data[i]);
        }
    }
    
    printf("\n\n");
    return 0;
}
