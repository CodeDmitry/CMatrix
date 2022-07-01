#include <stdio.h>

extern void asmMain();

FILE *stdout2;

int main(int argc, char **argv)
{
    stdout2 = stdout;
    
    asmMain();
}
