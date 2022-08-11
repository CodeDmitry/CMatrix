#include <stdint.h>

void matrix_transposef (
    void *Out, 
    void *In, 
    uint32_t Rows, 
    uint32_t ColumnsPerRow )
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) \
        (__RowLength * __RowIndex + __ColumnIndex)

    uint_fast32_t i;
    uint_fast32_t j;
    
    for (i = 0; i < Rows; ++i) {
        for (j = 0; j < ColumnsPerRow; ++j) {
            ((float *)Out)[__MATRIX_INDEX(ColumnsPerRow, i, j)] 
                = ((float *)In)[__MATRIX_INDEX(Rows, j, i)]
                ;
        }
    }
    
    #undef __MATRIX_INDEX
}
