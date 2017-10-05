extern double sin(double);
extern double cos(double);

void matrix3_rotationf (
    void *Out,
    float xangle,
    float yangle,
    float zangle,
    unsigned int option_bits)
{    
    #define __DEGREE_BIT 0
    #define __PI_F 3.14159265358979f
    
    float cosA;
    float sinA;
    float cosB;
    float sinB;
    float cosC;
    float sinC;
    float cosCcosB;
    float cosBsinA;
    float sinBsinA;

    if (option_bits & (0x1 << __DEGREE_BIT)) {
        float conversion;
        conversion = __PI_F / 180.f;
        xangle *= conversion;
        yangle *= conversion;
        zangle *= conversion;
    }        
    
    cosA = cos(xangle);
    sinA = sin(xangle);
    cosB = cos(yangle);
    sinB = sin(yangle);
    cosC = cos(zangle);
    sinC = sin(zangle);
    cosCcosB = cosC*cosB;
    cosBsinA = cosB*sinA;
    sinBsinA = sinB*sinA;

    ((float *)Out)[0] = cosCcosB;
    ((float *)Out)[1] = -sinC*cosA + cosC*sinBsinA;
    ((float *)Out)[2] = sinC*sinA + cosC*sinB*cosA;
    ((float *)Out)[3] = sinC*cosB;
    ((float *)Out)[4] = cosC*cosA + sinC*sinBsinA;
    ((float *)Out)[5] = -cosC*sinA + sinC*sinB*cosA;
    ((float *)Out)[6] = -sinB;
    ((float *)Out)[7] = cosBsinA;
    ((float *)Out)[8] = cosB*cosA;
                
    #undef __PI_F
    #undef __DEGREE_BIT
}
