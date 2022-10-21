/* File a13f3.c
 * --------------
 * Αυτό το πρόγραμμα ζητά έναν ακέραιο
 * και υπολογίζει το άθροισμα των κλασμάτων Σ(1/χ)
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //Δήλωση Μεταβλητών
    int N;
    int i;
    double athroisma=0.0;
    double klasma=0.0;

    //Είσοδος Δεδομένων
    printf("Dwse orio: ");
    N = GetInteger();

    //Επεξεργασία
    i=1;
    while (i<=N){
        klasma = (double)1/i;
        athroisma = athroisma + klasma;
        i++;
    }
    // Εμφάνιση Αποτελεσμάτων
    printf ("To athroisma einai: %.2f\n", athroisma);

}
    // ΤΕΛΟΣ

