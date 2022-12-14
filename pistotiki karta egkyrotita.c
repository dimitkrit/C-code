/*File a22f5.c
. Γράψτε ένα πρόγραμμα που θα ελέγχει την εγκυρότητα των αριθμών πιστωτικών καρτών. Το πρόγραμμα θα
διαβάζει ένα δεκαεξαψήφιο ακεραίο (long) από τον χρήστη (με την συνάρτηση GetLong()) και θα
τυπώνει τον αριθμό της κάρτας ακολουθούμενο από τη λέξη "VALID" αν αυτός είναι έγκυρος αριθμός
πιστωτικής κάρτας ή τη λέξη "invalid" διαφορετικά, σύμφωνα με τα μηνύματα που εμφανίζονται
παρακάτω.
Για την υλοποίηση της άσκησης θα δημιουργήσετε ένα πίνακα τύπου long, μεγέθους 16, στον οποίο σε κάθε
θέση του πίνακα θα βάλετε ένα ψηφίο του κωδικού.
Ο έλεγχος εγκυρότητας του κάθε δεκαεξαψήφιου αριθμού γίνεται σύμφωνα με τα ακόλουθα:
• Αν το πρώτο ψηφίο είναι μικρότερο από 4 ή μεγαλύτερο από 7, η κάρτα χαρακτηρίζεται ως μη
έγκυρη.
• Αν ο αριθμός δεν έχει ακριβώς 16 ψηφία τότε η κάρτα είναι μη έγκυρη.
• Διαφορετικά:
◦ Διπλασιάζουμε (μόνο) τα ψηφία που βρίσκονται στις περιττές θέσεις του αριθμού (δηλαδή τα 1ο,
3ο, 5ο,..., 15ο, όπως φαίνονται στο παράδειγμα εκτέλεσης με κίτρινο χρώμα). Όσα από αυτά
γίνουν διψήφια, προσθέτουμε τα ψηφία τους για να γίνουν μονοψήφια. Παραδείγματα:
▪ αρχικό ψηφίο 4, 2*4=8 άρα νέο ψηφίο 8.
▪ αρχικό ψηφίο 7, 2*7=14 άρα νέο ψηφίο 1+4 =5.
◦ Υπολογίσουμε το άθροισμα όλων των νέων ψηφίων που προκύπτουν (δηλαδή τόσο εκείνα σε
περιττές θέσεις μετά τις αλλαγές όσο και εκείνα στις άρτιες). Αν το άθροισμα των 16 ψηφίων είναι
ακέραιο πολλαπλάσιο του 10, η κάρτα είναι έγκυρη. και σε διαφορετική περίπτωση μη έγκυρη.
*/
#include <stdio.h>
#include "simpio.h"
#include "genlib.h"


//Ορισμός τύπου συνάρτησης
long long GetLongLong(void);


//Επεξεργασία
main() {

   long long table[16]; //Ορισμός πίνακα κωδικού
   long long code; // Ορισμός τύπου κωδικού
   long long CODE;
   printf("Insert card number(%lld psifia): ",code);
   code = GetLongLong(); //Εισαγωγή κωδικού
   CODE = code; // η μεταβλητή CODE θα μου χρειαστεί στην εγκυρότητα αριθμού ψηφίων.
                // επειδή η code για τους υπολογισμούς των ψηφίων θα αλλάξει τιμή.

   //Ορισμός τύπων μεταβλητών
   long long a;
   long long i;
   i=1000000000000000;
   int j;

   //Διάκριση ψηφίων κωδικών και εισαγωγή τους στον πίνακα
   for(j=0; j<=15; j++){
        a = code / i;
        table[j] = a;
        code = code % i;
        i = i / 10;
   }

   //Προβολή ψηφίων πίνακα για επιβεβαίωση σωστού υπολογισμού
   //for(i=0; i<=15; i++)
        //printf("%lld",table[i]);

   //Έλεγχος εγκυρότητας για το πρώτο ψηφίο
   if(table[0] < 4 || table[0] > 7){
        for(i=0; i<=15; i++)
            printf("%lld",table[i]);
            printf(" is invalid");
            printf("\n");

   }
   else {
       //Έλεγχος εγκυρότητας για αριθμό ψηφίων
       long long K;
       CODE / 1000000000000000 ==  K;
       if (K < 1 ){
           for(i=0; i<=15; i++)
               printf("%lld",table[i]);
               printf(" is invalid");
       }

       else{
          //Τρίτος έλεγχος εγκυρότητας
          //(άθροισμα στοιχείων σε περιττές και άρτιες θέσεις)
          long long sum_1 = 0;
          long long sum_2 = 0;
          long long ginomeno;
          long long b;
          //Υπολογισμός αθροίσματος στοιχείων περιττών θέσεων
          for(i=0; i<=15; i+=2){
              ginomeno = table[i]*2;
              if((ginomeno / 10) >= 1 ){
                   a = ginomeno / 10;
                   b = ginomeno % 10;
                   ginomeno = a + b;

             }
              sum_1 = sum_1 + ginomeno;
          }
          //Υπολογισμός αθροίσματος στοιχείων άρτιων θέσεων
          for(i=1; i<=15; i+=2)
              sum_2  =  sum_2 + table[i];

          //Έλεγχος συνολικού αθροίσματος ακέραιου πολλαπλάσιου του 10
          long long sum;
          sum = sum_1 + sum_2;

          for(i=0; i<=15; i++)
              printf("%lld",table[i]);
              if((sum % 10 ) == 0)
                    printf(" is VALID");
              else
                    printf(" is invalid");
        }
    }
}

//Συνάρτηση (ο ακέραιος που δίνουμε έχει πολλά ψηφία)
long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}

//ΤΕΛΟΣ
