//
//  main.c
//  45
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main(void) {
    
      float celsius, fahrenheit;
        
      printf("Enter temperature in Celsius: ");
      scanf("%f", &celsius);
        
      fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        
      printf("temperature in Fahrenheit is %.1f\n", fahrenheit);
        
      return 0;
}
