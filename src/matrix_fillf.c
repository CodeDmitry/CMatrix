void matrix_fillf(void *Out, float Value, int Rows, int Columns) 
{    
    int i;

    for (i = 0; i < Rows * Columns; ++i) {
        ((float *)Out)[i] = Value;
    }
}