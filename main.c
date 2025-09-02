
#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

color ray_color(const ray *r)
{
    return vec3_new(0,0,0);
}

int main()
{
    double aspect_ratio = 16/9;
    int image_width = 400;

    // calcular a altura do imagem e ter certeza que é pelo menos 1
    int image_height = (int) (image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    

    //camera
    double focal_length = 1.0;

    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width)/image_height; // viewport com tamanho menor que tá suave porque eles tao tamanho real (double no caso)
    point3 camera_center = vec3_new(0,0,0);

    // calcular os vetores u e v do viewport ( revisar pra entender melhor )
    vec3 viewport_u = vec3_new(viewport_width, 0, 0);
    vec3 viewport_v = vec3_new(0, -viewport_height, 0);// imagino que é negativo porque tem que descer e tamo usando y+ sobe
    //vec3 *vuP = &viewport_u;
    
    //calcular o delta u e o delta v
    vec3 pixel_delta_u =  vec3_div(&viewport_u, viewport_width);//viewport_u / viewport_width;
    vec3 pixel_delta_v = vec3_div(&viewport_v, viewport_height);// viewport_v / vp_height

    // calcular a posicao do pixel superior esquerdo (0,0)

        // codigo em c++:
        //     auto viewport_upper_left = camera_center - vec3(0, 0, focal_length)
        //                               - viewport_u/2 - viewport_v/2;
    
    vec3 z_vector = vec3_new(0, 0, focal_length); 

    vec3 halfViewportU = vec3_div(&viewport_u, 2); // calcular a metade dos viewports
    vec3 halfViewportV = vec3_div(&viewport_v, 2);

        //fazer as operacoes intermediarias
    vec3 tempResult1 = vec3_subtraction(&camera_center, &z_vector);
    vec3 tempResult2 = vec3_subtraction(&tempResult1, &halfViewportU);
    vec3 tempResult3;
    point3 viewport_upper_left = vec3_subtraction(&tempResult2, &halfViewportV);

        //auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    tempResult1 = vec3_sum(&pixel_delta_u, &pixel_delta_v);
    tempResult2 = vec3_scale(&tempResult1, 0.5);
    point3 pixel00_loc = vec3_sum(&viewport_upper_left, &tempResult2);

    // render
    printf("P3\n%i %i\n255\n", image_width, image_height);
    for(int j = 0; j<image_height; j++)
    {
        for(int i = 0; i<image_width; i++)
        {
            fprintf(stderr, "\r Scanlines remaining: %i", (image_height-j));
            fflush(stderr);
            
            tempResult1 = vec3_scale(&pixel_delta_u, i);
            tempResult2 = vec3_scale(&pixel_delta_v, j);
            tempResult3 = vec3_sum(&tempResult1, &tempResult2);
            point3 pixel_center = vec3_sum(&pixel00_loc, &tempResult3);

            vec3 ray_direction = vec3_subtraction(&pixel_center, &camera_center);
            ray r = ray_new(&camera_center, &ray_direction);

            color pixel_color = ray_color(&r);
            write_color(&pixel_color);
        }
    }
    fprintf(stderr, "\rPRONTO!                              \n");





    

    
    



    return 0;       
}