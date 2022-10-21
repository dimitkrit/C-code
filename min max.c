/* File a2f6
 Να γραφεί ένα πρόγραμμα το οποίο διαβάζει μη-αρνητικούς ακέραιους αριθμούς (int) από το χρήστη (δεν
χρειάζεται έλεγχος) και θα τους αποθηκεύει σε ένα μονοδιάστατο πίνακα, μέγιστου μεγέθους 100. Το
πρόγραμμα δέχεται αριθμούς από τον χρήστη μέχρι εκείνος να εισάγει την τιμή -1. Έπειτα υπολογίζει το
μέγιστο και ελάχιστο στοιχείο του πίνακα και εμφανίζει (από το κυρίως πρόγραμμα,, δηλαδή την συνάρτηση
main()) κατάλληλο μήνυμα στην οθόνη όπως φαίνεται στο παράδειγμα εκτέλεσης. Το πρόγραμμά σας θα
πρέπει να έχει:
 μια συνάρτηση η οποία διαβάζει τους αριθμούς από τον χρήστη, αποθηκεύει στον πίνακα (όλους
τους αριθμούς εκτός από το -1), και επιστρέφει το πλήθος των τιμών που εισήγαγε ο χρήστης χωρίς
να υπολογίζει την τιμή -1,
 μια συνάρτηση η οποία εντοπίζει και ενημερώνει την καλούσα συνάρτηση συγχρόνως τόσο για τη
μικρότερη όσο και για τη μεγαλύτερη τιμή ενός μονοδιάστατου πίνακα ακεραίων, δηλαδή
«επιστρέφει» (δείτε παρατήρηση 5 στην αρχή της άσκησης) δύο τιμές.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define SIZE 100


//Ορισμοί Συναρτήσεων
int EISAGOGI_ARITHMON(int size, int array[]);
void MIN_MAX(int size, int array[]);

int main()
{
   int plithos;
   int PINAKAS[SIZE];

   printf("Enter the elements of the array, one per line.\nUse -1 to signal the end of the list.\n");

   plithos = EISAGOGI_ARITHMON(SIZE,PINAKAS);
   MIN_MAX(plithos,PINAKAS);

   return 0;
}


//Συναρτήσεις
int EISAGOGI_ARITHMON(int size, int array[]){

    int arithmos;
    int i = 0;

    printf("? ");
    arithmos = GetInteger();

    while(arithmos != -1){
        array[i] = arithmos;
        printf("? ");
        arithmos = GetInteger();
        i++;
   }
   return i;

}

void MIN_MAX(int size, int array[]){

    int i;
    int max = array[0];
    int min = array[0];

    for(i=1; i<size; i++){
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    printf("The range of values is %d-%d\n", min, max);

}
