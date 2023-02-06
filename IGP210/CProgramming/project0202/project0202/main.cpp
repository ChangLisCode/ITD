//
//  main.cpp
//  project0202
//
//  Created by Chang on 2023-02-02.
//
/* 51
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
    int family_ages[5];
    string family_names[5] = {"Father", "Mother", "Sister", "Brother", "Myself"};

    int ageGap = 0;

    for(int i=0; i<5; i++){
    
//        printf("Please enter the age  of your ");
        cout<<"Please enter the age  of your "<< family_names[i] <<"\n";
        scanf("%d", &family_ages[i]);
//        printf("%d\n", family_ages[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i ! = j) {

                ageGap = family_ages[i] - family_ages[j];
                if (ageGap > 0) {
                    cout<<"my "<< family_names[i] <<" 's age: is " << ageGap <<", older than my"<< family_names[j]) << ".\n";
                }
                else if (ageGap < 0) {
                  printf("my %s 's age: is %d older than my %s.\n", "family_names[i]", ageGap, "family_names[j]");
//                    printf("my %s 's age: is %d youger than my %s.\n", "family_names[i]", -ageGap, "family_names[j]");cout
                }
                else {
                    printf("my %s 's age: is same with %s.\n", "family_names[i]", "family_names[j]");
                }

                return 0;
            }
        }
    }


}
 */

/*Q51
#include <stdio.h>

int main() {
  int father, mother, sister, brother, me, father_gap, mother_gap, sister_gap, brother_gap;

              printf("Please enter the age of Father: ");
              scanf("%d", &father);
                
              printf("Please enter the age of Mother: ");
              scanf("%d", &mother);
                
              printf("Please enter the age of Sister: ");
              scanf("%d", &sister);
                
              printf("Please enter the age of Brother: ");
              scanf("%d", &brother);
                
              printf("Please enter your age: ");
              scanf("%d", &me);

father_gap = father - me;
mother_gap = mother - me;
sister_gap = sister - me;
brother_gap = brother - me;

  if (father_gap > 0) {
    printf("My Father is %d years older than me.\n", father_gap);
      
  }
  else if(father_gap < 0) {
    printf("My Father is %d years younger than me.\n", -father_gap);
      
  }
  else {
      
    printf("My Father is the same age as me.\n");
  }

  if(mother_gap > 0) {
      
    printf("My Mother is %d years older than me.\n", mother_gap);
  }
  else if(mother_gap < 0) {
    printf("My Mother is %d years younger than me.\n", -mother_gap);
      
  }
  else{
    printf("My Mother is the same age as me.\n");
      
  }

  if(sister_gap > 0) {
    printf("My sister is %d years older than me.\n", sister_gap);
  }
  else if(sister_gap < 0) {
    printf("My sister is %d years younger than me.\n", -sister_gap);
      
  }
  else{
    printf("My sister is the same age as me.\n");
  }

  if(brother_gap > 0) {
    printf("My Brother is %d years older than me.\n", brother_gap);
      
  }
  else if(brother_gap < 0) {
    printf("My Brother is %d years younger than me.\n", -brother_gap);
  }
  else{
    printf("My Brother is the same age as me.\n");
      
      
  }

  return 0;
}
*/

/* 52*/

#include <stdio.h>
#include <iostream>

int main() {
    
    float  distance_run = 2.0, chocolate_have = 10.0, choco_total;
    int total = 25, i;
//    int distanceNumber = 1;
      
    for ( i = 1; (int)distance_run <= total; i++ ){
   
        distance_total =
            distance_run += distance_run * 1.1;
        choco_total =
            chocolate_have += chocolate_have * 1.3;
            printf("chocolate they have is %.1f. \n", chocolate_have);
            printf("distance they run is %.lf. \n", distance_run);
            printf("\n\n\n");
    }
    
    if ((int)distance_run >= total){
        distance_run = distance_run / 1.1;
        chocolate_have = chocolate_have / 1.3;
    }

    
    printf("chocolate they have is %.1f. \n", chocolate_have);
    printf("distance they run is %.lf. \n", distance_run);
    return i;
    
}


/* 53

#include <stdio.h>
#include <math.h>

int main() {
  int population;
  float growthRate;
  float expected_population;

  printf("please enter the current population: ");
  scanf("%d", &population);
  printf("Enter the expected growth percentage: ");
  scanf("%f", &growthRate);

  expected_population = population + population * (growthRate/100);

  printf("Expected population is: %d\n", (int)expected_population);

  return 0;
}
 */
    
