//
//  main.c
//  38
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>


int main()
{
    int n, i, j;
    printf("Insert an integer: ");
    scanf("%d", &n);

    if (n > 99 || n < 10)
    {
        printf("Invalid input. Please insert a 2-digit integer.\n");
        return 0;
    }

    printf("Group of Even Numbers:\n");
    for (i = 10; i <= n; i+=2)
    {
        for (j = 1; j <= 12; j++)
        {
            printf("%d * %d = %d\n", j, i, i*j);
        }
        printf("\n");
    }

    printf("Group of Odd Numbers:\n");
    for (i = 11; i <= n; i+=2)
    {
        for (j = 1; j <= 12; j++)
        {
            printf("%d * %d = %d\n", j, i, i*j);
        }
        printf("\n");
    }

    printf("this assignment is finished!");
    return 0;
}
