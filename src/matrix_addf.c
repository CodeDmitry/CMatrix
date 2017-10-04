void matrix_addf (
    void *Out, 
    void *A, 
    void *B, 
    int r, 
    int c)
{    
    int i;
    
    for (i = 0; i < r * c; ++i) {
        ((float *)Out)[i] = ((float *)A)[i] + ((float *)B)[i];
    }
}