#include <stdint.h>

void matrix_fillf(
    void *Out, 
    float Value, 
    uint32_t Rows, 
    uint32_t Columns) 
{    
    uint32_t i;

    for (i = 0; i < Rows * Columns; ++i) {
        ((float *)Out)[i] = Value;
    }
}