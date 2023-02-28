//
//  main.c
//  99-2
//
//  Created by Chang Li on 2023-02-27.
//

#include <stdio.h>
int main() {
    int n, length, bytes = 0;
    char type;
    printf("Enter the number of tracking codes: ");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the length and type of tracking code %d: ", i + 1);
        scanf_s("%d %c", &length,&type);
        if (type == 'i') {
            bytes += length * sizeof(int);
        }
        else if (type == 'd') {
            bytes += length * sizeof(double);
        }
        else if (type == 'c') {
            bytes += length * sizeof(char);
        }
        else {
            printf("Invalid tracking code type\n");
            return 0;
        }
    }
    printf("Total amount of space required to store all of the tracking codes: %d bytes\n", bytes);
    return 0;
}
