//
//  main.c
//  104
//
//  Created by Chang Li on 2023-02-27.
//

#include <stdio.h>
double myFunction(int, double, char);
 
int main(){
//! showMemory(start=65520)

    int i;
    double a;
    double b;
    char c;
    int arrayA[3];
    
    a = 1.0;
    b = 2.0;
    c = 'C';
    
    for(i=0; i<3; i++){
        arrayA[i] = i*i + 1;
        b = myFunction(i, b, c);
            }
    
    for (i=0; i<3; i++){
        arrayA[i] = i*i+1;
        b = myFunction(i, b, c);
    }
    
    
    return 0;
}

double myFunction(int j, double d, char l){
    printf("This function received %d, %lf, and %c. \n", j, d, l);
    
    j++;
    d = j*d;
    l = 'b';
    
    printf("In this function we changed the values of j/i, d/b, and l/c to %d, %lf, %c. \n", j, d, l);
    
    return d;
}
