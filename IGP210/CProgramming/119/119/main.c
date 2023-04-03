//
//  main.c
//  119
//
//  Created by Chang on 2023-03-06.
//

//#include <stdio.h>
//int main(){
//    struct node{
//        int a, b, c;
//        int num[3];
//
//    };
//    struct node num ={3,5,6};
//    struct node *ptr = &num;
//    printf("%d\n", *((int*)ptr + 1+ (3-2)));
//    return 0;
//}

#include <stdio.h>

//void myFunction(char **ptr){
//    char *ptr1;
////    step 1: printf("%d\n", sizeof(int)); sizeof(int) output to be 4
////    step 2: array arr[] is pass to myFunction by **ptr
////    step 3: ptr[0] is arr[0], it is "ant";
////    step 4: dereference: ptr[4] is arr[4], it is "egg";
////    step 5: dereference: ptr[4][-2] == *ptr[-2], so ptr[-2] == *(ptr - 2),
////    step 6: ptr[2] is arr[2], it is "cat";
//
//    ptr1 = (ptr += sizeof(int))[-2]; //ptr[2] is arr[2], it is "cat";
//    printf("%s\n", ptr1); // output: cat
    
void function(char **ptr)
{
    char *ptr1;
    ptr1 = ptr[0];
    printf("%s \n", ptr1);
    ptr1 = ptr[1];
    printf("%s \n", ptr1);
    ptr1 = ptr[2];
    printf("%s \n", ptr1);
    ptr1 = ptr[3];
    printf("%s \n", ptr1);
    ptr1 = ptr[4];
    printf("%s \n", ptr1);
    ptr1 = ptr[5];
    printf("%s \n", ptr1);
    printf("\n\n");
    
    // ptr1 = (ptr += sizeof(int))[-2];

    ptr1 = ptr[0+4-0];
    printf("%s \n", ptr1);
    ptr1 = ptr[0+4-1];
    printf("%s \n", ptr1);
    ptr1 = ptr[0+4-2];
    printf("%s \n", ptr1);
    ptr1 = ptr[0+4-3];
    printf("%s \n", ptr1);
    ptr1 = ptr[0+4-4];
    printf("%s \n", ptr1);
    ptr1 = ptr[0+4-5];
    printf("%s \n", ptr1);
}
    
int main(void) {
    char *arr[]={"ant", "bat", "cat", "dog", "egg", "fly"};
    function(arr);
    return 1;
}
