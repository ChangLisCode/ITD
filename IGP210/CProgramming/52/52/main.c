//
//  main.c
//  52
//
//  Created by Chang on 2023-02-13.
//

#include <stdio.h>

int main() {
    
    float  distance_run = 2.0, chocolate_have = 10.0, choco_total;
    int total = 25, i;
//    int distanceNumber = 1;
      
    for ( i = 1; (int)distance_run <= total; i++ ){
   
        int distance_total;
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
