/*File a6f6
 Να γραφεί ένα πρόγραμμα το οποίο εμφανίζει μέσους όρους σωματομετρικών στοιχείων μιας ομάδας Ν
ατόμων (το Ν είναι “σταθερά” και καθορίζεται με αντίστοιχη εντολή define). Για την υποβολή της
άσκησης μπορείτε να θέσετε το Ν ίσο με 5. Το πρόγραμμα θα εκτελεί τις παρακάτω λειτουργίες με τη χρήση
συναρτήσεων:
a. Θα διαβάζει Ν τετράδες ακέραιων αριθμών (σωματομετρικά στοιχεία) και θα τους καταχωρεί σε
διδιάστατο πίνακα (συνάρτηση readData). Κάθε τετράδα αναφέρεται στα στοιχεία ενός ατόμου, που
είναι κατά σειρά τα εξής:
 το φύλο (0 αν είναι άνδρας, 1 αν είναι γυναίκα)
 το βάρος (σε κιλά, ακέραια τιμή)
 το ύψος (σε εκατοστά, ακέραια τιμή)
 η ηλικία (σε χρόνια, ακέραια τιμή)
b. Θα εμφανίζει το μέσο όρο του βάρους, του ύψους και της ηλικίας τόσο για τους άνδρες όσο και για τις
γυναίκες. Ο υπολογισμός (και όχι η εμφάνιση) του μέσου όρου για κάθε ένα στοιχείο (ύψος, βάρος
ηλικία) θα γίνεται με τη βοήθεια μιας (και μόνο) συνάρτησης void FindMean. Εκτός των άλλων
παραμέτρων που θα ορίσετε στη συνάρτηση, αυτή θα έχει ως παράμετρο και έναν αριθμοδείκτη (τιμές 1,
2, 3). Ο αριθμοδείκτης θα δείχνει το αντίστοιχο στοιχείο της τετράδας, του οποίου ο μέσος όρος
υπολογίζεται στη συγκεκριμένη κλήση, δηλαδή τη κατάλληλη στήλη του διδιάστατου πίνακα. Για
παράδειγμα, όταν ο αριθμοδείκτης είναι 1, τότε θα υπολογίζεται ο μέσος όρος του βάρους. Η συνάρτηση
FindMean σε κάθε κλήση της θα «επιστρέφει» συγχρόνως τον αντίστοιχο μέσο όρο για τους άνδρες
και τον αντίστοιχο μέσο όρο για τις γυναίκες, θα «επιστρέφει» δηλαδή 2 τιμές. (δείτε παρατήρηση 5 για
τον όρο «επιστρέφει»).
Στη συνάρτηση main() θα καλούνται κατάλληλα οι παραπάνω συναρτήσεις/διαδικασίες προκειμένου να
διαβαστούν τα δεδομένα και στη συνέχεια να εμφανιστούν οι μέσοι όροι του βάρους, του ύψους και της
ηλικίας των ανδρών και των γυναικών. Οι μέσοι όροι θα εμφανίζονται με ακρίβεια ενός δεκαδικού ψηφίου.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 5
#define T 4

//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void readData(int rows, int cols, int P[rows][cols]);
void FindMean(int rows, int cols, int P[rows][cols], double* a, double* g,int ar );

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
    int PINAKAS[N][T];

    double mo_baros_a;
    double mo_ypsos_a;
    double mo_ilikia_a;
    double mo_baros_g;
    double mo_ypsos_g;
    double mo_ilikia_g;


    readData(N,T,PINAKAS);

    FindMean(N,T,PINAKAS,&mo_baros_a, &mo_baros_g,1);
    printf("Mesos oros barous andrwn: %.1f\n", mo_baros_a);
    printf("Mesos oros barous gynaikwn: %.1f\n", mo_baros_g);
    printf("\n");
    FindMean(N,T,PINAKAS,&mo_ypsos_a,&mo_ypsos_g,2);
    printf("Mesos oros ypsous andrwn: %.1f\n", mo_ypsos_a);
    printf("Mesos oros ypsous gynaikwn: %.1f\n", mo_ypsos_g);
    printf("\n");
    FindMean(N,T,PINAKAS,&mo_ilikia_a,&mo_ilikia_g,3);
    printf("Mesos oros hlikias andrwn: %.1f\n", mo_ilikia_a);
    printf("Mesos oros hlikias gynaikwn: %.1f\n", mo_ilikia_g);
    printf("\n");


}

//ΣΥΝΑΡΤΗΣΕΙΣ
void readData(int rows, int cols, int P[rows][cols]){
    int i;
    int j;

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j+=4){
            printf("Dwse fylo: ");
            P[i][j] = GetInteger();
            printf("Dwse baros: ");
            P[i][j+1] = GetInteger();
            printf("Dwse ypsos: ");
            P[i][j+2] = GetInteger();
            printf("Dwse ilikia: ");
            P[i][j+3] = GetInteger();
        }
        printf("-----\n");
    }
}

void FindMean(int rows, int cols, int P[rows][cols], double* a, double* g, int ar){
    double mo_men;
    double mo_women;
    int men = 0;
    int women = 0;
    int count_men = 0;
    int count_women = 0;
    int i;

    for(i=0; i<rows; i++){
       if(P[i][0] == 0){
         count_men+= P[i][ar];
         men++;
       }
       else
       {
         count_women+= P[i][ar];
         women++;
       }
    }
    mo_men = (double)count_men/men;
    *a = mo_men;
    mo_women = (double)count_women/women;
    *g = mo_women;

}


