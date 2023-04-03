//
//  main.c
//  134
//
//  Created by Chang on 2023-03-13.
//

#include <stdio.h>

void input(int *n){

    printf("please enter your four-digit integer: ");
    scanf("%d", n);
    
//    confirm right input
    int m = *n;
    int count = 0;
    
    while(m != 0)
       {
           m = m / 10;
           ++count;
       }
 
    if(count == 4){
        printf("Your input is received!\nIt is %d.\n\n", *n);
       }
    else {
        printf("Your input is not right! Please input again.\n\n");
        input(n);
    }
}

void fEncrypt(int *n) {
    printf("n: %d\n", *n);
    
    int a, b, c, d;
    
    a = (*n / 1000 + 7) % 10;
    b = (*n / 100 + 7) % 10;
    c = (*n / 10 + 7) % 10;
    d = (*n % 10 + 7) % 10;
    
//    printf("a: %d\n", a);
//    printf("b: %d\n", b);
//    printf("c: %d\n", c);
//    printf("d: %d\n", d);
    
    *n = c * 1000 + d * 100 + a * 10 + b;
}

void fDecrypt(int *n) {
    
    printf("n: %d\n", *n);
    
    int a, b, c, d;
    
    a = (*n / 1000 + 3) % 10;
    b = ((*n / 100) % 10 + 3) % 10;
    c = ((*n / 10) % 10 + 3) % 10;
    d = (*n % 10 + 3) % 10;
    
//    printf("a: %d\n", a);
//    printf("b: %d\n", b);
//    printf("c: %d\n", c);
//    printf("d: %d\n", d);

    *n = c * 1000 + d * 100 + a * 10 + b;
}



int main() {
    int n;
    
    input(&n);
    printf("n: %d\n", n);
    
    fEncrypt(&n);
    printf("Encrypted value: %04d\n\n", n);
    
    fDecrypt(&n);
    printf("Decrypted value: %04d\n\n", n);
    
    return 0;
}
