//
//  main.c
//  172 struct pointer
//
//  Created by Chang on 2023-04-20.
//

#include <stdio.h>
#include <stdlib.h>

struct datasheet{
    int x;
    int y;
    struct datasheet *ptr0;
};

void printPoints(struct datasheet *start);
struct datasheet * append(struct datasheet *end, struct datasheet *newptr);
struct datasheet * createPoint(int x, int y);
void freePoint(struct datasheet *ptr);

int main(int argc, const char * argv[]) {
            
    int num;
    int i;
    int x;
    int y;
    struct datasheet *start, *end, *newptr;
    struct datasheet date0 = {0,0,NULL};
    start = end = &date0;
    
    printf("Please insert he number of nodes you would like to create\n");
    scanf("%d", &num);
    
    for(i=0; i<num; i++){
        printf("Please insert the value of first element:\n");
        scanf("%d",&x);
        printf("second value of element.\n");
        scanf("%d", &y);
        
        newptr = createPoint(x,y);
        
        if(i == 0){
            start = end = newptr;
        }
        else {
            end = append(end, newptr);
        }
    }
        printf(" the value you inserted is: \n");
        printPoints(start);
        free(start);
        return 0;
}

void printPoints(struct datasheet *start){
    struct datasheet *ptr;
    ptr = start;
    while (ptr != NULL){
        printf("%d, %d\n", ptr->x, ptr->y);
        ptr = ptr->ptr0;
    }
}

struct datasheet * append(struct datasheet *end, struct datasheet *newptr){
    end -> ptr0 = newptr;
    return (end->ptr0);
}

struct datasheet *createPoint(int x, int y){
    struct datasheet *ptr;
    ptr = (struct datasheet *) malloc(sizeof(struct datasheet));
    ptr->x = x;
    ptr->y = y;
    ptr->ptr0 = NULL;
    
    //    free(ptr);
    //    what time should the ptr be free?
    return ptr;
}

void freePoint(struct datasheet *ptr){
    struct datasheet *start = ptr;
    while (start != NULL) {
        ptr = start;
        start = start->ptr0;
        free(ptr);
    }
}
