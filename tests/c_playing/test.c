#include <stdio.h>
#include <matrix/matrix.h>

float m1[16];
float m2[16];
float m3[16];
float v1[4] = {1, 2, 3, 4};
float v2[4] = {7, 3, 5, 9};

int main(int argc, char **argv)
{
    matrix_identityf(m1, 4, 2.f);    
    matrix_identityf(m2, 4, 3.f);
    matrix_multiplyf(m3, m1, m2, 4, 4, 4);
    matrix_dumpf(stdout, m1, 4, 4);
    matrix_dumpf(stdout, m2, 4, 4);
    matrix_dumpf(stdout, m3, 4, 4);
    matrix_setColumnf(m3, v1, 0, 4, 4);
    matrix_setColumnf(m3, v1, 3, 4, 4);
    matrix_dumpf(stdout, m3, 4, 4);
    matrix_setRowf(m3, v2, 0, 4);
    matrix_setRowf(m3, v2, 3, 4);
    matrix_dumpf(stdout, m3, 4, 4);

    return 0;
}