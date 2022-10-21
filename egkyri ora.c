/* File a23f4.c
 *  Γράψτε πρόγραμμα που περιλαμβάνει μια συνάρτηση με το όνομα Valid_Time η οποία θα δέχεται ως
τυπικές παραμέτρους 3 ακέραιους αριθμούς (int) που αντιστοιχούν σε ώρες, λεπτά και δευτερόλεπτα μιας
χρονικής στιγμής της ημέρας (ώρα) και θα επιστρέφει την τιμή ΤRUΕ ή FΑLSΕ ανάλογα με το αν η δοθείσα
χρονική στιγμή (ώρα) είναι έγκυρη ή όχι (αν δηλαδή οι ώρες θα πρέπει να είναι από 0 έως και 23 και τα λεπτά
και δευτερόλεπτα να είναι από 0 έως και 59). Τα δεδομένα (ώρες, λεπτά και δευτερόλεπτα) θα ζητούνται από
τον χρήστη στο κυρίως πρόγραμμα, όπως φαίνεται στα ακόλουθα παραδείγματα. Στο τέλος το πρόγραμμα θα
εμφανίζει το μήνυμα “WRA EGKYRH” ή “WRA MH EGKYRH” από το κυρίως πρόγραμμα (συνάρτηση
main(), δηλαδή η εντολή εμφάνισης του μηνύματος (printf) θα είναι στην main)
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

//Δήλωση συνάρτησης
bool valid_Time(int hours, int minutes, int seconds);

//Είσοδος και Επεξεργασία δεδομένων
int main() {
   int wres;
   int lepta;
   int defterolepta;

    printf("Dwse tis wres: ");
    wres = GetInteger();
    printf("Dwse ta lepta: ");
    lepta = GetInteger();
    printf("Dwse ta defterolepta: ");
    defterolepta = GetInteger();

    if (valid_Time(wres,lepta,defterolepta))
         printf("WRA EGKYRH\n");

    else
         printf("WRA MH EGKYRH\n");
    return 0;
}


// Συνάρτηση
bool valid_Time(int hours, int minutes, int seconds) {

    if ((hours >= 0) && (hours <=23) && (minutes >= 0) && (minutes <= 59) && (seconds >= 0) && (seconds <= 59))
        return TRUE;

    else
        return FALSE;



}


