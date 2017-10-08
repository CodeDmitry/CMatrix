#include <stdint.h>

void matrix_scaleRowf ( 
    void *Target, 
    uint32_t ColumnsPerRow, 
    uint32_t RowIndex, 
    float Coefficient)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;

    for (i = 0; i < ColumnsPerRow; ++i) {
        ((float *)Target)[__MATRIX_INDEX(ColumnsPerRow, RowIndex, i)] *= Coefficient;
    }
    
    #undef __MATRIX_INDEX
}
