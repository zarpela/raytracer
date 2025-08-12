#include <stdio.h>

int main()
{
    // image
    int image_height = 256;
    int image_width = 256;

    printf("P3\n%i %i\n255\n", image_height, image_width);
    // render
    for(int j = 0; j<image_height; j++)
    {
        for(int i = 0; i<image_width; i++)
        {
            fprintf(stderr, "\r Scanlines remaining: %i", (image_height-j));
            fflush(stderr);
            float r = (double)i/(image_width-1);
            float g = (double)j/(image_height-1);
            float b = 0.0f;

            int ir = (int)255.999*r;
            int ig = (int)255.999*g;
            int ib = (int)255.999*b;
            printf("%i %i %i\n", ir, ig, ib);
        }
    }
    fprintf(stderr, "\rPRONTO!                              \n");

    return 0;
}