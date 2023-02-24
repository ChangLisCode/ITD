//
//  main.c
//  77
//
//  Created by Chang on 2023-02-15.
//

#include <stdio.h>
#include <math.h>

void addInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    printf("the addtion result is %d.\n", num1 + num2);
    printf("the addtion result is %d\n%d.", num1, num2);
    }

void addDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    printf("the addtion result is %.2f.\n", num1 + num2);
    }
 
void subtractInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    printf("the subtract result is %d.\n", num1 - num2);
    }

void subtractDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    printf("the subtract result is %.2f.\n", num1 - num2);
    }

void multiplyInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    printf("the multiply result is %d.\n", num1 * num2);
    }

void multiplyDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    printf("the multiply result is %.2f.\n", num1 * num2);
    }

void divideInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    printf("the divide result is %d.\n", num1 / num2);
    }

void divideDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    printf("the divide result is %.2f.\n", num1 / num2);
    }

void powerInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    printf("the power result is %.2f.\n", pow((double)num1, (double)num2));
    }

void powerDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    printf("the power result is %.2f.\n", pow(num1, num2));
    }

void exponentialInt(int option){
    int num1;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    printf("the exponential result is %.lf.\n", exp((double)num1));
    }

void exponentialDoulbe(int option) {
    double num1;
    printf("please input the double.\n");
    scanf("%lf", &num1);
    printf("the exponential result is %.2f.\n", exp(num1));
    }

void squareRootInt(int option){
    int num1;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    printf("the square_root result is %.lf.\n", sqrt((double)num1));
    }

void squareRootDoulbe(int option) {
    double num1;
    printf("please input two double.\n");
    scanf("%lf", &num1);
    printf("the square root result is %.2f.\n", sqrt(num1));
    }

void squareRoot3Int(int option){
    int num1;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    printf("the square root 3 result is %.lf.\n", pow((double)num1, 1.0/3.0));
    }

void squareRoot3Doulbe(int option) {
    double num1;
    printf("please input two double.\n");
    scanf("%lf", &num1);
    printf("the square root 3 result is %.2f.\n", pow(num1, 1.0/3.0));
    }

void switchFunction(int option, int dataType){
  
    switch(option) {
        case 1:
        {switch(dataType){
            case 1:
                addInt(option);
                break;
            case 2:
                addDoulbe(option);
                break;
        }}
            break;
        case 2:
        {switch(dataType){
            case 1:
                subtractInt(option);
                break;
            case 2:
                subtractDoulbe(option);
                break;
        }}
            break;
        case 3:
        {switch(dataType){
            case 1:
                multiplyInt(option);
                break;
            case 2:
                multiplyDoulbe(option);
                break;
        }}
            break;
        case 4:
        {switch(dataType){
            case 1:
                divideInt(option);
                break;
            case 2:
                divideDoulbe(option);
                break;
        }}
            break;
        case 5:
        {switch(dataType){
            case 1:
                printf("please make sure function pow() need input doulbe data.\n");
                powerInt(option);
                break;
            case 2:
                powerDoulbe(option);
                break;
        }}break;
        case 6:
        {switch(dataType){
            case 1:
                printf("please make sure function exponential need input doulbe data.\n");
                exponentialInt(option);
                break;
            case 2:
                exponentialDoulbe(option);
                addDoulbe(option);
                break;
        }}
            break;
        case 7:
        {switch(dataType){
            case 1:
                
                printf("please make sure function square root() need input doulbe data.\n");
                squareRootInt(option);
                squareRoot3Int(option);
                break;
            case 2:
                squareRootDoulbe(option);
                squareRoot3Doulbe(option);
                break;
        }}
            break;
        default:
            printf("Invalid operation");
            break;
    }
}

int main() {
   
    int dataType = 0, option = 0;
    
    printf("what operation do you need? \n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Exponential\n7. Square Root and Root 3\n\n");
    scanf("%d", &option);
    
    printf("what data will you input? \n");
    printf("1. integer\n2. double\n\n");
    scanf("%d", &dataType);
   
    switchFunction(option, dataType);
    
    printf("Thanks for using this calculate.\n\n");
    
    return 0;
}
