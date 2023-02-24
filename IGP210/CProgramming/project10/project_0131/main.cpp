//
//  main.cpp
//  project_0131
//
//  Created by Chang on 2023-01-31.
//

//Q40

/*
#include <iostream>

int main() {
    int i;
    int number01;
    int height;
    int weight;
    int powerEngine;
    int resistanceRating;
    int powerRobot=0;
    
    printf("Please input the number of robot: \n");
    scanf("%d", &number01);
    
    for (i=0; i<number01; i++){
        printf("Please input the height of robot %d: \n", i+1);
        scanf("%d", &height);
        printf("Please input the weight of robot %d: \n", i+1);
        scanf("%d", &weight);
        printf("Please input the power engine of robot %d: \n", i+1);
        scanf("%d", &powerEngine);
        printf("Please input the resistance rating of robot %d: \n", i+1);
        scanf("%d", &resistanceRating);
        powerRobot += (powerEngine + resistanceRating) *  (weight - height);
        printf("\n\n");
    }
    return powerRobot;
}
*/

//Q41

/*
 

a) printf("The value is %d\n", number);
b) scanf("%d%d", &number1, &number2);
c) if (c < 7){
printf("C is less than 7");
}
d) if (c >= 7) {
printf("C is greater than or equal to 7");
}
 */

/*Q42
// Write a statement (or comment) to accomplish each of the following:
#include <iostream>

int main() {
    // a) State that a program will calculate the product of three integers.
    printf("This program will calculate the product of three integers\n\n");
    
    // b) Prompt the user to enter three integers.
    printf("Please enter the integers: \n\n");
    
    // c) Define the variable x to be of type int and initialize it to 0.
    int x = 0;
    
    // d) Define the variable y to be of type int and initialize it to 0.
    int y = 0;
    
    // e) Define the variable z to be of type int and initialize it to 0.
    int z = 0;
    
    int product;
    
    // f) Read three integers from the keyboard and store them in variables x, y, and z.
    
    scanf("%d", &x);
    printf("Please enter the integers: \n\n");
    scanf("%d", &y);
    printf("Please enter the integers: \n\n");
    scanf("%d", &z);
    
    // g) Define the variable result, compute the product of the integers in the variables x, y, and z, and use that product to initialize the variable result.
    product = x * y * z;
    
    // h) Display "The product is" followed by the value of the int variable result.
    printf("The product is %d \n", product);
}
*/

/* Q43
#include <iostream>

int main() {
    int x = 0;
    
//    7 + 3 * 6 / 2 - 1, first: 3*6, second: /2, third: +7 -1
    printf("the value of x-1 is: %d\n", 7 + 3 * 6 / 2 - 1);
    
//    2 % 2 + 2 * 2 - 2 / 2, first: 2%2, 2*2, 2/2, second: + and -
    printf("the value of x-2 is: %d\n", 2 % 2 + 2 * 2 - 2 / 2);
    
//    (3 * 9 * (3 + (9 * 3 / (3)))), first: 9*3/3, second 3+(), third:3*9*()
    printf("the value of x-3 is: %d\n",  (3 * 9 * (3 + (9 * 3 / (3)))));
}
 */

/* Q44 */
#include <iostream>

int main() {
    double x=1;
    float y=2;

//    printf("Please enter the distance in kilometers: \n\n");
//    scanf("%lf %lf", &x, &y);
//
//    printf("Please enter the temperature in centigrade: \n\n");
//    scanf("%lf", &y);

    printf("the distance in miles is: %lf miles.\n", x * 0.621371445454535343453);

    printf("the distance in miles is: %.2f °F.\n", (y*9/5) + 32.453535242432424242);

}

/* Q45
#include <stdio.h>

int main(void) {
    
      float celsius, fahrenheit;
        
      printf("Enter temperature in Celsius: ");
      scanf("%f", &celsius);
        
      fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        
      printf("temperature in Fahrenheit is %.1f\n", fahrenheit);
        
      return 0;
}
*/

/*Q46
#include <stdio.h>
int main(){
    printf("5.0/2 is %d.\n", 5.0/2);
    printf("5.0/2 is %lf.\n", 5.0/2);
    printf("\n\n");
    
    printf("5/2.0 is %d.\n", 5/2.0);
    printf("5/2.0 is %lf.\n", 5/2.0);
    printf("\n\n");
    
    printf("5/2 is %d.\n", 5/2);
    printf("5/2 is %lf.\n", 5/2);
    printf("\n\n");
    
    
    int intFive = 5;
    int intTwo =2;
    double doubleFive = 5.0;
    double doubleTwo = 2.0;
    
    double doubleFive1 = 5.2;
    double doubleTwo1 = 2.2;
    
    printf("intFive / inTwo is %d.\n", intFive/intTwo);
    printf("intFive / intTwo is %lf.\n", intFive/intTwo);
    printf("\n\n");
    
    printf("doubleFive / doubleTwo is %d.\n", doubleFive/doubleTwo);
    printf("doubleFive / doubleTwo is %lf.\n", doubleFive/doubleTwo);
    printf("\n\n");
    
    printf("doubleFive1 / doubleTwo1 is %d.\n", doubleFive1/doubleTwo1);
    printf("doubleFive1 / doubleTwo1 is %lf.\n", doubleFive/doubleTwo1);
    printf("\n\n");
    
    int twenties = 166/20;
    
    printf(" pay %d number \n ", twenties);
    printf("bills is %d \n", twenties*20);
    printf("pay %d CAD. \n", 166-twenties*20);
    
    
}
*/

/*47
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
        int x = 0;
        int y = 0;
        int z = 0;
    
        printf("Please enter the number x, y, z: ");
        
        scanf("%d%d%d", &x, &y, &z);
//    printf("Please enter the number x, y, z: ");

//    printf("Please enter the number x, y, z: ");
//        scanf("%d", &x);
//        scanf("%d", &y);
//        scanf("%d", &z);
    
    
        printf("Sum is %d,\n", x + y + z);
        printf("Average is %d,\n", (x + y + z) / 3);
        printf("Product is %d,\n", x * y * z);
        printf("Smallest is %d.\n", min(min(x, y), z));
        printf("Largest is %d.\n", max(max(x, y), z));
}
 */

/*47 */
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
    int family_ages[5];
    string family_names[5] = {"Father", "Mother", "Sister", "Brother", "Myself"};
//    char family_names[5] = {"Fa", "Mo", "Si", "Br", "My"};

    int ageGap = 0;

    for(int i=0; i<5; i++){
    
//        printf("Please enter the age  of your ");
        cout<<"Please enter the age  of your "<< family_names[i] <<"\n";
        
        scanf("%d", &family_ages[i]);
        printf("%d\n", family_ages[i]);
    }

//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            if (i != j) {
//
//                ageGap = family_ages[i] - family_ages[j];
//                if (ageGap > 0) {
//                    printf("my " %s " 's age: is %d older than my" %s ".\n", family_names[i], ageGap, family_names[j]);
//                }
//                else if (ageGap < 0) {
//                  printf("my %s 's age: is %d older than my %s.\n", "family_names[i]", ageGap, "family_names[j]");
////                    printf("my %s 's age: is %d youger than my %s.\n", "family_names[i]", -ageGap, "family_names[j]");cout
//                }
//                else {
//                    printf("my %s 's age: is same with %s.\n", "family_names[i]", "family_names[j]");
//                }
//
//                return 0;
//            }
//        }
//    }

}

//#include <stdio.h>
//
//int main()
//{
//    char a;
//    char b;
//   scanf ("%s %c", &a, &b);
//   printf ("Decimals: %d %ld\n", a, b);
//   printf ("Preceding with blanks: %10d \n", 1977);
//   printf ("Preceding with zeros: %010d \n", 1977);
//   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
//   printf ("Width trick: %*d \n", 5, 10);
//   printf ("%s \n", "A string");
//   return 0;
//}

//Q49
//#include <stdio.h>
//
//int main() {
//  int i;
//  for (i = 10; i <= 99; i++) {
//    if (i % 3 == 0 || i % 5 == 0) {
//      printf("%d\n", i);
//    }
//  }
//  return 0;
//}

// Q50
//int main() {
//  int i, sum = 0;
//  for (i = 10; i <= 99; i++) {
//    if ((i % 3 == 0 || i % 5 == 0) && (i % 15 != 0)) {
//      printf("%d\n", i);
//      sum += i;
//    }
//  }
//  printf("Sum: %d\n", sum);
//  return 0;
//}
