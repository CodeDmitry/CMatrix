#include <stdint.h>

extern double sin(double);
extern double cos(double);

void matrix2_rotationf (
    void *Out,
    float angle,
    uint32_t flags)
{    
    #define __RADIANS_FLAG 0x1
    #define __PI_F 3.14159265358979f
    
    float cos_angle;
    float sin_angle;

    if (!(flags & __RADIANS_FLAG)) {
        angle *= (__PI_F / 180.f);
    }        
    
    cos_angle = cos(angle);
    sin_angle = sin(angle);

    ((float *)Out)[0] = cos_angle;
    ((float *)Out)[1] = -1.0f * sin_angle;
    ((float *)Out)[2] = sin_angle;
    ((float *)Out)[3] = cos_angle;    
        
    #undef __PI_F
    #undef __RADIANS_FLAG
}
