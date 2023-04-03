//
//  main.c
//  129
//
//  Created by Chang on 2023-03-09.
//

#include <stdio.h>

int main() {
    
//! showMemory(start=2775)
    short a[3] = {234, 655, 843};
    short b[2] = {32, 42};
    short c[4] = {2322, 3422, 532};
    
    short *arrays[3] = {a,b,c};
    
    *arrays[0] = 0;
    arrays[0][0] = 5;
    
    *(arrays[0] + 1) = 6;
    *(arrays[0] + 2) = 7;
    
    *arrays[1] = 1;
    *(arrays[1] +1) = 2;
    
    arrays[0][0] = 11;
    arrays[0][1] = 12;
    arrays[0][2] = 13;
    
    arrays[1][0] = 15;
    arrays[1][1] = 25;
    
    arrays[2][0] = 35;
    arrays[2][1] = 45;
    arrays[2][2] = 55;
    arrays[2][3] = 65;
    
    return 0;
}
