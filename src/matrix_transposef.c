#include <stdint.h>

void matrix_transposef (
    /* out */ void *pvResultMatrix, 
    /* in */ void *pvGivenMatrix, 
    /* in */ uint32_t dwRows, 
    /* in */ uint32_t dwColumnsPerRow )
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

    uint_fast32_t i;
    uint_fast32_t j;
    float *rm = (float *)pvResultMatrix;
    float *gm = (float *)pvGivenMatrix;
    uint32_t nr = dwRows;
    uint32_t nc = dwColumnsPerRow;
    
    for (i = 0; i < nr; ++i) {
        for (j = 0; j < nc; ++j) {
            rm[matidx(nc, i, j)] = gm[matidx(nr, j, i)];
        }
    }
    
    // | Release the macro, as this file might
    // |     get cut/pasted into another file.
    #undef matidx
}
