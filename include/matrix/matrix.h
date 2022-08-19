#ifndef __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1
/*\ 
|*| If you need anything less, just create your own
|*|     header, and select what you want to keep or 
|*|     leave out. 
|*| EACH service of this library is COMPLETELY
|*|     independant of EVERY other service.
\*/
#define __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1

#include <stdint.h>

/* implemented */

/** 
 * @brief Dumps the matrix's string representation into the 
 *     specified stream. 
 * @param Stream The FILE * into which to dump the matrix string 
 *     representation.
 * @param Matrix The pointer to the matrix.
 * @param NumberOfRows Number of rows in the matrix.
 * Weak contract: 
 *     - Stream must be a valid FILE pointer.
 *     - Matrix must be a valid Matrix pointer.
 *     - NumberOfRows must be correct.
 *     - ColumnsPerRow must be correct.
 */
extern void matrix_dumpf (
    /* in notnull */ void *Stream, 
    /* in notnull */ void *Matrix, 
    /* in */ uint32_t NumberOfRows, 
    /* in */ uint32_t ColumnsPerRow );

/** 
 * @brief Sets Out to an identity matrix scaled by a Coefficient. 
 * @param Out The target matrix pointer to assign to.
 * @param Size The size of the rows=columns for the matrix.
 * @param Coefficient The coefficient to fill the main diagonal with.
 * Weak contract: 
 *     - Out pointer must be be able to store the float matrix of 
 *           the specified(Size x Size) number of rows and columns.
 *     - ColumnsPerRow must be correct.
 */
extern void matrix_identityf (
    /* out notnull */ void *Out, 
    /* in */ uint32_t Size, 
    /* in */ float Coefficient );
    
/* Out(r1 by c2) = A(r1 by r1c2) * B(c1r2 by c2). */
extern void matrix_multiplyf (
    /* out notnull */ void *Out, 
    /* in notnull */ void *A, 
    /* in notnull */ void *B, 
    /* in */ uint32_t r1, 
    /* in */ uint32_t c1r2, 
    /* in */ uint32_t c2 );    

/* sets Out to the sum of In1 and In2. */    
extern void matrix_addf (
    /* out notnull */ void *Out, 
    /* in notnull */ void *In1, 
    /* in notnull */ void *In2, 
    /* in */ uint32_t NumberOfRows, 
    /* in */ uint32_t ColumnsPerRow );
    
/* copies column ColumnIndex of In to Out. */
extern void matrix_getColumnf (
    /* out notnull */ void *Out,
    /* in notnull */ void *In,
    /* in */ uint32_t ColumnIndex,
    /* in */ uint32_t NumberOfRows,
    /* in */ uint32_t ColumnsPerRow );

/* copies row RowIndex of In to Out. */
extern void matrix_getRowf (
    /* out notnull */ void *Out,
    /* in notnull */ void *In,
    /* in */ uint32_t RowIndex,
    /* in */ uint32_t ColumnsPerRow );

/* copies In with every every slot scaled by Coefficient into Out. */
extern void matrix_multiply_scalarf (
    /* out notnull */ void *Out, 
    /* in notnull */ void *In,
    /* in */ void *Coefficient,
    /* in */ uint32_t NumberOfRows,
    /* in */ uint32_t ColumnsPerRow);

/* fills every slot of Target with Value. */   
extern void matrix_fillf (
    /* in out notnull */ void *Target, 
    /* in notnull */ float Value, 
    /* in */ uint32_t NumberOfRows, 
    /* in */ uint32_t ColumnsPerRow ); 

/* scales row RowIndex of Target by Coefficient. */
extern void matrix_scaleRowf ( 
    /* in out notnull */ void *Target, 
    /* in */ uint32_t ColumnsPerRow, 
    /* in */ uint32_t RowIndex, 
    /* in */ float Coefficient );

/* scales column ColumnIndex of Target by Coefficient. */
extern void matrix_scaleColumnf (
    /* in out notnull */ void *Target, 
    /* in */ uint32_t NumberOfRows,
    /* in */ uint32_t ColumnsPerRow, 
    /* in */ uint32_t ColumnIndex, 
    /* in */ float Coefficient );

/* puts a 2x2 rotaton matrix with angle degrees into Out.
set flags to 1 to use radians instead. */
extern void matrix2_rotationf (
    /* out notnull */ void *Out,
    /* in */ float angle,
    /* in */ uint32_t flags );
    
/* puts a 3x3 rotaton matrix with xangle,yangle,zangle degrees into Out
set flags to 1 to use radians instead. */
extern void matrix3_rotationf (
    /* out notnull */ void *Out,
    /* in notnull */ float xangle,
    /* in */ float yangle,
    /* in */ float zangle,
    /* in opt */ uint32_t option_bits );    

/* puts a 4x4 rotaton matrix with xangle,yangle,zangle degrees into Out
set flags to 1 to use radians instead. */
extern void matrix4_rotationf (
    /* out */ void *Out,
    /* in */ float xangle,
    /* in */ float yangle,
    /* in */ float zangle,
    /* in opt */ uint32_t option_bits );

/* copies In to column ColumnIndex of Out.*/
extern void matrix_setColumnf (
    /* out notnull */ void *Out,
    /* in notnull */ void *In,
    /* in */ uint32_t ColumnIndex,
    /* in */ uint32_t NumberOfRows,
    /* in */ uint32_t ColumnsPerRow );

/* copies In to row RowIndex of Out.*/
extern void matrix_setRowf (
    /* out notnull */ void *Out,
    /* in notnull */ void *In,
    /* in */ uint32_t RowIndex,
    /* in */ uint32_t ColumnsPerRow );

/** 
 * @brief Transposes the matrix, that is, swaps its 
 *     rows with its columns.
 * @param pvResultMatrix An address specifying
 *     where to store the transposed matrix.
 * @param pvGivenMatrix An address of the original
 *     matrix.
 * @param dwNumberOfRows The number of rows in the matrix.
 * @param dwColumnsPerRow The number of columns on a 
 *     single row of a matrix.
 * Weak contract: 
 *     - pvResultMatrix and pvGivenMatrix are both 
 *          non-null, memory containing 
 *          dwNumberOfRows*dwColumnsPerRow elements.
 *     - pvResultMatrix is stored in writable memory.
 *     - pvGivenMatrix is stored in readable memory.
 */
extern void matrix_transposef ( 
    /* out notnull */ void *pvResultMatrix, 
    /* in notnull */ void *pvGivenMatrix, 
    /* in */ uint32_t dwNumberOfRows, 
    /* in */ uint32_t dwColumnsPerRow );

/** 
 * @brief Fills each element of the matrix pvResultMatrix
 *     with fFillValue.
 * @param pvResultMatrix An address specifying
 *     where to store the filled matrix.
 * @param fFillValue The value to fill each element of 
 *     pvResultMatrix.
 * @param dwNumberOfRows The number of rows in the matrix.
 * @param dwColumnsPerRow The number of columns on a 
 *     single row of a matrix.
 * Weak contract: 
 *     - pvResultMatrix is stored in writable memory.
 */
extern void matrix_fillf (
    /* out notnull */ void *pvResultMatrix, 
    /* in */ float fFillValue, 
    /* in */ uint32_t NumberOfRows, 
    /* in */ uint32_t ColumnsPerRow ) 

#endif /* __MATRIX_A6ACC912_1ED2_4C9A_82C4_1872183959E1 */
