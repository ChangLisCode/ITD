//
//  main.c
//  197 C exam
//
//  Created by Chang on 2023-04-27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct title {
    char titles[50];
    char Mr[50];
    char Mrs[50];
    char Miss[50];
};

struct Date_of_birth {
    int day;
    char month[10];
    int year;
};

struct institution_address {
    char street[50];
    char city[50];
    char province[50];
    char postal_code[50];
};

struct home_address {
    char street[50];
    char city[50];
    char province[50];
    char postal_code[50];
};

struct student {
    int student_id;
    struct title theTitle;
    char first_name[50];
    char last_name[50];
    struct Date_of_birth dob;
    int semester_number;
    char program[50];
    struct institution_address ins_address;
    struct home_address home_address;
    struct student *next;
};

struct student* createStudent(int num);
void printStudent(struct student* new_student);
void printStudentsbyID(struct student *start);
struct student* append(struct student *end, struct student *newptr);
struct student* initialTemp(int num);

int main() {
    
    int i, num=0;
    struct student *ptr, *start, *end;
    struct student* temp;
    
// initialization the struct
    temp = initialTemp(num);
    
    start = end = temp;
    
    printf("Hi, How many students will you create:\n");
    scanf("%d", &num);
    
// input student information
    for (i=0; i<num; i++) {
        ptr = createStudent(num);
        
        if(i == 0){
            start = end = ptr;
        }
        else{
            end = append(end, ptr);
        }
        
        printStudent(ptr);
        
    }
    
    printf("student input is finished.\n");
    
    
// searching task based on the input student ID
    printf("Now we do some searching task.\n");

    printStudentsbyID(start);
    
// free heap memory
    for (i=0; i<num; i++) {
        free(start);
    }
    
    printf("system finish running successfuly! See you next time!\n\n");

    return 0;
}

struct student* initialTemp(int num){
    struct student *temp = (struct student *)malloc(sizeof(struct student));
    temp->student_id = num;
    strcpy(temp->theTitle.titles, "");
    strcpy(temp->theTitle.Mr, "");
    strcpy(temp->theTitle.Mrs, "");
    strcpy(temp->theTitle.Miss, "");
    strcpy(temp->first_name, "");
    strcpy(temp->last_name, "");
    temp->dob.day = 0;
    strcpy(temp->dob.month, "");
    temp->dob.year = 0;
    temp->semester_number = 1;
    strcpy(temp->program, "");
    strcpy(temp->ins_address.street, "");
    strcpy(temp->ins_address.city, "");
    strcpy(temp->ins_address.province, "");
    strcpy(temp->ins_address.postal_code, "");
    strcpy(temp->home_address.street, "");
    strcpy(temp->home_address.city, "");
    strcpy(temp->home_address.province, "");
    strcpy(temp->home_address.postal_code, "");
    temp->next = NULL;
    
    return temp;
}

// task 1
struct student* createStudent(int num) {
    struct student* new_student;
    new_student = (struct student * ) malloc(sizeof(struct student));
    
    printf("Please input student id: \n");
    scanf("%d", &new_student->student_id);
    
    printf("Please input student gender: \n");
    scanf("%s", new_student->theTitle.titles);
    
    printf("Please input student first_name: \n");
    scanf("%s", new_student->first_name);

    printf("Please input student last_name: \n");
    scanf("%s", new_student->last_name);

    printf("Please input student dob day: \n");
    scanf("%d", &new_student->dob.day);

    printf("Please input student dob month: \n");
    scanf("%s", new_student->dob.month);

    printf("Please input student dob year: \n");
    scanf("%d", &new_student->dob.year);

    printf("Please input student semester number: \n");
    scanf("%d", &new_student->semester_number);

    printf("Please input student program: \n");
    scanf("%s", new_student->program);

    printf("Please input student home address street: \n");
    scanf("%s", new_student->home_address.street);
    
    printf("Please input student home address city: \n");
    scanf("%s", new_student->home_address.city);
    
    printf("Please input student home address province: \n");
    scanf("%s", new_student->home_address.province);
    
    printf("Please input student home address postal_code: \n");
    scanf("%s", new_student->home_address.postal_code);
    
    printf("Please input student institutions street: \n");
    scanf("%s", new_student->ins_address.street);
    
    printf("Please input student institution city: \n");
    scanf("%s", new_student->ins_address.city);
    
    printf("Please input student institution province: \n");
    scanf("%s", new_student->ins_address.province);
    
    printf("Please input student institution postal_code: \n");
    scanf("%s", new_student->ins_address.postal_code);
    
    printf("Please input next student\n");
    
    new_student->next = NULL;

    printf(" input is done. Thanks!\n\n");
    
    return new_student;
}

void printStudent(struct student* new_student) {
    
    printf("New student created:\n %s %s(Gender: %s) with student ID %d was born on %d/%s/%d and he is %d years old now.\nHe studies %s at ITD Canada located at %s %s, %s, %s and his Home address is %s %s, %s, %s", new_student->first_name, new_student->last_name, new_student->theTitle.titles, new_student->student_id,new_student->dob.day,new_student->dob.month, new_student->dob.year, (2023-new_student->dob.year), new_student->program, new_student->ins_address.street, new_student->ins_address.city, new_student->ins_address.province, new_student->ins_address.postal_code, new_student->home_address.street,new_student->home_address.city,new_student->home_address.province, new_student->home_address.postal_code);
    
    printf("print is done. Thanks!\n\n");

                      
}
// task 2
struct student * append(struct student *end, struct student *newptr){
    end -> next = newptr;
    return (end->next);
}

// task 3
void printStudentsbyID(struct student *start){
    struct student *ptr;
    ptr = start;
    
    int id;
    while (ptr != NULL) {
        printf("Please input the student ID:\n");
        scanf("%d", &id);
        if(ptr->student_id == id){
            printStudent(ptr);
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    
    printf("Searching is finised.Thanks!\n\n");

}

// task 4
void freeStudent(struct student *ptr){
    struct student *start = ptr;
    while (start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    printf("Memory free is done. Thanks!\n\n");
}
