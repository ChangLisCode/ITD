//
//  main.c
//  173
//
//  Created by Chang on 2023-04-20.
//

//
//  main.c
//  172 struct pointer
//
//  Created by Chang on 2023-04-20.
//

#include <stdio.h>

struct datasheet{
    int x;
    int y;
    struct datasheet *ptr0;
};

void printPoints(struct datasheet *start);
append(struct datasheet *end, struct datasheet *newptr);

int main(int argc, const char * argv[]) {
    
    struct datasheet sheet1 = {1, 3, NULL};
    struct datasheet sheet2 = {3, 4, NULL};
    struct datasheet sheet3 = {-3, 6, NULL};
    struct datasheet *ptr1, *ptr2;
    
    printf("Please insert the number of nodes you would like to create?\n");
    
    int num;
    int i;
    int x;
    int y;
    struct datasheet *start173, *end173, *newptr173;
    
    printf("Please insert he number of nodes you would like to create");
    scanf("%d", &num);
    
    for(i=0; i<num; i++){
        printf("Please insert the value of first element:\n");
        scanf("%d",&x);
        printf("second value of element.\n");
        scanf("%d", &y);
        
        newptr = createPoint(x,y);
        if(i ==0){
            start173 = end173 = newptr173;
        }
        else {
            end = append(end173, newptr173);
        }
        printf(" the value you inserted is: \n");
        printPoints(start173);
        return 0;
    }
}

void printPoints(struct datasheet *start){
    struct datasheet *ptr;
    ptr = start;
    while (ptr != NULL){
        printf("%d %d\n", ptr->x, ptr->y);
        ptr = ptr->ptr0;
    }
}

append(struct datasheet *end, struct datasheet *newptr){
    end -> ptr0 -> newptr;
    return (end->ptr0);
}

