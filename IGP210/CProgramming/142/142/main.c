//
//  main.c
//  142
//
//  Created by Chang on 2023-03-14.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    
    int *ptr;
    
    ptr = malloc(0);
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 0;
     but malloc function take 8 byte which is uesed as pointer information.
     */
    
    ptr = malloc(4);
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 4;
     but malloc function take 8 byte which is uesed as pointer information.
     */
    
    ptr = malloc(6);
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 6;
     but malloc function take 8 byte which is uesed as pointer information.
     */
        
    ptr =  malloc(sizeof(int));
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 4, becauze type int take 4 byte in 64 system;
     but malloc function take 8 byte which is uesed as pointer information.
     */
    
    ptr =  malloc(3*sizeof(int));
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 4 * 3, becauze type int take 4 byte in 64 system;
     but malloc function take 8 byte which is uesed as pointer information.
     */
    ptr =  malloc(4*sizeof(float));
    /*
     specify a memory on the heap side of memory, return the address of first byte to ptr; the memory size is 4 * 4, becauze type int take 4 byte in 64 system;
     but malloc function take 8 byte which is uesed as pointer information.
     */

    return 0;
}
