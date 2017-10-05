void matrix_transposef(void *Out, void *In, int Rows, int ColumnsPerRow)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;
    int j;
    
    for (i = 0; i < Rows; ++i) {
        for (j = 0; j < ColumnsPerRow; ++j) {
            ((float *)Out)[__MATRIX_INDEX(ColumnsPerRow, i, j)] = ((float *)In)[__MATRIX_INDEX(Rows, j, i)];
        }
    }
    
    #undef __MATRIX_INDEX
}