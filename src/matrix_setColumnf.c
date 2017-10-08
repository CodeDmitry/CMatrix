#include <stdint.h>

void matrix_setColumnf (
    void *Out,
    void *In,
    uint32_t ColumnIndex,
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;
    
    for (i = 0; i < NumberOfRows; ++i) {        
         ((float *)Out)[__MATRIX_INDEX(ColumnsPerRow, i, ColumnIndex)] = ((float *)In)[i];
    }
    
    #undef __MATRIX_INDEX
}