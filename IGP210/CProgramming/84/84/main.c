//
//  main.c
//  84
//
//  Created by Chang on 2023-02-17.
//
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 10
#define MAX_WEEKS 52

struct TemperatureData {
  int week;
  float temperature;
};

int main() {
  char city[MAX_CITIES][20];
  struct TemperatureData temperature[MAX_CITIES][MAX_WEEKS];

  int num_cities, num_weeks;
  printf("Enter the number of cities: ");
  scanf("%d", &num_cities);
  printf("Enter the number of weeks: ");
  scanf("%d", &num_weeks);

  for (int i = 0; i < num_cities; i++) {
    printf("Enter the name of city %d: ", i+1);
    scanf("%s", city[i]);
  }

  for (int i = 0; i < num_cities; i++) {
    printf("Enter the temperature data for city %s:\n", city[i]);
    for (int j = 0; j < num_weeks; j++) {
      printf("Week %d: ", j+1);
      scanf("%f", &temperature[i][j].temperature);
      temperature[i][j].week = j+1;
    }
  }
   
  printf("\nTemperature data organized by city and week:\n");
  for (int i = 0; i < num_cities; i++) {
    printf("%s:\n", city[i]);
    for (int j = 0; j < num_weeks; j++) {
      printf("Week %d: %.1f\n", temperature[i][j].week, temperature[i][j].temperature);
    }
  }
  return 0;
}
