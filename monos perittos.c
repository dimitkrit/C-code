/* File a23f3.c
 * --------------
 * ���� �� ��������� ��������� ��� �������
 * ��������� ��� ������� ��� �������
 * � ������� ������� �� ����� �����
 * � �������� �������
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //������ ����������
    int arithmos;
    int i;

    //������� ���������
     printf("Enter number: ");
     arithmos = GetInteger();

    //����������� - �������� ���������
     if ((arithmos%2) == 0) {
         for (i=0; i<=arithmos; i=i+2 )
            printf("%d ",i);
        }
     else {
         for (i=1; i<=arithmos; i=i+2)
            printf("%d ",i);
        }
    }

    //�����
