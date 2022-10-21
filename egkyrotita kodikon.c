/*FileName: a27f4.c
*  ------------------
* Αυτό το πρόγραμμα ελέγχει την εγκυρότητα κωδικών.
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

//Δήλωση συναρτήσεων
long encode(long N);
bool check(long EN);

//Επεξεργασία - Εμφάνιση Δεδομένων
int main() {

   long first_limit;
   long last_limit;
   long i;

   printf("Lower Limit: ");
   first_limit = GetLong();
   printf("Upper Limit: ");
   last_limit = GetLong();

   for(i=first_limit; i<=last_limit; i++){
       if (check(encode(i)))
          printf("Code: %ld Encoding: %ld isValid:yes\n", i, encode(i));

       else
          printf("Code: %ld Encoding: %ld isValid:no\n", i, encode(i));
   }
   return 0;
}

//Συναρτήσεις

//Συνάρτηση που υπολογίζει τον κωδικό
long encode(long N){
     int psifia_elegxou;
     int EN;
     psifia_elegxou = (98 - (N*100) % 97) % 97;
     EN = (N * 100) + psifia_elegxou;

     return EN;

}

//Συνάρτηση που ελέγχει τον κωδικό
bool check(long(EN)){
     if (EN % 97 == 1)
        return TRUE;
     else
        return FALSE;

}

//ΤΈΛΟΣ





