//
//  main.c
//  128
//
//  Created by Chang on 2023-03-09.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int count) {
//rolling two dice and return sum.
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    
    return dice1 + dice2;
}

int playCraps(int count) {

// craps and return 1 if the player wins, 0 otherwise.
    int point = 0;
    int total = rollDice(count);
        
    if ((total == 7 || total == 11) && count == 1) {
        printf("Rolling %d time,you are the winner!\n\n", count);
        return 1;
    }
    
    else if ((total == 2 || total == 3 || total == 12)&& count == 1) {
        printf("Rolling %d time,you lose!\n\n", count);
        return 0;
    }
    
    else if (total == 7 && count >1){
        printf("Rolling %d time,you lose!\n\n", count);
        return 0;
    }
        
    else {
        point += total;
        printf("Point is %d.\nYou need continue rolling the dice.\n\n", point);
        
        if(point >= 21){
            printf("Rolling %d time,you are the winner!\n\n", count);
            total = 1;
        }
        else {
            playCraps(count);
        }
        return total;
    }
}

int main() {
    int count = 1, point = 0, result;
    int win = 0;
    srand(time(NULL));
// Seed the random number generator with the current time.

    for (int i = 0; i < 7; i++) {
        result = playCraps(count);
        if (result == 1){
            win++;
            printf(" result %d, win %d", result, win);
        }
        count++;
    }
    
    printf("Player won %d out of 7 games.\n\n", win);
    
    return 0;
}
