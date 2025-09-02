#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <stdio.h>

typedef vec3 color;


void write_color(const color *pixel_color)
{
    double r = vec3_x(pixel_color);
    double g = vec3_y(pixel_color);
    double b = vec3_z(pixel_color);

    // r g b estao entre 0 e 1, essas linhas normalizam isso
    int rbyte = (int)255.999 * r; 
    int gbyte = (int)255.999 * g;
    int bbyte = (int)255.999 * b;
    printf("%d %d %d\n", rbyte, gbyte, bbyte);

}



#endif