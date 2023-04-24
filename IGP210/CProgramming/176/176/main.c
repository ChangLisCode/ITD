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
    struct digit * next;
};
struct digit *append(struct digit *end, struct digit *newDigitptr);
struct digit *createDigit(int dig);
void printNumber(struct digit *start);
struct digit * readNumber();

int main(int argc, const char * argv[]) {
//struct digit *numberptr;
    struct digit *start;
    struct digit *end;
    struct digit *newDigitptr;
    struct digit *tmp;
    
//    int digitToStore = 5;
    int first = 5;
    int second = 3;
    int third = 7;
    
    start = createDigit(first);
    end = start;
    newDigitptr = createDigit(second);
    end = append(end, newDigitptr);
    newDigitptr = createDigit(third);
    
//    numberptr = createDigit(third);
//    printf("We are storing the digit %d and the pointer %p at memory location %p. \n", numberptr->num, numberptr->next, numberptr;
    
    printNumber(start);

    tmp = start->next;
    free(start);
    start =tmp;
    tmp = start->next;
    free(start);
    free(tmp);
    printf("\n\n");
    return 0;
}

struct digit *createDigit(int dig){
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
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
    //while(c != '\n'){
        // This is coming from the sequence and orders we have in the ASCII table
        d = c - 48;
        newptr = createDigit(d);
        if(start == NULL){
            start = newptr;
            end = start;
        }
        else {
            end = append(end, newptr);
        }
        //scanf("%c", &c);
        //c = '\n';
    //}
    return start;
}

