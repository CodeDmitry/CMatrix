void matrix_scaleRowf ( 
    void *M, 
    int ColumnsPerRow, 
    int RowIndex, 
    float Coefficient)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;

    for (i = 0; i < ColumnsPerRow; ++i) {
        ((float *)M)[__MATRIX_INDEX(ColumnsPerRow, RowIndex, i)] *= Coefficient;
    }
    
    #undef __MATRIX_INDEX
}
