//
//  main.c
//  57
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>
int main() {

int array_1[3];

printf("Enter 3 integers for array1: \n");
for (int i = 0; i < 3; i++) {
scanf("%d", &array_1[i]);
}

float array_2[3] = {1.1, 2.2, 3.3};

char array_3[3];
printf("Enter 3 characters for array3: \n");
for (int i = 0; i < 3; i++) {
scanf(" %c", &array_3[i]);
}




for (int i = 0; i < 3; i++) {
printf("%d\n", array_1[i]);
}


for (int i = 0; i < 3; i++) {
printf("%.3f\n", array_2[i]);
}


for (int i = 0; i < 3; i++) {
printf("%c\n", array_3[i]);
}

return 0;
}
