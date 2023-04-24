//
//  main.c
//  178
//
//  Created by Chang on 2023-04-21.
//

//
//  main.c
//  176
//
//  Created by Chang on 2023-04-21.
//

#include <stdio.h>
#include <stdlib.h>

struct digit{
    int num;
    struct digit * next; // could we create a common pointer which point to this memory position.
};
struct digit *append(struct digit *end, struct digit *newDigitptr);
struct digit *createDigit(int dig);
void printNumber(struct digit *start);
struct digit * readNumber(struct digit *start);
struct digit * searchNumber(struct digit * start, int number);

int main(int argc, const char * argv[]) {
//struct digit *numberptr;
    struct digit *start;
    struct digit *end;
    struct digit *newDigitptr;
    struct digit *tmp;
    
    struct digit *ptr;
    
//    int digitToStore = 5;
    int first = 5;
    int second = 3;
    int third = 7;
//    int searchNum = NULL;
    int searchNum = 5;
    
    start = createDigit(first);
    end = start;
    newDigitptr = createDigit(second);
    end = append(end, newDigitptr);
    newDigitptr = createDigit(third);
    
//    numberptr = createDigit(third);
//    printf("We are storing the digit %d and the pointer %p at memory location %p. \n", numberptr->num, numberptr->next, numberptr;
    
    printNumber(start);
    
    ptr = searchNumber(start, searchNum);
    if(ptr != NULL){
        printf("Found the digit %d at location %p. \n", searchNum, ptr);
    }
    else {
        printf(" Digit %d not found. \n", searchNum);
    }
    
    tmp = start->next;
    free(start);
    start =tmp;
    tmp = start->next;
    free(start);
    free(tmp);
    
    free(newDigitptr);// this is missed, right?
    
    printf("\n\n");
    return 0;
}

struct digit *createDigit(int dig){
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
#warning the memory is free when new variable is assigned. line 44, 46, 48 ? we need free the three heap memory of pointer.
#error right?
    
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit *append(struct digit *end, struct digit *newDigitptr){
    end->next = newDigitptr;
    end = newDigitptr;
    return (end);
}

void printNumber(struct digit *start){
    struct digit *ptr = start;
    while (ptr != NULL) {
        printf("%d \n", ptr->num);
        ptr = ptr->next;
    }
    printf("\n\n");
}

struct digit * readNumber(){
    char c;
    int d;
    struct digit *start;
    struct digit *end;
    struct digit *newptr;
   
    start = NULL;
    end = start;
    scanf(" %c", &c);
    while(c != '\n'){
        d = c - 48;
        newptr = createDigit(d);
        if(start == NULL){
            start = newptr;
            end = start;
        }
        else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
        c = '\n';
    }
    return start;
}

struct digit * searchNumber(struct digit * start, int number){
    struct digit *ptr =start;
    while ((ptr !=NULL) && (ptr->num != number)) {
        ptr = ptr->next;
    }
    return (ptr);
}
