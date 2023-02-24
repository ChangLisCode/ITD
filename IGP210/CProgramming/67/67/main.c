//
//  main.c
//  67
//
//  Created by Chang on 2023-02-10.
//

#include <stdio.h>
#include <math.h>

int functionUp(int x){
    int i=0;
    for (i=0; i<x; i++){
        printf("%d \n", i);
    }
    return 0;
};

int functionDown(int x){
    int i=0;
    for (i=0; i<x; i++){
        printf("%d \n", i);
    }
    return 0;
 };

int main(int argc, const char * argv[]) {
    double a, b;
    printf("please insert the number.\n");
    scanf("%lf", &a);
    
    printf("%.2f", a);
    printf("\n\n\n");
    
    b = round(a);
    
    if (a - (double)b >= 0.5){
        functionUp(b);
    }
    else {
        functionDown(b);
    }
    
    return b;
}
