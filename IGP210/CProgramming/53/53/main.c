//
//  main.c
//  53
//
//  Created by Chang on 2023-02-13.
//
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
