//
//  main.c
//  164 struct pointer
//
//  Created by Chang on 2023-04-11.
//

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

struct student_address
{
    int street_number;
    char *state;
    char *city;
    char *country;
};

//  creating nested structures
struct student_data
{
    int student_id;
    int student_age;
    char *student_name;
    struct student_address stuAddress;
};

void printStudent(struct student stud);
void readStudent(struct student *studptr);
void printStudent(struct student stud);
void printStudentNestInfo(struct student_data mydata);

int main() {

    struct student me = {"Alex", "Brandon", 1985, 3.9};
//    struct student you = {"Remi", "Peter", 2000, 3.87};
    struct student readInfo;
//    Assignment 164: pass struct directly to a function.
    printStudent(me);
    
//    Assignment 165: passing a structure to a function using a pointer.
    readStudent(&readInfo);
    
//    Assignment 166: creating nested structures.
    struct student_data mydata;
    mydata.student_id = 2222;
    mydata.student_age = 23;
    mydata.student_name = "Alex";
    
    mydata.stuAddress.state = "BC";
    mydata.stuAddress.street_number = 12345;
    mydata.stuAddress.city = "Surrey";
    mydata.stuAddress.country = "Canada";
    
    printStudentNestInfo(mydata);
    
    printf("\n\n");
    return 0;
}

void printStudent(struct student stud)
{
    printf("first name of the student: %s\n", stud.firstName);
    printf("last name of the student: %s.\n", stud.lastName);
    printf("birth year of student: %d.\n", stud.birthYear);
    printf("average grade of student: %lf. \n", stud.aveGrade);
}

void readStudent(struct student *studptr){
    printf("please insert the first name\n ");
    scanf("%s", (*studptr).firstName);
    
    printf("please insert the last name\n ");
    scanf("%s", (*studptr).firstName);
    
    printf("please insert the birth year\n ");
    scanf("%d", &(*studptr).birthYear);
    
    printf("please insert the average grade\n ");
    scanf("%lf", &(*studptr).aveGrade);
};

void printStudentNestInfo(struct student_data mydata){
    printf("%s", mydata.stuAddress.state);
    printf("%d", mydata.stuAddress.street_number);
    printf("%s", mydata.stuAddress.city);
    printf("%s", mydata.stuAddress.country);
};
