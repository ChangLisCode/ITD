//
//  main.cpp
//  project5
//
//  Created by Chang on 2023-01-30.
//

/* Q 34
#include <iostream>
int main(void) {
    int i;

    printf ("Welcome,humans!\n");
    printf ("I am Buttons, your robot instructor! \n");
    printf ("Today we are going to learn how to love robots :) \n");
    printf ("Repeat after me: \n");

    for (i = 0; i < 3; i++){
        printf ("I love Buttons!\n");
        printf ("Still not convinced? n");
        printf ("In that case, let me explain some more ... \n");

    for (i = 0; i < 200; i++) {
        printf ("We come in peace and kindness! \n");
        printf ("A robot cannot hurt a human being or ");
        printf ("allow a human being to be hurt. ");
    }
*/
/*
        printf ("This is the end of today's lesson! ");
        printf ("Thank you for your cooperation, and");
//        printf ("goodbye!");

//    return(0);

}
    return 0;
}
*/

/* Q35
#include <iostream>
int main(void) {
    int i;
    
    for(i=1; i<21; i++){
        printf("multiples is %d * 4 = %d \n",i, i*4);
        
    }
    return i;
}
*/

/* Q36
#include <iostream>
int main(void) {
    int i;
    int j;
    for(i=1; i<11; i++){
        for(j=1; j<11; j++){
            printf("multiples is %d * %d = %d \n",i, j, i*j);
        }
 }
return i;
}
 */

/* Q37
#include <iostream>
int main(void) {
    int i;
    int j;
    for(i=1; i<8; i++){
        for(j=1; j<8; j++){
            printf("multiples is %d * %d = %d \n",i, j, i*j);
        }
 }
return i;
}
 */

/*
#include <stdio.h>

int main()
{
    int num, i, j;
    printf("Inserted Number: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= num; j++)
        {
            printf("%d*%d=%d\n", i, j, i*j);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int i, result;
    for (i = 1; i <= 20; i++)
    {
        result = i * 4;
        printf("%d*4 = %d\n", i, result);
    }
    return 0;
}

 */

/* Q38

#include<stdio.h>

int main()
{
    int n, i, j;
    printf("Insert an integer: ");
    scanf("%d", &n);

    if (n > 99 || n < 10)
    {
        printf("Invalid input. Please insert a 2-digit integer.\n");
        return 0;
    }

    printf("Group of Even Numbers:\n");
    for (i = 10; i <= n; i+=2)
    {
        for (j = 1; j <= 12; j++)
        {
            printf("%d * %d = %d\n", j, i, i*j);
        }
        printf("\n");
    }

    printf("Group of Odd Numbers:\n");
    for (i = 11; i <= n; i+=2)
    {
        for (j = 1; j <= 12; j++)
        {
            printf("%d * %d = %d\n", j, i, i*j);
        }
        printf("\n");
    }

    printf("this assignment is finished!");
    return 0;
}

 */

/* Q38-2
#include <stdio.h>

int main() {
  int input, i, j;
  printf("Enter a 2-digit integer: ");
  scanf("%d", &input);

  if (input >= 10 && input <= 99) {
    printf("\nGroup of Even Numbers:\n");
    for (i = 10; i <= input; i++) {
      if (i % 2 == 0) {
        for (j = 1; j <= i; j++) {
          printf("%d * %d = %d\n", j, i, i * j);
        }
      }
    }

    printf("\nGroup of Odd Numbers:\n");
    for (i = 11; i <= input; i++) {
      if (i % 2 != 0) {
        for (j = 1; j <= i; j++) {
          printf("%d * %d = %d\n", j, i, i * j);
        }
      }
    }
  } else {
    printf("Invalid input.\n");
  }

  return 0;
}

*/

//Q39

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
