#include <stdint.h>

void matrix_getColumnf (
    void *Out,
    void *In,
    uint32_t ColumnIndex,
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;
    
    for (i = 0; i < NumberOfRows; ++i) {        
        ((float *)Out)[i] = ((float *)In)[__MATRIX_INDEX(ColumnsPerRow, i, ColumnIndex)];
    }
    
    #undef __MATRIX_INDEX
}