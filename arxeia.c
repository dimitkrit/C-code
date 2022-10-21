/*File a2f9
Δίνεται το αρχείο κειμένου ‘i2f9.dat’ των μαθητών ενός σχολείου που περιλαμβάνει τα εξής στοιχεία για
κάθε μαθητή:
 ονοματεπώνυμο μαθητή, το οποίο δεν μπορεί να περιλαμβάνει περισσότερους από 30 χαρακτήρες
 αριθμός απουσιών (int)
 διάφορα στοιχεία μαθητή, τα οποία δεν μπορούν να ξεπερνάνε τους 68 χαρακτήρες
Τα παραπάνω στοιχεία για κάθε μαθητή χωρίζονται με κόμμα.
Ζητείται να γίνει πρόγραμμα που να δημιουργεί αρχείο μαθητών με απουσίες άνω των 100. Το πρόγραμμα
θα ζητά τα ονόματα των αρχείων "εισόδου" (i2f9.dat) και "εξόδου" (o2f9.dat) από τον χρήστη. Από
το αρχείο μαθητών ‘i2f9.dat’ θα δημιουργείται το αρχείο κειμένου ‘o2f9.dat’ που θα περιέχει το
ονοματεπώνυμο (30 χαρακτήρες) και τον αριθμό απουσιών (int) κάθε μαθητή που οι απουσίες του
ξεπερνούν τις 100. Τέλος, θα περιέχει το πλήθος όλων των μαθητών του σχολείου καθώς και το πλήθος των
μαθητών του σχολείου που οι απουσίες τους ξεπερνούν τις 100. H εμφάνιση θα ακολουθεί στοίχιση με την
παρακάτω μορφή:
1-30 31-39
ΟΝΟΜΑΤΕPWΝΥΜΟ ΑPΟΥSΙΕS
----------------------------------------------------
PAPANIKOLAOU KVSTAS 115
.......................... .....
----------------------------------------------------
SΥΝΟLΟ ΜΑTHIΤWΝ: 8
SΥΝΟLΟ ΑPΟΝΤWΝ: 5
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>


#define M 100

//ΟΡΙΣΜΟΣ ΔΟΜΗΣ
typedef struct {
   char name[30];
   int apousies;
} studentT;

//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void  readInput(FILE* infile, studentT students[], int *pApontes, int *pStudents);
void  writeOutput(FILE* outfile, studentT students[], int apontes, int totalStudents);

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main(){

    FILE* infile;
    FILE* outfile;

    char inputFileName[30];
    char outputFileName[30];

    studentT students[M];
    int apontes, totalStudents;

    printf("Dwse to onoma gia to arxeio eisodou: ");
    gets(inputFileName);
    printf("Dwste to onoma gia to arxeio exodou: ");
    gets(outputFileName);

    infile = fopen(inputFileName,"r");
    if(infile == NULL){
        printf("Cannot open input file %s",inputFileName);
        exit(1);
    }
    outfile = fopen(outputFileName,"w");

    readInput(infile, students,&apontes, &totalStudents);
    writeOutput(outfile, students, apontes, totalStudents);
    fclose(infile);
    fclose(outfile);

    return 0;

}

//ΣΥΝΑΡΤΗΣΕΙΣ

void  readInput(FILE *infile, studentT students[], int *pApontes, int *pStudents){
     int nscan, apousies;
     char name[30], comments[68], termch;
     int line = 0;
     *pApontes = 0;
     *pStudents = 0;

     while(TRUE){
        nscan = fscanf(infile,"%30[^,], %d, %68[^\n]%c",
                      name, &apousies, comments, &termch);
        if(nscan == EOF)
            break;
        }
        line++;
        if(nscan !=4 || termch != '\n'){
            printf("Error in line %d. Program termination\n", line);
            exit(1);
        }
        if (apousies > 100){
            strcpy(students[*pApontes].name, name);
            students[*pApontes].apousies = apousies;
            (*pApontes)++;
        }
        (*pStudents)++;
}

void  writeOutput(FILE* outfile, studentT *students, int apontes, int totalStudents){
    int i;
    fprintf(outfile,"%-30s%-9s\n", "ONOMATEPONYMO", "APOUSIES");
    for(i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for(i=0; i<apontes; i++)
        fprintf(outfile,"%-30s%9d\n", students[i].name,students[i].apousies);

    for(i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);


        fprintf(outfile,"%-30s%9d\n","SYNOLO MATHITWN",totalStudents);
        fprintf(outfile,"%-30s%9d\n","SYNOLO APONTWN:", apontes);

}




