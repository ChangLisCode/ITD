#include <stdio.h>

void writeExcel()
{
    char chy[4]={ 'x' ,'a' ,'h','w' } ;
    int data[4]={ 1 , 3 , 6 ,9    };
    int i ;
    FILE *fp = NULL ;
    fp = fopen("/Users/chang/Desktop/test.csv","w") ;
    for (i=0 ; i<4 ;i++)
        fprintf(fp,"%c\t%d\n",chy[i],data[i] ) ;
    fclose(fp);
}
void main()
{
    writeExcel()  ;
}
