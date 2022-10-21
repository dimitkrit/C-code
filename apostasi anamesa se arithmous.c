/*FileName: a21f5
*  ------------------
* Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει 5 πραγματικούς αριθμούς τύπου double και να τους
αποθηκεύει σε έναν πίνακα. Το πρόγραμμα να υπολογίζει την απόσταση μεταξύ διαδοχικών στοιχείων του
πίνακα και την αποθηκεύει σε ένα νέο πίνακα (θα καθορίσετε εσείς το απαιτούμενο μέγεθος). Η απόσταση
προκύπτει ως η απόλυτη τιμή της διαφοράς των στοιχείων (συνάρτηση fabs). Για παράδειγμα, αν τα
τέσσερα πρώτα στοιχεία του πίνακα είναι: 5.2, -3.2, 7.5, 12.22, οι αντίστοιχες αποστάσεις είναι: |-3.2-5.2| =
8.4, |7.5-(-3.2)| = 10.7 και |12.22-7.5| = 4.72. Το πρόγραμμα θα εμφανίζει στο τέλος τον αρχικό πίνακα που
εισήγαγε ο χρήστης, σε μια γραμμή καθώς και τον πίνακα διαφορών σύμφωνα με την εκτέλεση που
παρουσιάζεται. Κάθε στοιχείο των πινάκων θα εμφανίζεται με ακρίβεια 2 δεκαδικών ψηφίων.
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

//Επεξεργασία
int main() {
   int i; //ορισμός τύπου μεταβλητής

   double table_1[5]; //ορισμός πίνακα_1  5 θέσεων για τους αριθμούς που θα εισάγω
   double table_2[4]; //ορισμός πίνακα_2 4 θέσεων για τις αποστάσεις που είναι 4 για 5 αριθμούς

   for (i=0; i<=4; i++){ // συμπληρώνω τον πίνακα_1 με πραγματικούς αριθμούς
      printf("Enter number (%d):",i);
      table_1[i] = GetReal();
   }
   double apostasi;
   for(i=0; i<=3; i++) { // Υπολογίζω τις αποστάσεις και τις συμπληρώνω στον πίνακα_2
        apostasi = fabs(table_1[i+1]-table_1[i]);
        table_2[i] = apostasi;
   }


   //Εμφάνιση Δεδομένων
   for(i=0; i<=4; i++)
      printf("%.2f ",table_1[i]);

   printf("\n");

   for(i=0; i<=3; i++)
      printf("%.2f ",table_2[i]);

   return 0;
 }

