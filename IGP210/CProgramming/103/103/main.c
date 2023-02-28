//
//  main.c
//  103
//
//  Created by Chang Li on 2023-02-27.
//

#include <stdio.h>
#include <string.h>

void revstr(char *str1){
    int i, len, temp;
    len = strlen(str1);
      
    for (i = 0; i < len/2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

int main() {
    char nameList[100][100] = {
        "Vancouver, Canada", "Ottawa, Canada", "Calgary, Canada", "Toronto, Canada", "Montreal, Canada", "Sanjose, USA", "Seatle, USA", "Atlanta, USA","New York, USA", "Boston, USA"};
    int a, b, c;
    
    printf("please choose 3 city and countries, please input its number\n");
    
    for(int i = 0; i < 10; i++){
        printf("option %d is %s \n", i+1, nameList[i]);
    }
    
    
//    char tempList[100] = nameList[a] + " ," + nameList[b] + " ," + nameList[c];
    
    scanf("%d%d%d", &a, &b, &c);

    printf("\n\n");
         
    revstr(nameList[c-1]);
    revstr(nameList[b-1]);
    revstr(nameList[a-1]);
    
    printf("reverse string is:\n %s%s%s%s%s", nameList[a-1], " ,", nameList[b-1], " ,", nameList[c-1]);
    
    printf("\n\n\n");
    return 0;
}

/*
#include <stdio.h>
int main(void){
    int i;
    double a;
    double b;
    char c;
    int arrayA[3];
    
    a = 1.0;
    b = 2.0;
    c = 'C';
    
    for(i=0; i<3; i++){
        arrayA[i] = i*i + 1;
    }
    return 0;
}
*/
