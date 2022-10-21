/* File a10f8
10. Σε ένα ημερολόγιο ενός έργου καταγράφονται διάφορα πακέτα εργασίας. Κάθε εργασία έχει όνομα name
(char name [60]), μήνα έναρξης (int) όπως μετράται από την αρχή του έργου και διάρκεια σε μήνες
(int). Για παράδειγμα:
• η εργασία “project specifications” έχει χρόνο έναρξης 0 (ξεκινά τον πρώτο μήνα του έργου) και
διάρκεια 4 μήνες, οπότε θεωρείται ότι ολοκληρώνεται τον 4 μήνα.
• η εργασία “implementation” έχει χρόνο έναρξης 2 και διάρκεια 8 μήνες, οπότε θεωρείται ότι
ολοκληρώνεται τον 10 μήνα (10 = 8 + 2)
(α) Να ορίσετε κατάλληλη δομή (νέο τύπο) η οποία να αποθηκεύει τα στοιχεία των εργασιών.
(β) Να ορίσετε ένα πρόγραμμα το οποίο:
• Zητά από τον χρήστη τον συνολικό αριθμό εργασιών του έργου WP
• Mέσω μιας συνάρτησης ReadWorkpackages ζητά από τον χρήστη τα στοιχεία των WP εργασιών
(όνομα, χρόνο έναρξης και διάρκεια)
• Βρίσκει ποια εργασία ξεκινά πρώτη μέσω της συνάρτησης FindFirstWp, η οποία επιστρέφει την
δομή της πρώτης χρονικά εργασίας.
• Τυπώνει τα στοιχεία της πρώτης χρονικά εργασίας στην οθόνη μέσω της συνάρτησης main().
• Βρίσκει την συνολική διάρκεια του έργου (makespan) μέσω της συνάρτησης FindMakespan. Η
συνολική διάρκεια του έργου ορίζεται ως ο μήνας στον οποίο ολοκληρώνεται η τελευταία εργασία
(έχουν τελειώσει όλες οι εργασίες).
• Εμφανίζει την συνολική διάρκεια του έργου στην οθόνη.
Για να γίνουν τα παραπάνω θα πρέπει να ορίσετε κατάλληλο πίνακα δομών με μέγεθος τουλάχιστον 100.
Θεωρείστε ότι ο χρήστης (α) δεν θα εισάγει περισσότερες από 100 εργασίες (δεν απαιτείται έλεγχος), (β) θα
εισάγει πάντα ως χρόνο έναρξης ένα μη-αρνητικό ακέραιο (δεν απαιτείται έλεγχος) (γ) ότι θα εισάγει πάντα ως
διάρκεια ένα θετικό ακέραιο (δεν απαιτείται έλεγχος) και (δ) τα ονόματα των εργασιών είναι αυστηρά μικρότερα
των 60 χαρακτήρων (δεν απαιτείται έλεγχος).
*/

#include <stdio.h>
#include <ctype.h>
#include "genlib.h"

//ΟΡΙΣΜΟΣ ΜΕΓΕΘΟΥΣ ΠΙΝΑΚΑ
#define pinakas 100

//ΟΡΙΣΜΟΣ ΔΟΜΩΝ
typedef struct
{
    char name[60];
    int minas_enarxis;
    int diarkeia;
} imerologio;


//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void  ReadWorkpackages(int n_ergasies, imerologio erg[]);
imerologio  FindFirstWp(int n_ergasies, imerologio erg[]);
int FindMakespan(int n_ergasies, imerologio erg[]);

int main()
{

    imerologio erg[pinakas];
    imerologio firsterg;
    int ar_erg;
    int makespan;
    printf("Total work packages: ");
    ar_erg = GetInteger();

    ReadWorkpackages(ar_erg,erg);

    firsterg = FindFirstWp(ar_erg, erg);
    printf("FIRST WP: %s start: %d duration: %d\n", firsterg.name, firsterg.minas_enarxis, firsterg.diarkeia);

    makespan = FindMakespan(ar_erg,erg);
    printf("Total duration = %d", makespan);

	return 0;
}


//ΣΥΝΑΡΤΗΣΕΙΣ

 void  ReadWorkpackages(int nergasies, imerologio erg[]){
     int i;
     for(i=0; i<nergasies; i++)
       {
          printf("WP name: ");
	      gets(erg[i].name);
          printf("WP Start Month: ");
	      erg[i].minas_enarxis = GetInteger();
	      printf("WP Duration: ");
	      erg[i].diarkeia = GetInteger();
       }
 }

 imerologio  FindFirstWp(int n_ergasies, imerologio erg[]){

    int i, index;

    int proti_ergasia = erg[0].minas_enarxis;
    index=0;
    for(i=1; i<n_ergasies; i++)
    	if (proti_ergasia > erg[i].minas_enarxis) {
            proti_ergasia = erg[i].minas_enarxis;
            index=i;
        }

    return erg[index];
}

int FindMakespan(int n_ergasies, imerologio erg[]){
    int total = 0;
    int i, index;
    int last_minas = 0;
    for(i=0; i<n_ergasies; i++){
        total = erg[i].minas_enarxis + erg[i].diarkeia;
    	if (last_minas < total)
            last_minas = total;

        }
   return last_minas;

 }








