//
//  main.c
//  77
//
//  Created by Chang on 2023-02-15.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

// external calculation function for question part one, it has two datatype, integer and doulbe. I think they can be coded in one function. I will update it soon.

int addInt(int option){
    int num1, num2;
    int result;
    
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    
    result = num1 + num2;
    
    printf("the addtion result is %d.", result);
    return result;
    }

double addDoulbe(int option) {
    double num1, num2;
    double result;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    
    result = num1 * num2;
    
    printf("the addtion result is %.2f.\n", result);
    return result;
    }
 
int subtractInt(int option){
    int num1, num2, result;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    result = num1 - num2;
    printf("the subtract result is %d.\n", result);
    return result;
    }

double subtractDoulbe(int option) {
    double num1, num2;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    double result = num1 - num2;
    printf("the subtract result is %.2f.\n", result);
    return result;

    }

int multiplyInt(int option){
    int num1, num2, result;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    result = num1 * num2;
    printf("the multiply result is %d.\n", result);
    return result;

    }

double multiplyDoulbe(int option) {
    double num1, num2, result;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("the multiply result is %.2f.\n", result);
    return result;
    }

int divideInt(int option){
    int num1, num2, result;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    result = num1 / num2;
    printf("the divide result is %d.\n", result);
    return result;
    }

double divideDoulbe(int option) {
    double num1, num2, result;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    result = num1 / num2;
    printf("the divide result is %.2f.\n", result);
    return result;
    }

int powerInt(int option){
    int num1, num2;
    printf("please input two integer.\n");
    scanf("%d%d", &num1, &num2);
    double result = pow((double)num1, (double)num2);
    printf("the power result is %.2f.\n", result);
    return result;
    }

double powerDoulbe(int option) {
    double num1, num2, result;
    printf("please input two double.\n");
    scanf("%lf %lf", &num1, &num2);
    result = pow(num1, num2);
    printf("the power result is %.2f.\n", result);
    return result;
    }

int exponentialInt(int option){
    int num1;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    double result = exp((double)num1);
    printf("the exponential result is %.lf.\n", result);
    return result;
    }

double exponentialDoulbe(int option) {
    double num1, result;
    printf("please input the double.\n");
    scanf("%lf", &num1);
    result = exp(num1);
    printf("the exponential result is %.2f.\n", result);
    return result;
    }

int squareRootInt(int option){
    int num1;
    double result;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    result = sqrt((double)num1);
    printf("the square_root result is %.lf.\n", result);
    return result;
    }

double squareRootDoulbe(int option) {
    double num1, result;
    printf("please input two double.\n");
    scanf("%lf", &num1);
    result = sqrt(num1);
    printf("the square root result is %.2f.\n", result);
    return result;
    }

int squareRoot3Int(int option){
    int num1, result;
    printf("please input the integer.\n");
    scanf("%d", &num1);
    result = pow((double)num1, 1.0/3.0);
    printf("the square root 3 result is %.lf.\n", pow(num1, 1.0/3.0));
    return result;
    }

double squareRoot3Doulbe(int option) {
    double num1, result;
    printf("please input two double.\n");
    scanf("%lf", &num1);
    result = pow(num1, 1.0/3.0);
    printf("the square root 3 result is %.2f.\n", result);
    return result;
    }

// make choice for different calculation for question part one
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

// for question part two, calculator main code.

int compoudCal(char operator, double firstNumber, double secondNumber){

    double result = 0;
    
    switch(operator)
    {
        case '+':
            result = firstNumber + secondNumber;
//            printf("result = %lf.\n",result);
            break;
 
        case '-':
            result = firstNumber - secondNumber;
//            printf("result = %lf.\n",result);
            break;
 
        case '*':
            result = firstNumber * secondNumber;
//            printf("result = %lf.\n",result);
            break;
 
        case '/':
            result = firstNumber / secondNumber;
//            printf("result = %lf.\n",result);
            break;
            
        case '=':
            printf("input is done, thanks.\n");
//            printf("result = %lf.\n",result);
            break;
 
        // operator doesn't match any case constant (+, -, *, /, =)
        default:
            printf("Error! operator is not correct.\n\n");
            break;
    }
    return result;
}

// for question part 2, calculate the number which is more than 2.

int compoundCal2(int numberAmount){
    int i, result;
    int arr[numberAmount];
//    char operator[numberAmount];
    char operator[100];
    
    for(i=0;i < numberAmount; i++){
        printf("please input the number-%d that you want calculate.\n\n", i+1);
        scanf("%d", &arr[i]);
        printf("please input your operator after this number.\n\n");
        scanf("%s", &operator[i]);
    }
    
    result = arr[0];
    
    for(i=0; i < numberAmount-1; i++){
        result = compoudCal(operator[i], result, arr[i+1]);
     }
    
//    input the result
    printf("the calculator: \n%d", arr[0]);
    
    for(i=1; i < numberAmount; i++){
        printf(" %c %d", operator[i-1], arr[i]);
    }
    printf(" = %d\n", result);
    return result;
}

int main() {
   
    int numberAmount = 0, dataType = 0, option = 0;
    
    printf("how many number will you want to calculate?\n\n");
    scanf("%d", &numberAmount);
    
//    make choise for different calculation
    
//    to resolve question part one.
            if(numberAmount == 2){
                
                printf("what operation do you need? \n");
                printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Exponential\n7. Square Root and Root 3\n\n");
                scanf("%d", &option);
                
                printf("what data will you input? \n");
                printf("1. integer\n2. double\n\n");
                scanf("%d", &dataType);
                
                switchFunction(option, dataType);
                
                printf("Thanks for using this calculate.\n\n");
            }
    
//        to reslolve question part two.
            else {
                compoundCal2(numberAmount);
    }
    return 0;
}

 






































//int main() {
//    int arrayA[5]= {1,2,3,4,5};
//    int size = sizeof arrayA;
////    / sizeof arrayA[2];
//    printf("%u \n", size);
//    return 0;
//}

