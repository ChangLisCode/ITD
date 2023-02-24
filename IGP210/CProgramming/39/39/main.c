//
//  main.c
//  39
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    int age;
    age = 10;
    
    printf("I am %d years old.\n\n", age);              // use %d

    
    double height;
    height = 1.877777777777777777777;
    float height1;
    height1 = height;
    
    printf("I am %lf meters tall.\n", height);          // use %lf   letter"l"
    printf("I am %1f meters tall.\n", height);          // use %1f   number"l"
    printf("I am %.lf meters tall.\n", height);         // use %.lf  letter"l"
    printf("I am %.1f meters tall.\n", height);         // use %.1f  number"1"
    printf("I am %.2f meters tall.\n", height);
    printf("I am %.3f meters tall.\n", height);
    printf("I am %.6f meters tall.\n", height);
    printf("\n\n");
    
    printf("I am %lf meters tall.\n", height1);          // use %lf   letter"l"
    printf("I am %1f meters tall.\n", height1);          // use %1f   number"l"
    printf("I am %.lf meters tall.\n", height1);         // use %.lf  letter"l"
    printf("I am %.1f meters tall.\n", height1);         // use %.1f  number"1"
    printf("I am %.2f meters tall.\n", height1);
    printf("I am %.3f meters tall.\n", height1);
    printf("I am %.6f meters tall.\n", height);
    
    printf("\n\n");
    
    
    double weight;
    weight = 71.56;
    
    printf("I am %lf Kg..\n", weight);         // use %1f
    printf("I am %.1f Kg.\n", weight);         // use %.1f number '1'
    printf("I am %.2f Kg.\n", weight);
    printf("I am %.3f Kg.\n", weight);
    printf("I am %.8f Kg.\n", weight);
    printf("I am %.14f Kg.\n", weight);
    
    
    int age1;
    age1 =30;
    
    float height2;
    height2 = 1.89;
    
    
    float weight1;
    weight1 =70.54;
    
    float size1;
    size1 = 10.120323;
    
    double test;
    float test1;
    test = 10.23323574342563;
    test1 = test;
    
    double test2;
    float test3;
    test2 = 10.857738665729;
    test3 = test2;
    
    double test4;
    float test5;
    test4 = 10.48594988439;
    test5 = 10.48594988439;
    
    double test6;
    float test7;
    test6 = 10.48594988439;
    test7 = 10.48594988439;
    
    printf("\n\n");
    
    printf("My test value is 0 double data type %lf.\n", test);          // double float include 8 byte, double date receive round value
    printf("My test value is 1 float data type %1f.\n", test1);         // float include 4 byte, receive the value of test2.
    
    printf("\n\n");
    
    printf("My test value is 2 double data type %lf.\n", test2);   // double include 8 byte, double date type receive round value.
    printf("My test value is 3 float data type %lf.\n", test3);    // float include 4 byte, receive the value of test2.
    
    printf("\n\n");
    
    printf("My test value is 4 double data type %lf.\n", test4);
    printf("My test value is 5 float data type %lf.\n", test5);
    
    printf("My test value is 6 double data type %lf.\n", test6);
    printf("My test value is 7 float data type %lf.\n", test7);
   }
