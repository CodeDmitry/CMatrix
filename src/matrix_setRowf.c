#include <stdint.h>

void matrix_setRowf (
    void *Out,
    void *In,
    uint32_t RowIndex,
    uint32_t ColumnsPerRow)
{
    uint32_t rowStartIndex;
    uint32_t i;
    
    rowStartIndex = ColumnsPerRow * RowIndex;    
    
    for (i = 0; i < 4; ++i) {
        ((float *)Out)[rowStartIndex + i] = ((float *)In)[i];
    }
}
