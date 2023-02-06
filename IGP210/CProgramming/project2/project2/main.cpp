#include <stdio.h>

int main(){
    
    printf("Hello my fellow students in C programming course.\n");
    
// For loops
// separated For loops
    for(int i=0; i<5; i++){
        printf("1 - Hello my fellow students in C programming course.\n");
    }
    
    printf("\n\n\n");

    for(int i=0; i<5; i++){
        printf("2 - Hello my fellow students in C programming course.\n");
    }
    
// integrated For loops
    
    for(int i=0; i<3; i++){
        printf("1 - first layer.\n");
        for(int i=0; i<3; i++){
            printf("2 - second layer.\n");
        }
        printf("\n\n\n");
    }

// counters of For loops
    
    int n = 0;
    for(int i=0; i<5; i++){
        printf("1 - first layer.\n");
        for(int i=0; i<5; i++){
            printf("2 - second layer.\n");
            n++;
        }
        printf("\n\n\n");
        n++;
    }

    
// intergers %d
    
    int x = 11;
    int y = 22;
    int z = 33;
    printf("1 - first number is 1.\n");
    printf("1 - first number is 2.\n");
    printf("1 - first number is 3.\n");
    
    printf("\n\n");
    
    printf("2 - first number x is equal to %d.\n", 111);
    printf("2 - first number y is equal to %d.\n", 222);
    printf("2 - first number z is equal to %d.\n", 333);

    printf("\n\n");
     
    printf("2 - first number x is equal to %d.\n", x);
    printf("2 - first number y is equal to %b.\n", 11);
    printf("2 - first number z is equal to %d.\n", z);
    
    return n;
}


