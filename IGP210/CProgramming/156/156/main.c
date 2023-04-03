//
//  main.c
//  156
//
//  Created by Chang on 2023-03-21.
//

#include <stdio.h>

int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float m1, b1, m2, b2;
    float x_intersect, y_intersect;

    printf("Enter the coordinates of the first point (x1 y1): \n");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): \n");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third point (x3 y3): \n");
    scanf("%f %f", &x3, &y3);
    printf("Enter the coordinates of the fourth point (x4 y4): \n");
    scanf("%f %f", &x4, &y4);
    printf("\n\n");
    
    m1 = (y2 - y1) / (x2 - x1);
    b1 = y1 - m1 * x1;

    m2 = (y4 - y3) / (x4 - x3);
    b2 = y3 - m2 * x3;

    if (m1 == m2) {
        if (b1 == b2) {
            printf("identical,there are an infinite number of solutions.\n");
        } else {
            printf("no solutions,the two lines are parallel and do not intersect.\n");
        }
    } else {
        x_intersect = (b2 - b1) / (m1 - m2);
        y_intersect = m1 * x_intersect + b1;
        printf("The intersection point of the two lines is (%f, %f).\n", x_intersect, y_intersect);
    }
    
    printf("\n\n");
    return 0;
}
