
/*File a8f8
Να γραφεί ένα πρόγραμμα που να περιλαμβάνει μια δομή box, η οποία αναπαριστά ορθογώνια
παραλληλεπίπεδα, και περιλαμβάνει πέντε ακέραια πεδία: width (πλάτος), height (ύψος), depth
(βάθος), area (επιφάνεια) και volume (όγκος). Το πρόγραμμα θα περιλαμβάνει τις παρακάτω
συναρτήσεις:
 Μια συνάρτηση που να ζητά από το χρήστη τις διαστάσεις του κουτιού σε cm (μη-αρνητικοί ακέραιοι –
δεν απαιτείται έλεγχος), δηλαδή το πλάτος, ύψος και βάθος (width, height, depth) και θα επιστρέφει
δομή box με τα αντίστοιχα τρία πεδία συμπληρωμένα.
 Μια void συνάρτηση που να υπολογίζει το συνολικό εμβαδόν όλων των πλευρών του κουτιού (πεδίο
area). H συνάρτηση θα ενημερώνει το αντίστοιχο πεδίο της δομής.
 Μια void συνάρτηση που να υπολογίζει τον όγκο (πεδίο volume) του κουτιού. H συνάρτηση θα
ενημερώνει το αντίστοιχο πεδίο της δομής.
 Οι δύο παραπάνω τιμές (area και volume) θα τυπώνονται από τη συνάρτηση main.
Και οι δύο συναρτήσεις να δέχονται ως παράμετρο έναν δείκτη στη δομή box.
 */
#include <stdio.h>
#include <ctype.h>
#include "genlib.h"


//ΟΡΙΣΜΟΣ ΔΟΜΗΣ
typedef struct {
    int width;
    int height;
    int depth;
    int area;
    int volume;
} box;

//ΟΡΙΣΜΟΣ ΣΥΝΑΡΤΗΣΕΩΝ
void read_boxes(box *ptr_kouti);
void synoliko_emvadon (box *ptr_kouti);
void ogkos(box *ptr_kouti);

//ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ
int main()
{
    //Θέτω δείκτη στη δομή
    box kouti;
    box *ptr_kouti;
    ptr_kouti = &kouti;

    //καλώ τις συναρτήσεις
    read_boxes(&kouti);
    synoliko_emvadon (&kouti);
    ogkos(&kouti);
         //Εμφάνιση αποτελεσμάτων
         printf("To emvadon tou koutiou einai %d cm2\n",kouti.area);
         printf("O ogos tou koutiou einai %d cm3",kouti.volume);

  return 0;

 }

//ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΕΙΣΑΓΕΙ ΤΑ 3 ΣΤΟΙΧΕΙΑ ΤΗΣ ΔΟΜΗΣ
void read_boxes(box *ptr_kouti){
        printf("Dose to mikos tou koutiou se cm: ");
        ptr_kouti->width=GetInteger();
        printf("Dose to ypsos tou koutiou se cm: ");
        ptr_kouti->height=GetInteger();
        printf("Dose to vathos tou koutiou se cm: ");
        ptr_kouti->depth=GetInteger();

 }

//ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΥΠΟΛΟΓΙΖΕΙ ΤΟ ΕΜΒΑΔΟΝ(4ο στοιχείο δομής)
void synoliko_emvadon (box *ptr_kouti){
        int mikos = ptr_kouti->width;
        int ypsos = ptr_kouti->height;
        int vathos = ptr_kouti->depth;
        int emvadon = 2*(mikos*ypsos) + 2*(ypsos*vathos) + 2*(mikos*vathos);
        ptr_kouti->area = emvadon;
 }

//ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΥΠΟΛΟΓΙΖΕΙ ΤΟΝ ΟΓΚΟ(5ο στοιχείο δομής)
void ogkos(box *ptr_kouti){
       int mikos = ptr_kouti->width;
       int ypsos = ptr_kouti->height;
       int vathos = ptr_kouti->depth;
       int ogkos = mikos * ypsos * vathos;
       ptr_kouti->volume = ogkos;
 }

 //ΤΕΛΟΣ
