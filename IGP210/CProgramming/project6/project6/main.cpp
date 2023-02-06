//
//  main.cpp
//  project6
//
//  Created by Chang on 2023-02-06.

//Q60
#include <iostream>

int main() {

    char letter;
    char letter0 = '+';

    int i, j, k;
    int l = 1, m = 9, n = 5;

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

/*W59
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
*/
