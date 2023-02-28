//
//  main.c
//  100
//
//  Created by Chang Li on 2023-02-24.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numCodes, codeLength, totalBytes = 0;
    char codeType;

    printf("please input the tracking codes amount.\n");
    scanf("%d", &numCodes);

    for (int i = 0; i < numCodes; i++) {
        
        printf("please input the code length and code type.\n");
        
        scanf("%d %c", &codeLength, &codeType);
        
        if (codeType == 'i') {
            totalBytes += codeLength * sizeof(int);
        }
       
        else if (codeType == 'd') {
            totalBytes += codeLength * sizeof(double);
        }
       
        else if (codeType == 'c') {
            totalBytes += codeLength * sizeof(char);
        }
        
        else {
            printf("Invalid tracking code type!\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("%d bytes\n", totalBytes);

    return 0;
}
