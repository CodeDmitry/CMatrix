#include <stdint.h>

void matrix_getColumnf (
    /* out notnull */ void *pvResultMatrix,
    /* in notnull */ void *pvGivenMatrix,
    /* in */ uint32_t ColumnIndex,
    /* in */ uint32_t NumberOfRows,
    /* in */ uint32_t ColumnsPerRow )
{
    // | A temporary macro to get flat index of the 
    // |     element at [rowidx][colidx], given
    // |     a specified row length(rowlen).
    // | rowlen: Row Length.
    // | rowidx: Row Index.
    // | colidx: Column Index.
    // | result: offset units to get [rowidx][colidx].
    #define matidx(rowlen, rowidx, colidx) \
        (rowlen*rowidx + colidx)
    
    float *rm = (float *)pvResultMatrix;
    float *gm = (float *)pvGivenMatrix;
    uint32_t ci = ColumnIndex;
    uint32_t nr = NumberOfRows;
    uint32_t nc = ColumnsPerRow;
    uint32_t i;
    
    for (i = 0; i < nr; ++i) {        
        rm[i] = gm[matidx(nc, i, ci)];
    }
    
    // | Release the macro, as this file might
    // |     get cut/pasted into another file.
    #undef matidx
}
