/* File a23f3.c
 * --------------
 * Αυτό το πρόγραμμα εμφανίζει την αύξουσα
 * ακολουθία του αριθμού που εισάγει
 * ο χρήστης ανάλογα αν είναι μονός
 * ή περιττός αριθμός
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //Δήλωση μεταβλητών
    int arithmos;
    int i;

    //Είσοδος Δεδομένων
     printf("Enter number: ");
     arithmos = GetInteger();

    //Επεξεργασία - Εμφάνιση Δεδομένων
     if ((arithmos%2) == 0) {
         for (i=0; i<=arithmos; i=i+2 )
            printf("%d ",i);
        }
     else {
         for (i=1; i<=arithmos; i=i+2)
            printf("%d ",i);
        }
    }

    //ΤΕΛΟΣ
