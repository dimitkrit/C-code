/* FileName: a7f2.c
*  ------------------
*  This program demosntrates the use
*  of conditionals
*/

# include <stdio.h>
# include "genlib.h"
# include "simpio.h"

main(){

    long code;
    int hours;
    double salary, wage, weekly_amount;

    printf("Enter the code: ");
    code = GetLong();

    if (code >= 1000) {
       printf("Enter the yearly salary: ");
       salary = GetReal();
       weekly_amount = salary / 52.0;
       }

    else {
        printf ("Enter the number of hours: ");
        hours = GetInteger();
        printf ("Enter the hourly wage: ");
        wage = GetReal();

        if(hours < 40){
           weekly_amount = (double)hours * wage;
       }
        else {
           weekly_amount = (40.0 * wage) + ((double)hours - 40.0) * 1.5 * wage;

       }
     }
    printf("The weekly amount is %g\n,", weekly_amount);
}
