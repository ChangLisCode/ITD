//
//  main.c
//  126-2
//
//  Created by Chang on 2023-03-08.
//

#include <stdio.h>

void behind(int *scores, int num_players) {
    int max_score = *scores;
    for (int i = 1; i < num_players; i++) {
        if (*(scores + i) > max_score) {
            max_score = *(scores + i);
        }
    }
    for (int i = 0; i < num_players; i++) {
        *(scores + i) = max_score - *(scores + i);
    }
}

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    int scores[10];
    for (int i = 0; i < num_players; i++) {
        printf("Enter the score of player %d: ", i+1);
        scanf("%d", scores + i);
    }

    behind(scores, num_players);

    printf("Points behind the top-scoring player:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i+1, *(scores + i));
    }
    return 0;
}
