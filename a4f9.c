#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define N 100

typedef struct{
   char name[25];
   int prom;
}SellerT;

void readInput(FILE*infile,SellerT array[],int *total);
void writeOutput(FILE *outfile,int size, SellerT array[]);

int main()
{
    FILE*infile;
    FILE*outfile;

    SellerT array[N];

    infile=fopen("i4f9.dat","r");
    if(infile==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    outfile=fopen("o4f9.dat","w");
    int totalSellers;
    readInput(infile,array,&totalSellers);
    writeOutput(outfile,totalSellers,array);

    fclose(infile);
    fclose(outfile);


    return 0;
}
void readInput(FILE*infile,SellerT array[],int *total)
{
    int nscan,code,line;
    long sells;
    char name[25],termch;
    line=0;
    *total=0;
    while(TRUE)
    {
       nscan=fscanf(infile,"%d, %25[^,],%ld%c",&code,name,&sells,&termch);
       if(nscan==EOF)
       {
           break;
       }
       line++;
       if(nscan!=4 || termch!='\n')
       {
           printf("Error in line %d\n",line);
       }
       strcpy(array[*total].name,name);
       if(code==11)
       {
           array[*total].prom=sells*0.03;
       }
       if(code==12)
       {
           array[*total].prom=sells*0.05;
       }
       if(code==13)
       {
           array[*total].prom=sells*0.08;
       }
       if(code==14)
       {
           array[*total].prom=sells*0.11;
       }
       (*total)++;
    }
}
void writeOutput(FILE *outfile,int size, SellerT array[])
{
    int i;
    fprintf(outfile,"%-25s%-5s","ONOMATEPWNYMO","POSO");
    fputc('\n',outfile);
    for(i=0;i<size;i++)
    {
        fprintf(outfile,"%-25s%-5d\n",array[i].name,array[i].prom);
    }
    fputc('\n',outfile);

}
