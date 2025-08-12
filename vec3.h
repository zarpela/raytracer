#ifndef VEC3_H
#define VEC3_H

#if defined(__cplusplus)
#error "This header is for C only"
#endif

#include <cmath>
#include <stdio.h>
 
typedef struct
{
    double e[3];
}vec3;


static inline vec3 vec3new(float x, float y, float z)
{
    vec3 v = { {x,y,z} };
    return v;

}


using point3=vec3;





#endif