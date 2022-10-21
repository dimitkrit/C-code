/*FileName: a13f5
*  ------------------
* Να γραφεί πρόγραμμα το οποίο:
(α) Θα ζητά από τον χρήστη δύο θετικούς ακέραιους αριθμούς R (γραμμές) και C (στήλες) από το 1 μέχρι
και το 10. Μπορείτε να υποθέσετε με ασφάλεια ότι ο χρήστης θα εισάγει σωστούς αριθμού σύμφωνα με τα
προηγούμενα όρια. Δεν απαιτείται έλεγχος. Η εισαγωγή θα γίνεται από την συνάρτηση main.
(β) Θα "γεμίζει" τα στοιχεία R x C ενός διδιάστατου πίνακα Α ακεραίων (διάστασης 10x10) με τυχαίους
ακέραιους από 0 έως και 99 (rand() % 100), μέσω κλήσης μιας συνάρτησης populate_data.
Δηλαδή το πρόγραμμα θα χρησιμοποιεί μέρος του πίνακα Α, βάσει των αριθμών R και C, που εισήγαγε ο
χρήστης.
(γ) Θα καλεί μια συνάρτηση print_array που θα τυπώνει τα R x C στοιχεία του πίνακα Α.
(δ) Θα καλεί μια διαδικασία change_array, η οποία για κάθε γραμμή του πίνακα Α θα θέτει όσα
στοιχεία είναι αριστερά του μέγιστου της γραμμής ίσα με αυτό (δηλαδή όσα είναι στην ίδια γραμμή με
αυτό, αλλά έχουν μικρότερο δείκτη στήλης θα γίνουν ίσα με το μέγιστο).
(ε) Τέλος, θα εμφανίζονται και πάλι τα στοιχεία του "αλλαγμένου" πίνακα κατά γραμμές.
Όλες οι συναρτήσεις σας θα ακολουθούν το πρότυπο C99 για πίνακες 2 διαστάσεων. ΠΡΟΣΟΧΗ στις
δηλώσεις των παραμέτρων των συναρτήσεων. Είναι άλλο η διάσταση του πίνακα, και άλλο ποιο μέρος του
πίνακα έχει χρησιμοποιηθεί. θα πρέπει να περάσετε περισσότερες παραμέτρους
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

#define R 10
#define C 10


void populate_data(int ur, int uc, int rows, int cols,int P[rows][cols]);
void change_array(int ur, int uc, int rows, int cols, int P[rows][cols]);
void print_array(int ur, int uc, int rows, int cols, int P[rows][cols]);

int main()
{
    int A[R][C];

    int row;
    int col;

    printf("Dwse ton arithmo twn grammwn: ");
    row = GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    col = GetInteger();



   //Γέμισμα του πίνακα Α με τυχαίους αριθμούς
	populate_data(row, col, R, C,  A);

    //Εμφάνιση των στοιχείων του πίνακα Α
    printf("ARXIKOS PINAKAS \n");
    print_array(row, col, R, C,  A);

   //Αλλαγή στοιχείων πίνακα και εμφάνιση
    printf("ALLAGMENOS PINAKAS \n");
    change_array(row, col, R, C,  A);
    print_array( row, col, R, C,  A);




return 0;

}

//ΟΡΙΣΜΟΙ ΣΥΝΑΡΤΗΣΕΩΝ

//Γέμισμα του πίνακα Α με τυχαίους αριθμούς
void populate_data(int ur, int uc, int rows, int cols,int P[rows][cols]){

    int i;
    int j;
    for (i =0; i<ur; i++)
        for (j=0; j<uc; j++)
            P[i][j] = rand() % 100;

}

//Εμφάνιση στοιχείων πίνακα
void print_array(int ur, int uc,int rows, int cols, int P[rows][cols]){

    int i;
    int j;
    for (i =0; i<ur; i++)
    {
        for (j=0; j<uc; j++)
            printf("%3d ",P[i][j]);
        printf("\n");
    }

}

//Αλλαγή στοιχείων πίνακα
void change_array(int ur, int uc, int rows, int cols, int P[rows][cols]){

    int k;
    int i;
    int j;
    int mx;
    for (i=0; i<ur; i++){
        mx = P[i][0];
        for (j=1; j<uc; j++){
             if(P[i][j] > mx){
               mx = P[i][j];
               for (k=0; k<j; k++){
                   P[i][k] = P[i][j];
               }
            }
       }
    }
 }


//ΤΕΛΟΣ

