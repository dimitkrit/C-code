/*FileName: a14f4.c
*  ------------------
* . Να γίνει πρόγραμμα το οποίο:
 Θα διαβάζει τις τιμές τριών ακεραίων αριθμών a, b, c,
 Θα υπολογίζει και θα εμφανίζει την τιμή της παράστασης (double):
y=2*max( a,b)+3∗gr(a,b,c )4 όπου max(a, b) είναι η συνάρτηση υπολογισμού του μεγίστου των αριθμών a και b
και gr(a, b, c) η συνάρτηση υπολογισμού του μεγίστου τριών αριθμών a, b, c. Το
διάβασμα των τριών αριθμών, ο υπολογισμός και εμφάνιση της τιμής της παράστασης θα
γίνουν στο κυρίως πρόγραμμα, χρησιμοποιώντας τις συναρτήσεις max και gr που θα
υλοποιήσετε ως συναρτήσεις στην C. Το αποτέλεσμα (y) θα εμφανίζεται με ακρίβεια 2 δεκαδικών ψηφίων..
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

//Δήλωση συναρτήσεων
int max(int a,int b);
int gr(int a, int b, int c);

//Επεξεργασία - Εμφάνιση Δεδομένων
int main() {
   int a,b,c;
   double y;

   printf("Dwse a: ");
   a = GetInteger();
   printf("Dwse b: ");
   b = GetInteger();
   printf("Dwse c: ");
   c = GetInteger();

   y=(double)(2*max(a,b)+3*gr(a,b,c))/4;

   printf("y = %.2f\n ",y);

   return 0;
}

//Συναρτήσεις

//Συνάρτηση υπολογισμού μεγίστου δυο αριθμών
int max(int a, int b){
     if( a > b )
       return a;
     else
       return b;

     }

//Συνάρτηση υπολογισμού τριών αριθμών
int gr(int a, int b, int c){
     int maxnumber;
     maxnumber = 0;
     if( a > b )
        maxnumber = a;
     else
        maxnumber = b;
     if ( c > maxnumber )
        maxnumber = c;

     return maxnumber;


}

//ΤΈΛΟΣ





