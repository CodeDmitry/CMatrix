#include <stdint.h>

void matrix_multiply_scalarf (
    void *Out, 
    void *In, 
    uint32_t Coefficient, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow) 
{
    uint32_t i;
    
    for (i = 0; i < NumberOfRows * ColumnsPerRow; ++i) {
        ((float *)Out)[i] = ((float *)In)[i] * Coefficient;
    }
}