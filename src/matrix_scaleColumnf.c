void matrix_scaleColumnf (
    void *M, 
    int Rows,
    int ColumnsPerRow, 
    int ColumnIndex, 
    float Coefficient)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;

    for (i = 0; i < Rows; ++i) {
        ((float *)M)[__MATRIX_INDEX(ColumnsPerRow, i, ColumnIndex)] *= Coefficient;
    }
    
    #undef __MATRIX_INDEX
}