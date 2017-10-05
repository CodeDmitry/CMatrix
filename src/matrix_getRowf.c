extern void *memcpy(void *, void *, unsigned int);

void matrix_getRowf (
    void *Out,
    void *In,
    int RowIndex,
    int ColumnsPerRow)
{
    #define __MATRIX_ROWSTARTOFFSET(ColsPerRow, RowIndex) (ColsPerRow * RowIndex)

    int rowStartIndex;
    
    rowStartIndex = __MATRIX_ROWSTARTOFFSET(ColumnsPerRow, RowIndex);    
    memcpy(Out, (float *)In + rowStartIndex, sizeof(float) * ColumnsPerRow);
    
    #undef __MATRIX_ROWSTARTOFFSET
}