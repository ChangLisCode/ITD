//
//  main.c
//  44
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    double x=1;
    float y=2;

//    printf("Please enter the distance in kilometers: \n\n");
//    scanf("%lf %lf", &x, &y);
//
//    printf("Please enter the temperature in centigrade: \n\n");
//    scanf("%lf", &y);

    printf("the distance in miles is: %lf miles.\n", x * 0.621371445454535343453);

    printf("the distance in miles is: %.2f °F.\n", (y*9/5) + 32.453535242432424242);

}
