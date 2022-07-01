#include <stdint.h>

/**
 * Adds two matrices A and B and places the result into Out.
 *
 * Usage Examples:
 *     float msum[16];
 *     float m1[16];
 *     float m2[16];
 *     matrix_identityf(m1, 4, 1);
 *     matrix_identityf(m2, 4, 2);
 *     matrix_addf(msum, m1, m2, 4, 4);
 *
 * @param Out A pointer where to place the sum.
 * @param A The first matrix.
 * @param B The second matrix.
 * @param NumberOfRows The number of rows of given matrices.
 * @param ColumnsPerRow The column count of given matrices.
 */
void matrix_addf (
    void *Out, 
    void *A, 
    void *B, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow )
{    
    uint32_t i;
    
    for (i = 0; i < NumberOfRows * ColumnsPerRow; ++i) {
        ((float *)Out)[i] = ((float *)A)[i] + ((float *)B)[i];
    }
}
