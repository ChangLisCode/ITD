//
//  main.c
//  114
//
//  Created by Chang on 2023-03-03.
//

#include <stdio.h>

//version 1
void myFunction1(int x){
    x *= 2;
    printf("the value of x is %d. \n", x);
}

//version 2
int myFunction2(int *ptr){
    int y = *ptr * 3;
    printf("the value of y is %d.\n %d is passed to this function as parameter in this address 'ptr'. \n", y, *ptr);
    return  *ptr;
}

void myFunction3(int myNumbers2[4], int *ptr){
        for (int i = 0; i < 4; i++) {
      printf("the array position - %d is: %d\n", myNumbers2[i], *(ptr + i));
    }
}

int main() {
    
    int a = 5;
    int b = 6;
    int *ptr1 = &b;
    
    int myNumbers1[4] = {25, 50, 75, 100};
    int myNumbers2[4] = {1, 2, 3, 4};
    
    int *ptr2 = &myNumbers1;
  
    
    myFunction1(a);
    myFunction2(ptr1);
    myFunction3(myNumbers2, ptr2);
    
    return 0;
}
