//
//  main.c
//  54
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
int x, y, z;
int i;

printf("Enter three integers: ");
scanf("%d%d%d", &x, &y, &z);

// Sorting the numbers in ascending order
if (x > y) {
i = x;
x = y;
y = i;
}
if (y > z) {
i = y;
y = z;
z = i;
}
if (x > y) {
i = x;
x = y;
y = i;
}

printf("The sorted numbers are: %d, %d, %d\n", x, y, z);

return 0;
}
