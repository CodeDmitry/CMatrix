#include <stdint.h>

extern int fprintf(void *, const char *, ...);
extern int fputc(int, void *);

void matrix_dumpf (
    void *Stream, 
    void *Matrix, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow)
{   
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;
    uint32_t j;
    
    for (i = 0; i < NumberOfRows; ++i) {
        for (j = 0; j < ColumnsPerRow; ++j) {
            float cur;
            
            cur = ((float *)Matrix)[__MATRIX_INDEX(ColumnsPerRow, i, j)]; 
            fprintf(Stream, "%.3f", cur);
            if (j != ColumnsPerRow - 1) {
                fputc(' ', Stream);
            }
        }
        fputc('\n', Stream);
    }
    
    #undef __MATRIX_INDEX
}