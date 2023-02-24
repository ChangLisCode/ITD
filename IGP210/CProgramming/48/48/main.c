//
//  main.c
//  48
//
//  Created by Chang on 2023-02-13.
//


//Q48
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

