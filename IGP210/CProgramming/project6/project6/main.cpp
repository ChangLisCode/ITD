//
//  main.cpp
//  project6
//
//  Created by Chang on 2023-02-06.

/* Q64 */

#include <stdio.h>

void myFunction(char name[], int age) {
  printf("Hello %s. You are %d years old\n", name, age);
}

int main() {
  myFunction("Liam", 3);
  myFunction("Jenny", 14);
  myFunction("Anja", 30);
  return 0;
}


//#include <iostream>
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int function1(int x, int y, char m, char n){
//
//    int sumOfTripled;
//
//
//
//    printf("please insert two integers %c and %c. \n", m, n);
//    scanf("%d %d", &x, &y);
//    printf("a = %d, b = %d. \n\n", x, y);
//
//
//
////    printf("please insert two integers c and d. \n");
////    scanf("%d %d", &c, &d);
////    printf("c = %d, d = %d. \n\n", c, d);
////
////    printf("please insert two integers e and f. \n");
////    scanf("%d %d", &e, &f);
////    printf("e = %d, f = %d. \n\n", e, f);
//
//    sumOfTripled = x + y;
//
//    return  sumOfTripled;
//}
//
//int main(void) {
//    int a, b, c, d, e, f;
//
////    int a = 0 , b = 0,
////    int sum;
////    sum = a + b;
//
////    printf("please insert two integers a and b. \n");
////    scanf("%d %d", &c, &d);
////    printf("c = %d, d = %d. \n\n", c, d);
//
//    function1();
//
//
//
////    printf("sumOfTripled is equal to %d. \n", function1(e,f));
////
////    printf("sum of two inserted numbers is equal to %d.\n", function1(a) + function(b));
////
////    printf("difference between sumOfTripled and sum is equal to %d.\n", function1(sumOfTripled) - (function1(a) + function(b)));
////
//    return 0;
// }

 
/* Q64

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y){
    int compute;
    compute = x +y;
    return compute;
}

int main() {
    int a, b;
    int result;
    
    printf("1 - please insert two integers: \n");
    scanf("%d %d", &a, &b); // use space to input two integers.
    
    result = sum(a,b);
    
    printf("The result of a +b is equal %d.\n", result);
    printf("End of the program. \n");
    
    return 0;
    
}
*/

/*Q62

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 0;
    int i, k;
    
    //    char teamTypeOne[50][50] = {"Jeff", "David", "Kevin", "Sean", "Bill"};
    
    struct Player {
//        char name[100];
//        char role[100];
        
        char name[50];
        char role[50];
        
        int age;
        int experience;
    };
    struct Player team[number];
    
    
    
    // input part
    
    printf("how many soccer is in your team?\n");
    scanf("%d", &number);
    
    if (number >= 1 && number <= 22){
//        number -= 1;
        for(i=0; i<number; i++){
            
            printf("please input your player %d 's name?\n", i+1);
            scanf("%s", &team[i].name);
            
            printf("please input your player %d 's role?\n", i+1);
            scanf("%s", &team[i].role);
            
            printf("what is your player %d 's age?\n", i+1);
            scanf("%d", &team[i].age);
            
            
            //  age check
            
            if(team[i].age == false){
                
                for(k=1; k<2; k++){
                    
                    printf("wrong enter, please repeat?\n");
                    scanf("%d", &team[i].age);
                    
                    if (k == 2 ){
                        printf(" wrong times is more than two times wrongly, you are defined as a robot and spam and will not be allowed to enter.\n");
                        
                        break;
                    }
                }
            }
            
            printf("please input your player %d 's experience?\n", i+1);
            scanf("%d", &team[i].experience);
            
        }
        
        printf("\n\n\n");
        
        // array check
        
        
        //      sort by age and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (team[j].age > team[j + 1].age) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d.\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        //     sort by experience and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (team[j].experience > team[j + 1].experience) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d..\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        //     sort by name and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (strcmp(team[j].name, team[j + 1].name) > 0) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d.\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        return 0;
    }
    
}
*/

/* Q61
#include <iostream>

int main() {
    int arrayH[3][3][2];
    int i, j, k;
    printf("\n\n\n");
    printf("please insert 18 intetger.\n");
    for (i=0; i<3; i++){
        for ( j=0; j<3; j++){
            for ( k=0; k<3; k++ ){
                scanf("%d", &arrayH[i][j][k]);
            }
        }
    }
    for (i=0; i<3; i++){
        for ( j=0; j<3; j++){
            for ( k=0; k<3; k++ ){
                printf("%d", arrayH[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
 
 */
 
/* n/a
#include <iostream>

int main() {
    
    char letter;
    int i = 15, j = 5;
    double m = 16, n = 3;
    
    printf("%d\n", i/j);
    printf("%lf\n\n", i/j);
    
    printf("%d\n", m/n);
    printf("%lf\n\n", m/n);
    
    printf("%d\n", (int)m%j);
    printf("%lf\n\n", m/j);
    
    printf("%d\n", j/m);
    printf("%lf\n\n", j/m);
    
    printf("%d\n", j/m);
    printf("%lf\n\n", j/m);
    
    
//    scanf("%d", & letter);
//
//    printf("please input the leter:\n");
//    scanf("%c", & letter);
//
//    printf("please input the leter:\n");
//    scanf("%c", & letter);
  
}
 */

/*Q60
#include <iostream>

int main() {

    char letter;
    char letter0 = '+';

    int i, j, k;
    int l = 1, m = 9, n = 5;
    
    printf(" **** \033[1;33m Assignment 60 \033 [1;32m *****\n");

    printf("please input the leter:\n");
    scanf("%c", & letter);

    printf("please input the column:\n");
    scanf("%d", &m);

    printf("please input the row:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) {

            if (j == m/2) {
                for (k = 0; k < l; k++) {
                    printf("%c", letter);
                }
                } else {
                    printf("%c", letter0);
                }
        }
        l += 2;
        m -= 2;
        printf("\n");
    }
    return 0;

}
*/

/* W59
#include <iostream>

int main() {
    int totalCement;
    int totalBag;
    int purchasedCement = 0;
    double cementPerPound;
    int i;
    
    printf("please input the total cement you need:\n");
    scanf("%d", &totalCement);
    printf("\n\n");
    
    totalBag = (int)totalCement/120 + 1;
    
    cementPerPound = 45.00/120.00;
    printf("cement per pound is %lf:\n", cementPerPound);
    
    printf("\n\n");
    
    for(i=0; purchasedCement < totalCement; i++){
        purchasedCement += 120;
        printf("total purchased cement is %d.\n", purchasedCement);
    }
    
    printf("\n\n");
    printf("the cement bags %d bags.\n", purchasedCement);
    printf("the actual cost of cement %lf dollars.\n", cementPerPound * totalCement);
    printf("the cement bags you have to purchase %d dollars.\n", totalBag * 45);
    
    printf("\n\n");
    
    return i;
}
*/



/*W58

#include <iostream>

int main() {
    double totalMoney;
    double bookPrice;
    double totalPrice=0;
    int i=0;
    
    printf("please input the money you have:\n");
    scanf("%lf", &totalMoney);
    
    printf("please input the book price:\n");
    scanf("%lf", &bookPrice);
    
    printf("\n\n");
    
    printf("total money is: %lf\n", totalMoney);
    printf("the book price is: %lf\n", bookPrice);

    printf("\n\n");
    
    printf("total money is: %.2f\n", totalMoney);
    printf("the book price is: %.2f\n", bookPrice);

    
    for(i=0; totalPrice < totalMoney; i++){
        totalPrice += bookPrice;
        printf("total Price is %lf.\n", totalPrice);
    }
    
//    do{
//        totalPrice += bookPrice;
//        i++;
//    }
//    while (totalPrice < totalMoney);
    
    printf("\n\n");
    printf("book amount is %d.\n", i-1);
    printf("\n\n");
    
    return i;
}
 }
*/
