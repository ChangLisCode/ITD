//
//  main.c
//  163 struct memory
//
//  Created by Chang on 2023-04-06.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct person{
    char name[30];
    char last_name[30];
    int age;
    float wage;
} person1;

typedef struct people{
    char name[30];
    char last_name[30];
    int age;
    float wage;
} person2;

struct pers{
    int age;
    double weight;
};

int main(int argc, const char * argv[]) {

    printf("Examp 1:\n");
    strcpy(person1.name, "James");
    person1.age = 55;
    person1.wage = 17.7;
    
    printf("The name of this person is %s. \n", person1.name);
    printf("The age of this person is %d. \n", person1.age);
    printf("The wage of this person is %lf. \n", person1.wage);
    printf("\n\n");
    
    printf("Example 2: \n");
    person2 student1;
    strcpy(student1.name, "Peter");
    student1.age = 55;
    student1.wage = 14.4;
    
    printf("The name of this person is %s. \n", person1.name);
    printf("The age of this person is %d. \n", person1.age);
    printf("The wage of this person is %lf. \n", person1.wage);
    printf("\n\n");
    
//    pointer
    printf("Example 3:\n");
    struct pers *personPtr, person11;
    personPtr = &person11;
    
    printf("Please, insert the age of this person: \n");
    scanf("%d", &personPtr->age);
    
    printf("Please, insert the age of this person: \n");
    scanf("%lf", &personPtr->weight);
    
    printf("Please, insert the age of this person: \n");
    scanf("%d", &personPtr->age);
    
    printf("the age of this person is: %d.\n", personPtr->age);
    printf("the age of this person is: %.2f.\n", personPtr->weight);

    struct person *ptr;
    int n=0;
    
    ptr = (struct person*) malloc(n * sizeof(struct person));
    
    for (int i=0; i<n; i++){
        
        printf("Insert the name followed by the age of the person, separated with a space:");
        scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
    }
    
    for (int i=0; i<n; i++) {
        printf("Name: %s - Age:%d \n", (ptr+i)->name, (ptr+i)->age);
    }
    
    free(ptr);
    
    return 0;
}
