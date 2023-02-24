//
//  main.c
//  Assignment 71
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

void function1(int num1, int num2, double num3, double num4, double num5){
    int sum1;
    double sum2;
    
    sum1 = num1 + num2 + (int)num3 + (int)num4 + (int)num5;
    sum2 = (double)num1 + (double)num2 + num3 + num4 + num5;
    
    printf("sum1 is equeal to %d.\n, sum2 is equal to %lf.\n", sum1, sum2);
    printf("\n\n\n");
};

void function2(int num1, int num2, double num3, double num4, double num5){
    int subtract1 =  num1 - num2 - (int)num3 - (int)num4 - (int)num5;
    double subtract2 = (double)num1 + (double)num2 + num3 + num4 + num5;
    printf("sum1 is equeal to %d\n, sum2 is equal to %lf.\n", subtract1, subtract2);
    
};

void function3(int num1, int num2, double num3, double num4, double num5){
    int array1[5] = {num1, num2, (int)num3, (int)num4, (int)num5};
    int i, j;
    int temp;
    for (i=0; i<5; i++){
        for (j = 0; j < 4 - i; j++){
            if (array1[j] > array1[j+1]){
                temp = array1[j];
                array1[j] = array1[j+1];
                array1[j+1] = temp;
            }
        }
    }
        for(i=0; i<5; i++){
            printf("%d \n", array1[i]);
        }
    printf("\n\n\n");
    };
    
    void function4(int num1, int num2, double num3, double num4, double num5){
        int array1[5] = {num1, num2, (int)num3, (int)num4, (int)num5};
        int i, j;
        int temp;
        for (i=0; i<5; i++){
            for (j = 0; j < 4 - i; j++){
                if (array1[j] < array1[j+1]){
                    temp = array1[j];
                    array1[j] = array1[j+1];
                    array1[j+1] = temp;
                }
            }
        }
        for(i=0; i<5; i++){
            printf("%d \n", array1[i]);
        }
        printf("\n\n\n");
    };
    
// I do not know why function5 can not work.

    void function5(int num1, int num2, double num3, double num4, double num5){
        int array1[5] = {num1, num2, (int)num3, (int)num4, (int)num5};
        int i, j;
        int temp;
        for (i=0; i<5; i++){
            for (j = 0; j < 4 - i; j++){
                if (array1[j] < array1[j+1]){
                    temp = array1[j];
                    array1[j] = array1[j+1];
                    array1[j+1] = temp;
                }
            }
        }
        
        int subtractA = array1[0];
        
        for(i=1; i<5; i++){
            subtractA -= array1[i];
//            printf("%d \n", subtractA);
        }
        printf("the last subtractA is %d \n", subtractA);
        printf("\n\n\n");
    };
    
    
    void function6(int num1, int num2, double num3, double num4, double num5){
        int array1[5] = {num1, num2, (int)num3, (int)num4, (int)num5};
        int i;
        int multiplyA = 1;
        for (i=1; i<5; i++){
            multiplyA *= array1[i];
        }
        printf("the multiply of all the elements is %d \n", multiplyA);
        printf("\n\n\n");
    };
    
    
    void function7(int num1, int num2, double num3, double num4, double num5){
        int array1[5] = {num1, num2, (int)num3, (int)num4, (int)num5};
        int i;
        int divideA = array1[0];
        for (i=1; i<5; i++){
            divideA /= array1[i];
        }
        printf("the divide of all the elements is %d \n", divideA);
        printf("\n\n\n");
    };
    
    int main(){
        int num1, num2;
        double num3, num4, num5;
        
        printf("Please input num1 and num2!\n");
        scanf("%d %d", &num1, &num2);
        
        printf("Please input num3, num4 and num5!\n");
        scanf("%lf %lf %lf", &num3, &num4, &num5);
        
        printf("\n\n\n");
        
        function1(num1, num2, num3, num4, num5);
        function2(num1, num2, num3, num4, num5);
        function3(num1, num2, num3, num4, num5);
        function4(num1, num2, num3, num4, num5);
//        function5(num1, num2, num3, num4, num5);
        function6(num1, num2, num3, num4, num5);
        function7(num1, num2, num3, num4, num5);
        return 0;
    }

