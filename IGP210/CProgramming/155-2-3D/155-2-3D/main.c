//
//  main.c
//  155-2-3D
//
//  Created by Chang on 2023-03-20.
//

#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, z1, x2, y2, z2, x=0, y=0, z=0;

    printf("Enter point 1 (x,y,z): ");
    scanf("%f,%f,%f", &x1, &y1, &z1);

    printf("Enter point 2 (x,y,z): ");
    scanf("%f,%f,%f", &x2, &y2, &z2);

    printf("\n\n");
    
//    d[3] = {{x2 - x1}, {y2 - y1}, {z2 - z1}};
    
//    x = x1 + (x2 - x1) * t;
//    y = y1 + (y2 - y1) * t;
//    z = z1 + (z2 - z1) * t;
    printf("The parametric equation of the line is:\n");
    
    printf("x = %f + (%f - %f) * t \n", x1, x2, x1);
    printf("y = %f + (%f - %f) * t \n", y1, y2, y1);
    printf("z = %f + (%f - %f) * t \n", z1, z2, z1);
    

    printf("The symmetric equation of the line is:\n (x - %f)/(%f - %f)=(y - %f)/(%f - %f)= (z - %f)(%f - %f) \n", x1, x2, x1, y1, y2, y1, z1, z2, z1);

    
    printf("\n\n");
    return 0;
}
