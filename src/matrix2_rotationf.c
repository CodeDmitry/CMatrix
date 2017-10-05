void matrix2_rotationf (
    void *Out,
    float angle,
    unsigned int option_bits)
{    
    #define __DEGREE_BIT 0
    #define __PI_F 3.14159265358979f
    
    float cos_angle;
    float sin_angle;

    if (option_bits & (0x1 << __DEGREE_BIT)) {
        angle *= (__PI_F / 180.f);
    }        
    
    cos_angle = cos(angle);
    sin_angle = sin(angle);

    ((float *)Out)[0] = cos_angle;
    ((float *)Out)[1] = -1.f *  sin_angle;
    ((float *)Out)[2] = sin_angle;
    ((float *)Out)[3] = cos_angle;    
        
    #undef __PI_F
    #undef __DEGREE_BIT
}
