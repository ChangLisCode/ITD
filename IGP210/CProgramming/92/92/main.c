//
//  main.c
//  92
//
//  Created by Chang on 2023-02-22.
//

#include <stdio.h>

int main() {
  int n = 5;
  int arr[n];

  printf("Size of arr: %lu\n", sizeof(arr));

  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < n; i++) {
    printf("%05d\n", arr[i]); 
  }

  return 0;
}
