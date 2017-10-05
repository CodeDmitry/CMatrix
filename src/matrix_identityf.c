void matrix_identityf(void *M, int Size, float Value)
{
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;
    int j;
    
    for (i = 0; i < Size; ++i) {
        for (j = 0; j < Size; ++j) {
            float val;
            
            if (i == j) {
                val = Value;
            } else {
                val = 0;
            }
            
            ((float *)M)[__MATRIX_INDEX(Size, i, j)] = val;
        }
    }
    
    #undef __MATRIX_INDEX
}