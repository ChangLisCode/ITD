//
//  main.c
//  160
//
//  Created by Chang on 2023-04-05.
//

#include <stdio.h>
#include <string.h>
struct my_second_structure{
    int number;
    char letter;
};

struct books{
    char title[30];
    char author[30];
    char subject[30];
    int id;
    int page_number;
};

struct Number{
    float x;
    float y;
};

struct number_structure2{
    float x;
    float y;
    float z;
};

struct number_structure3{
    float arr[4];
    float x,y,z;
    };

int main(int argc, const char * argv[]) {
    
    struct my_second_structure member1;
    struct Number number1, number2;
    
    member1.number = 10;
    member1.letter = 'N';
    
    printf("In the structure the number is %d!\n", member1.number);
    printf("In the structure the letter is %c", member1.letter);
    printf("\n\n----------------------\n\n");
    
    struct books Book1;
    struct books Book2;
    struct books Book3;
    
    strcpy(Book1.title, "How to do C Programming");
    strcpy(Book1.author, "a");
    strcpy(Book1.subject, "Programming");
    
    Book1.id = 1111111111;
    Book1.page_number = 400;
    
    strcpy(Book2.title, "How to do C++ programming");
    strcpy(Book2.author, "b");
    strcpy(Book2.subject, "Programming");
    Book2.id = 22222222;
    Book2.page_number = 500;
    
    strcpy(Book2.title, "How to do C++ programming");
    strcpy(Book2.author, "b");
    strcpy(Book2.subject, "Programming");
    Book3.id = 1111111111;
    Book3.page_number = 400;
    
    printf("Book1 title is %s\nBook1 author is %s\nBook1 subject is %s\nBook1 id is %d\nBook1 page number is %d",Book1.title,Book1.author,Book1.subject,Book1.id,Book1.page_number);
    printf("\n\n----------------------\n\n");

    printf("Book2 title is %s\nBook2 author is %s\nBook2 subject is %s\nBook2 id is %d\nBook2 page number is %d",Book2.title,Book2.author,Book1.subject,Book2.id,Book2.page_number);
    printf("\n\n----------------------\n\n");
    
    number1.x = 10.22;
    number1.y = 12.34;
    
    number2.x = 5.4 + (3 * number1.x) - (4 * number1.y);

    printf("The value of number1.x is: %lf. \n", number1.x);
    printf("The value of number2.x is: %lf. \n", number2.x);
    printf("\n\n----------------------\n\n");
    
    struct number_structure2 point1 = {1.535, 2.365, 3.351};
    struct number_structure2 *point2 = &point1;
    
    printf("The x value of point1 is: %lf\n", point2->x);
    printf("\n\n----------------------\n\n");
    
    struct number_structure3 point3 = {{1.535, 2.365, 3.351},4.5, 6.9};
    struct number_structure3 *point4 = &point3;
    printf("The arr[0] value of point1 is: %lf\n", point4->arr[0]);
    printf("The arr[1] value of point1 is: %lf\n", point4->arr[1]);
    printf("The arr[2] value of point1 is: %lf\n", point4->arr[2]);
    
    printf("\n\n----------------------\n\n");
    
    printf("The x value of point1 is: %lf\n", point4->x);
    printf("The y value of point1 is: %lf\n", point4->y);
    printf("The z value of point1 is: %lf\n", point4->z);
    printf("\n\n----------------------\n\n");
    
    return 0;
}
