#include <stdint.h>

void matrix_identityf(void *Out, uint32_t Size, float Coefficient)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;
    uint32_t j;
    
    for (i = 0; i < Size; ++i) {
        for (j = 0; j < Size; ++j) {
            float val;
            
            if (i == j) {
                val = Coefficient;
            } else {
                val = 0;
            }
            
            ((float *)Out)[__MATRIX_INDEX(Size, i, j)] = val;
        }
    }
    
    #undef __MATRIX_INDEX
}