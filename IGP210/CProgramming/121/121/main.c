//
//  main.c
//  121
//
//  Created by Chang on 2023-03-07.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int a = 5;
    const int *ptr;
    ptr = &a;
//    *ptr = 10;
    printf("%d\n", a);
    return 0;

}
