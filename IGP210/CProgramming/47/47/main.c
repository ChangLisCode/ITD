//
//  main.c
//  47
//
//  Created by Chang on 2023-02-13.
//
#include <stdio.h>
#include <math.h>

int main(){
        int x = 0;
        int y = 0;
        int z = 0;
    
        printf("Please enter the number x, y, z: ");
        
        scanf("%d%d%d", &x, &y, &z);
    
        printf("Sum is %d,\n", x + y + z);
        printf("Average is %d,\n", (x + y + z) / 3);
        printf("Product is %d,\n", x * y * z);
//        printf("Smallest is %d.\n", min(min(x, y), z));
//        printf("Largest is %d.\n", max(max(x, y), z));
}
