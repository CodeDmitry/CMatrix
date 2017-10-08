#ifndef __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1
/* everything will be linked, so there's no point of hiding it. 
   
   If you need anything less, just create your own header, or 
   an extern statement in the file that has a dependency. 
   on CMatrix */
#define __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1

#include <stdint.h>

/* dump a matrix's string representation to a stream. */
extern void matrix_dumpf (
    void *Stream, 
    void *Matrix, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow);

/* scales row RowIndex of Target by Coefficient. */
void matrix_scaleRowf ( 
    void *Target, 
    uint32_t ColumnsPerRow, 
    uint32_t RowIndex, 
    float Coefficient);

/* copies column ColumnIndex of In to Out. */
extern void matrix_getColumnf (
    void *Out,
    void *In,
    uint32_t ColumnIndex,
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow);

/* copies In with every every slot scaled by Coefficient into Out. */
extern void matrix_multiply_scalarf (
    void *Out, 
    void *In,
    void *Coefficient,
    uint32_t NumberOfRows,
    uint32_t ColumnsPerRow);

/* sets Out to an identity matrix scaled by a Coefficient. */
extern void matrix_identityf (
    void *Out, 
    uint32_t Size, 
    float Coefficient);

/* sets Out to the sum of In1 and In2. */    
extern void matrix_addf (
    void *Out, 
    void *In1, 
    void *In2, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow);

/* fills every slot of Target with Value. */   
extern void matrix_fillf (
    void *Target, 
    float Value, 
    uint32_t NumberOfRows, 
    uint32_t ColumnsPerRow); 

/* Out(r1 by c2) = A(r1 by r1c2) * B(c1r2 by c2). */
extern void matrix_multiplyf (
    void *Out, 
    void *A, 
    void *B, 
    uint32_t r1, 
    uint32_t c1r2, 
    uint32_t c2);

/* puts a 2x2 rotaton matrix with angle degrees into Out.
set flags to 1 to use radians instead. */
extern void matrix2_rotationf (
    void *Out,
    float angle,
    uint32_t flags);
    
/* puts a 3x3 rotaton matrix with xangle,yangle,zangle degrees into Out
set flags to 1 to use radians instead. */
extern void matrix3_rotationf (
    void *Out,
    float xangle,
    float yangle,
    float zangle,
    uint32_t option_bits)    

/* puts a 4x4 rotaton matrix with xangle,yangle,zangle degrees into Out
set flags to 1 to use radians instead. */
extern void matrix4_rotationf (
    void *Out,
    float xangle,
    float yangle,
    float zangle,
    uint32_t flags);


#endif /* __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1 */