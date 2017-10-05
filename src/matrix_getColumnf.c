void matrix_getColumnf (
    void *Out,
    void *In,
    int ColumnIndex,
    int Rows,
    int ColumnsPerRow)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;
    
    for (i = 0; i < Rows; ++i) {        
        ((float *)Out)[i] = ((float *)In)[__MATRIX_INDEX(ColumnsPerRow, i, ColumnIndex)];
    }
    
    #undef __MATRIX_INDEX
}