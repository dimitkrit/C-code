#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"

#define N 100

typedef struct{
       char name[30];
       long prom;
}SellersT;

void readData(FILE*infile,SellersT Sellers[],int *synolo);
void writeOutput(FILE*outfile,SellersT Sellers[],int total);
int main()
{
    FILE*infile;
    FILE*outfile;
    infile=fopen("i3f9.dat","r");
    if(infile==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    outfile=fopen("e3f9.dat","w");
    SellersT Sellers[N];
    int total;
    readData(infile,Sellers,&total);
    writeOutput(outfile,Sellers,total);
    fclose(infile);
    fclose(outfile);



    return 0;
}
void readData(FILE*infile,SellersT Sellers[],int *synolo)
{
    int nscan,sells,line;
    char name[30],comments[68],termch;
    line=0;
    *synolo=0;

    while(TRUE)
    {
       nscan=fscanf(infile,"%30[^,], %d, %68[^\n]%c",name,&sells,comments,&termch);
       if(nscan==EOF)
       {
           break;
       }
       if(nscan!=4 || termch!='\n')
       {
           printf("ERROR IN LINE %d",line);
           exit(1);
       }

       if(sells>300000)
       {
           strcpy(Sellers[*synolo].name,name);
           Sellers[*synolo].prom=sells*0.05;
       }
       else
       {
           strcpy(Sellers[*synolo].name,name);
           Sellers[*synolo].prom=sells*0.03;

       }

       (*synolo)++;
    }
}
void writeOutput(FILE*outfile,SellersT Sellers[],int total)
{
    int i;
    fprintf(outfile,"%-30s%-10s","ONOMATEPWNYMO","PROMHTHEIA");
    fputc('\n',outfile);
    for(i=0;i<40;i++)
    {
        fputc('-',outfile);
    }
    fputc('\n',outfile);
    for(i=0;i<total;i++)
    {
        fprintf(outfile,"%-30s%-10d\n",Sellers[i].name,Sellers[i].prom);
    }
    for(i=0;i<39;i++)
    {
        fputc('-',outfile);
    }
    fputc('\n',outfile);
    fprintf(outfile,"%-30s%-10d","SYNOLO MATHITWN",total);

}
