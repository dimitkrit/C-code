/* File a13f3.c
 * --------------
 * ���� �� ��������� ���� ���� �������
 * ��� ���������� �� �������� ��� ��������� �(1/�)
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //������ ����������
    int N;
    int i;
    double athroisma=0.0;
    double klasma=0.0;

    //������� ���������
    printf("Dwse orio: ");
    N = GetInteger();

    //�����������
    i=1;
    while (i<=N){
        klasma = (double)1/i;
        athroisma = athroisma + klasma;
        i++;
    }
    // �������� �������������
    printf ("To athroisma einai: %.2f\n", athroisma);

}
    // �����

