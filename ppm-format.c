#include <stdio.h>
#include <stdlib.h>
#include "vec3.h"
#include "color.h"




int main()
{
    // image
    int image_width = 2560;
    int image_height = 1440;
    

    printf("P3\n%i %i\n255\n", image_width, image_height);
    // render
    for(int j = 0; j<image_height; j++)
    {
        for(int i = 0; i<image_width; i++)
        {
            fprintf(stderr, "\r Scanlines remaining: %i", (image_height-j));
            fflush(stderr);
            color pixel_color = vec3_new(
                (double)i/(image_width-1),
                ((double)i/(image_width-1)+(double)j/(image_height-1))/2.0,
                (double)j/(image_height-1)
            );
            write_color(&pixel_color);
        }
    }
    fprintf(stderr, "\rPRONTO!                              \n");

    return 0;
}