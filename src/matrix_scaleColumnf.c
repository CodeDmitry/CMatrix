#include <stdint.h>

void matrix_scaleColumnf (
    void *Target, 
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow, 
    uint32_t ColumnIndex, 
    float Coefficient)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;

    for (i = 0; i < NumberOfRows; ++i) {
        ((float *)Target)[__MATRIX_INDEX(ColumnsPerRow, i, ColumnIndex)] *= Coefficient;
    }
    
    #undef __MATRIX_INDEX
}