//
//  main.c
//  40
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    int i;
    int number01;
    int height;
    int weight;
    int powerEngine;
    int resistanceRating;
    int powerRobot=0;
    
    printf("Please input the number of robot: \n");
    scanf("%d", &number01);
    
    for (i=0; i<number01; i++){
        printf("Please input the height of robot %d: \n", i+1);
        scanf("%d", &height);
        printf("Please input the weight of robot %d: \n", i+1);
        scanf("%d", &weight);
        printf("Please input the power engine of robot %d: \n", i+1);
        scanf("%d", &powerEngine);
        printf("Please input the resistance rating of robot %d: \n", i+1);
        scanf("%d", &resistanceRating);
        powerRobot += (powerEngine + resistanceRating) *  (weight - height);
        printf("\n\n");
    }
    return powerRobot;
}
