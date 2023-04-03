//
//  main.c
//  150
//
//  Created by Chang on 2023-03-17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocateString(int n) {
    char* ptr = (char*) malloc(n * sizeof(char));
    return ptr;
}

int main() {
    int n1, n2;
    char* light, * dark;
    printf("please input:\n");
    
    scanf("%d %d", &n1, &n2);
    light = allocateString(n1);
    dark = allocateString(n2);
    
    scanf("%s %s", light, dark);
    printf("Local settings: %s - %s\n", light, dark);
    
    free(light);
    free(dark);
    
    return 0;
}
