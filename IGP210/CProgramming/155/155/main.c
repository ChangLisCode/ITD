//
//  main.c
//  155
//
//  Created by Chang on 2023-03-20.
//

#include <stdio.h>

int main() {
    float x1, y1, x2, y2, slope, y_intercept;

    printf("Enter point 1 (x,y): ");
    scanf("%f,%f", &x1, &y1);

    printf("Enter point 2 (x,y): ");
    scanf("%f,%f", &x2, &y2);

    printf("\n\n");
    
    if (x1 == x2) {
        printf("The line connecting the two points is vertical.\n");
        printf("The equation of the line is x = %.2f\n", x1);
    }
    else if (y1 == y2) {
        printf("The line connecting the two points is horizontal.\n");
        printf("The equation of the line is y = %.2f\n", y1);
    }
    else {
        slope = (y2 - y1) / (x2 - x1);
        y_intercept = y1 - slope * x1;

        printf("The slope of the line connecting the two points is %.2f.\n", slope);

        if (slope > 0) {
            printf("The line has a positive slope.\n");
        }
        else {
            printf("The line has a negative slope.\n");
        }

        printf("The equation of the line is y = %.2fx + %.2f\n", slope, y_intercept);
    }
    
    printf("\n\n");
    return 0;
}
