//
//  main.c
//  159
//
//  Created by Chang on 2023-04-04.
//

#include <stdio.h>

struct point{
    int x, y, z;
};

struct point_2{
    int x, y, z;
    int array[3];
};

struct player{
    int x, y, z;
};

int main(int argc, const char * argv[]) {
    struct point p1 = {0,0,0};
    
    printf("%d%d%d\n\n", p1.x, p1.y,p1.z);
    
    p1.x = 1;
    p1.y = 2;
    p1.z = 3;
    
    printf("%d%d%d\n", p1.x, p1.y,p1.z);
    printf("\n");
    
    struct point_2 p1_2 ={
        .x = 4,
        .y = 5,
        .z = 6,
        .array = {7, 8, 9}
    };
    
    printf("%d%d%d\n\n", p1.x, p1.y,p1.z);
    printf("%d%d%d\n\n", p1_2.array[0], p1_2.array[1], p1_2.array[2]);
    printf("\n");
    
    struct player team_1[11];
    
    team_1[0].x = 11;
    team_1[0].y = 22;
    team_1[0].z = 33;
    
    team_1[1].x = 11;
    team_1[1].y = 22;
    team_1[1].z = 33;
    
    for (int i=0; i<11; i++) {
        team_1[i].x = i + p1.x;
        team_1[i].y = i + p1.y;
        team_1[i].z = i + p1.z;
    }
    printf("\n");
    
    for (int i=0; i<11; i++) {
        printf("%d\n", team_1[i].x);
        printf("%d\n", team_1[i].y);
        printf("%d\n", team_1[i].z);
        printf("\n");
    }
    
    
    printf("\n\n\n");
    return 0;
}
