#include <stdint.h>

extern double sin(double);
extern double cos(double);

void matrix4_rotationf (
    void *Out,
    float xangle,
    float yangle,
    float zangle,
    uint32_t flags)
{    
    #define __RADIANS_FLAG 0x1
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

    if (!(flags & __RADIANS_FLAG)) {
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
    ((float *)Out)[3] = 0;
    
    ((float *)Out)[4] = sinC*cosB;
    ((float *)Out)[5] = cosC*cosA + sinC*sinBsinA;
    ((float *)Out)[6] = -cosC*sinA + sinC*sinB*cosA;
    ((float *)Out)[7] = 0;
    
    ((float *)Out)[8] = -sinB;
    ((float *)Out)[9] = cosBsinA;
    ((float *)Out)[10] = cosB*cosA;
    ((float *)Out)[11] = 0;

    ((float *)Out)[12] = 0;
    ((float *)Out)[13] = 0;
    ((float *)Out)[14] = 0;
    ((float *)Out)[15] = 1;
                
    #undef __PI_F
    #undef __RADIANS_FLAG
}