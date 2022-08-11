#include <stdint.h>

void matrix_setColumnf (
    void *Out,
    void *In,
    uint32_t ColumnIndex,
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow )
{
    uint32_t i;
            
    for (i = 0; i < NumberOfRows; ++i) { 
        int32_t outIndex = ColumnsPerRow*i + ColumnIndex;
        ((float *)Out)[outIndex] = ((float *)In)[i];
    }    
}
