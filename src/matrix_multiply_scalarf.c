void matrix_multiply_scalarf (
    void *Out, 
    void *In, 
    float Coefficient, 
    int Rows, 
    int ColumnsPerRow) 
{
    int i;
    for (i = 0; i < Rows * ColumnsPerRow; ++i) {
        ((float *)Out)[i] = ((float *)In)[i] * Coefficient;
    }
}