//
//  main.c
//  151-2
//
//  Created by Chang on 2023-03-19.
//

#include <stdio.h>
#include <string.h>

#define MAX_PROGRAMS 10
#define MAX_COURSES 10
#define MAX_CLASSES 10
#define MAX_STUDENTS 50

// Structure to store information about each course
struct Course {
    char name[50];
    int credit_hours;
};

// Structure to store information about each program
struct Program {
    char name[50];
    int num_courses;
    struct Course courses[MAX_COURSES];
    int num_classes;
    int num_students[MAX_CLASSES];
    int grades[MAX_CLASSES][MAX_STUDENTS][MAX_COURSES];
    float avg_grade;
};

int main() {
    // Collect information about the programs
    int num_programs;
    printf("Enter the number of programs: ");
    scanf("%d", &num_programs);
    struct Program programs[MAX_PROGRAMS];
    for (int i = 0; i < num_programs; i++) {
        printf("Enter the name of program %d: ", i+1);
        scanf("%s", programs[i].name);
        printf("Enter the number of courses in program %d: ", i+1);
        scanf("%d", &programs[i].num_courses);
        for (int j = 0; j < programs[i].num_courses; j++) {
            printf("Enter the name of course %d in program %d: ", j+1, i+1);
            scanf("%s", programs[i].courses[j].name);
            printf("Enter the credit hours for course %d in program %d: ", j+1, i+1);
            scanf("%d", &programs[i].courses[j].credit_hours);
        }
        printf("Enter the number of classes in program %d: ", i+1);
        scanf("%d", &programs[i].num_classes);
        for (int j = 0; j < programs[i].num_classes; j++) {
            printf("Enter the number of students in class %d in program %d: ", j+1, i+1);
            scanf("%d", &programs[i].num_students[j]);
            for (int k = 0; k < programs[i].num_students[j]; k++) {
                printf("Enter the grades for student %d in class %d in program %d:\n", k+1, j+1, i+1);
                for (int l = 0; l < programs[i].num_courses; l++) {
                    printf("Enter the grade for course %d: ", l+1);
                    scanf("%d", &programs[i].grades[j][k][l]);
                }
            }
        }
    }
    
    // Calculate the average grade for each program
    for (int i = 0; i < num_programs; i++) {
        int total_credit_hours = 0;
        float weighted_sum = 0.0;
        for (int j = 0; j < programs[i].num_courses; j++) {
            total_credit_hours += programs[i].courses[j].credit_hours;
            float course_weighted_sum = 0.0;
            for (int k = 0; k < programs[i].num_classes; k++) {
                for (int l = 0; l < programs[i].num_students[k]; l++) {
                    course_weighted_sum += programs[i].grades[k][l][j] * programs[i].courses[j].credit_hours;
                }
            }
            weighted_sum += course_weighted_sum;
        }
        programs[i].avg_grade = weighted_sum / total_credit_hours;
    }
    
    // Find
}
