//
//  main.c
//  50
//
//  Created by Chang on 2023-02-13.
//
# include <stdio.h>

int main() {
  int i, sum = 0;
  for (i = 10; i <= 99; i++) {
    if ((i % 3 == 0 || i % 5 == 0) && (i % 15 != 0)) {
      printf("%d\n", i);
      sum += i;
    }
  }
  printf("Sum: %d\n", sum);
  return 0;
}
