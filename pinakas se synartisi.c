/*/*FileName: a16f5
*  ------------------
 Να αναπτυχθεί (με τη χρήση των συναρτήσεων που περιγράφονται) πρόγραμμα στο οποίο,
 - θα γεμίζει τον πίνακα a μεγέθους 50 με τυχαίους αριθμούς από το 0 έως το 9 χρησιμοποιώντας την
συνάρτηση rand() (a[i]=rand() % 10), της βιβλιοθήκης <stdlib.h> (συνάρτηση populate)
- θα εμφανίζει τον πίνακα a στην οθόνη (συνάρτηση printArr)
- θα ζητά έναν ακέραιο αριθμό Ν από το 0 έως και το 9 από τον χρήστη
- θα καλεί την συνάρτηση checkTable, η οποία θα υπολογίζει τον αριθμό των εμφανίσεων του αριθμού
Ν στον πίνακα a και τις θέσεις του πίνακα στις οποίες εμφανίζεται ο αριθμός
- θα εμφανίζει τα αποτελέσματα στο χρήστη, όπως φαίνεται στο παράδειγμα. Η εμφάνιση των
αποτελεσμάτων θα γίνεται από τη συνάρτηση main() (κυρίως πρόγραμμα), καλώντας την printArr.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

#define X 50

void populate(int rows, double P[rows]);
void printArr(int rows, double P[rows]);
int checkTable(int rows, double P[rows],int number);

int main()
{
    double a[X];
    int N;

     //Γέμισμα του πίνακα  με τυχαίους αριθμούς
	populate(X, a);

	//Εμφάνιση πίνακα
	printArr(X, a);

	printf("--------------\n");

	printf("Dose arithmo apo to 0 ews to 9: ");
	N = GetInteger();
    printf("\n");

	int count;
	//Υπολογισμός αριθμού εμφανίσεων του Ν και εμφάνιση θέσεων του Ν
	count = checkTable(X, a, N);
	printf("o Arithmos %d emfanizetai %d fores.\nStis Theseis:\n", N, count);
	printArr(count, a);
    printf("-----------------\n");


return 0;



}
//ΟΡΙΣΜΟΙ ΣΥΝΑΡΤΗΣΕΩΝ

//Γέμισμα του πίνακα  με τυχαίους αριθμούς
void populate(int rows, double P[rows]){

    int i;
    for (i =0; i<rows; i++)
        P[i] = rand() % 10;
}


 //Εμφάνιση πίνακα
void printArr(int rows, double P[rows]){

    int i;
    for (i =0; i<rows; i++)
        printf(" %.f ",P[i]);
    printf("\n");

}

 // Υπολογισμός αριθμού εμφανίσεων του Ν και εμφάνιση θέσεων του Ν
int checkTable(int rows, double P[rows],int number){
    double C[rows];
    int a=0;
    int i;
    int sum=0;
    for (i=0; i<rows; i++)
        if (P[i] == number){
            sum ++;
            C[a] = (double)i;
            a+=1;

        }
    for (i=0; i<sum; i++)
            P[i] = C[i];
    return sum;


    }

//TELOS

