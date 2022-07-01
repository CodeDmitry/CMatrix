#include <stdint.h>

/**
 * Creates a Size*Size matrix with Coefficient on each element of the main diagonal.
 *
 * Usage Examples:
 * creating an identity 4x4 matrix:
 *     float m1[16];
 *     matrix_identityf(m1, 4, 1);
 * creating a 3x3 identity matrix where the main diagonal is filled with "7".
 *     float m1[9];
 *     matrix_identityf(m1, 3, 7);
 *
 * @param Out a pointer where to place the identity matrix requested.
 * @param Size indicates the number of both rows and columns for this identity matrix.
 * @param Coefficient indicates the coefficient to place on the main diagonal of the matrix.
 */
void matrix_identityf(void *Out, uint32_t Size, float Coefficient)
{
    /** given row size and indices, compute flat offset into the matrix. */ 
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) \
        (__RowLength * __RowIndex + __ColumnIndex)

    uint32_t i;
    uint32_t j;
    float *lpOut = (float *)Out;
    
    for (i = 0; i < Size; ++i) {
        for (j = 0; j < Size; ++j) {
            float val;
            
            /** If we are on the main diagonal, use the Coefficient, otherwise use 0. */
            if (i == j) {
                val = Coefficient;
            } else {
                val = 0;
            }
            
            /** Fill the elements of the matrix. */
            lpOut[__MATRIX_INDEX(Size, i, j)] = val;
        }
    }
    
    /** limit lifetime of the macro to this scope. */
    #undef __MATRIX_INDEX
}
