/* File a20f3.c
 * --------------
 * ���� �� ��������� ������� �� ����������
 * ��� �� ��������� ������ ��� ��� ����� �������
 * ��� ������� � �������
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

    //������ ����������
    int ilikia;
    int maxilikia;
    int minilikia;

    //������� ���������
     printf("Dwse ilikia: ");
     ilikia = GetInteger();
     maxilikia = 0;
     minilikia = ilikia;

    //����������� - ������� ���������
     while (ilikia != -1) {
            if (ilikia > maxilikia)
                 maxilikia = ilikia;
            if (ilikia < minilikia)
                 minilikia = ilikia;
            printf("Dwse ilikia: ");
            ilikia = GetInteger();
           }

    //�������� �������������
    printf("H megalyteri ilikia einai %d\n", maxilikia);
    printf("H mikroteri ilikia einai %d\n", minilikia);

   }

   //�����
