/* File a13f6
Να γραφεί μια συνάρτηση decompose τύπου void, η οποία θα δέχεται ως όρισμα έναν ακέραιο (long) και
θα ενημερώνει την καλούσα συνάρτηση («επιστρέφει» - δείτε παρατήρηση 5 στην αρχή της άσκησης) για τα
ακόλουθα:
 το πλήθος των ψηφίων του,
 τον μέσο όρο των ψηφίων του,
 το μέγιστο ψηφίο του.
Να υλοποιήσετε ένα πρόγραμμα το οποίο στη συνάρτηση main() θα ζητά από τον χρήστη ένα αριθμό (μηαρνητικός ακέραιος-δεν απαιτείται έλεγχος), και χρησιμοποιεί την παραπάνω συνάρτηση για να εμφανίσει (από
τη συνάρτηση main()) τα παραπάνω στοιχεία του αριθμού. Ο μέσος όρος θα εμφανίζεται με ακρίβεια 3
δεκαδικών ψωφίων. Παραδείγματα εκτέλεσης για διαφορετικές περιπτώσεις αριθμών ακολουθούν παρακάτω:
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

//Ορισμός συνάρτησης
void decompose(long a);

int main()
{
   long a;
   printf("Please insert non-negative number:");
   a = GetLong();

   decompose(a);

   return 0;
}

//Συνάρτηση
void decompose(long a){
   int i;
   long sum = 0;
   int count = 0;
   long b = 1000000000;
   long max_psifio = 0;
   double mesos_oros;
   long c;
   for (i=0; i<10; i++){
        c = a / b;
        if ( c > 0 ){
            sum += c;
            if( c > max_psifio )
                max_psifio = c;
            count++;
             a = a % b;
        }
        b = b / 10;

   }


   mesos_oros = (double)sum / count;

   printf("Digits: %d\nAverage: %.3lf\nMax: %d",(int)count, mesos_oros,(int)max_psifio);
}




























































