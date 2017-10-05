extern int printf(const char *, ...);
extern int putchar(int);

void matrix_dumpf(void *M, int rows, int columns)
{   
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i, j;
    
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j) {
            float cur;
            
            cur = ((float *)M)[__MATRIX_INDEX(columns, i, j)]; 
            printf("%.3f", cur);
            if (j != columns - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    
    #undef __MATRIX_INDEX
}