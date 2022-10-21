#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int gcd(int a, int b);
int phi(int n);

int main()
{
   int x, i;
   printf("Enter X: ");
   x=GetInteger();
   for(i = 1; i <= x; i++)
        printf("phi (%d) = %d\n", i, phi(i));

    return 0;

}


int gcd(int a, int b)
{
while(b)
    {
        a %= b;
        //Εναλλαγή a & b
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int phi(int n)
{
    int result = 0;
    int k;
    for(k = 1; k <= n; k++)
        result += gcd(k, n) == 1;
    return result;
}
