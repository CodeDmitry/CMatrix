#include <stdint.h>

void matrix_fillf (
    /* out */ void *pvResultMatrix, 
    /* in */ float fFillValue, 
    /* in */ uint32_t NumberOfRows, 
    /* in */ uint32_t ColumnsPerRow ) 
{    
    float *rm = (float *)pvResultMatrix;    
    float fv = fFillValue;
    uint32_t nr = NumberOfRows;
    uint32_t nc = ColumnsPerRow;
    uint32_t i;

    for (i = 0; i < nr*nc; ++i) {
        rm[i] = fv;
    }
}
