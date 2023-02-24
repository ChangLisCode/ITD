//
//  main.c
//  49
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
  int i;
  for (i = 10; i <= 99; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}
