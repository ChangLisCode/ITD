//
//  main.c
//  90
//
//  Created by Chang on 2023-02-21.
//

#include <stdio.h>
 
int main() {
  
    int r, c, i, j;                 // type the variable at first
                
    printf("Enter rows and columns: ");
    scanf("%d %d", & r, & c);
   
    int a[r][c], transpose[c][r]; // after scanf to avoid initial the array.
    
  // assigning elements to the matrix
    printf("\nEnter matrix elements:\n");
 
    for (i = 0; i < r; i++){    // lack of grace bracket ; expression: i++
        for (j = 0; j < c; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", & a[i][j]);
        }
    }
  // printing the matrix a[][]
    printf("\nEntered matrix: \n");
      for (i = 0; i < r; i++){        //lack of branket
          for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
       }
    }
  // computing the transpose
    for (i = 0; i < r; i++){                    //lack of branket
        for (j = 0; j < c; j++) {
            transpose[j][i] = a[i][j];
        }
    }
    
  // printing the transpose
    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < c; i++){                     //lack of branket
        for (j = 0; j < r; j++) {
            printf("%d ", transpose[i][j]);
            if (j == r - 1){                        //lack of branket
                printf("\n");
            }
        }
    }
  return 0;
}
