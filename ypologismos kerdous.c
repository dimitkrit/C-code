/* File: a4f1.c
---------------
This program calculates the profit
and the total amount from a sale
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {
   //Δήλωση μεταβλητών
   long purchaseAmount;
   int rate;
   double profit, saleAmount;


   //Είσοδος Δεδομένων
   printf("Dwse thn katharh axia: ");
   purchaseAmount = GetLong();

   printf("Dwse to pososto kerdous: ");
   rate = GetInteger();

   //Επεξεργασία Δεδομένων
   profit = purchaseAmount * rate/100;
   saleAmount = purchaseAmount + profit;

   //Εμφάνιση αποτελεσμάτων
   printf("To kerdos einai %g\n", profit);
   printf("To synoliko poso einai %g\n", saleAmount);

 }
