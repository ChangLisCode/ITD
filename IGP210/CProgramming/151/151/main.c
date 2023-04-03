//
//  main.c
//  151
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

void input_information(int program_num, char array_program_name, int student_num, int class_num){
    
    printf("%d \n", program_num);
    for (int i = 0; i < program_num; i++) {
        printf("please input the name of the programs:\n");
        scanf("%s", &array_program_name);
        printf("%d\n", i);
    }
    
    printf("please input the number of classes in each program:\n");
    scanf("%d", &class_num);
    
    printf("please input the number of students in each class:\n");
    scanf("%d", &student_num);
}

struct myStructure {
  int program_no;
  char program_name;
};

int main() {
    
    int student_num, program_num, class_num, array_len;
    int program_credit[] = {1,4,3,2,5};
    int average_grade[5];
    
    printf("please input program number:\n");
    scanf("%d", &program_num);
    
    array_len = allocateString(program_num);
    
    char array_program_name[array_len];
        
    input_information(program_num, array_program_name, student_num, class_num);
    
    
    
    
//
//    average_grade[0]= Sum(Credit Hour * Course Average Grade))/program_credit;
//
//
//
//    input_information(, <#int n#>, <#int p#>)
//    scanf("%d %d", &n1, &n2);
//    light = allocateString(n1);
//    dark = allocateString(n2);
//
//    scanf("%s %s", light, dark);
//    printf("Local settings: %s - %s\n", light, dark);
//
//    free(light);
//    free(dark);
//
    return 0;
}

