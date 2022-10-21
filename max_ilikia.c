/* File a20f3.c
 * --------------
 * Αυτό το πρόγραμμα βρίσκει τη μεγαλύτερη
 * και τη μικρότερη ηλικία από μια σειρά ηλικιών
 * που εισάγει ο χρήστης
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //Δήλωση μεταβλητών
    int ilikia;
    int maxilikia;
    int minilikia;

    //Είσοδος Δεδομένων
     printf("Dwse ilikia: ");
     ilikia = GetInteger();
     maxilikia = 0;
     minilikia = ilikia;

    //Επεξεργασία - Είσοδος Δεδομένων
     while (ilikia != -1) {
            if (ilikia > maxilikia)
                 maxilikia = ilikia;
            if (ilikia < minilikia)
                 minilikia = ilikia;
            printf("Dwse ilikia: ");
            ilikia = GetInteger();
           }

    //Εμφάνιση αποτελεσμάτων
    printf("H megalyteri ilikia einai %d\n", maxilikia);
    printf("H mikroteri ilikia einai %d\n", minilikia);

   }

   //ΤΕΛΟΣ
