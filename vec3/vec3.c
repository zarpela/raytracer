#include <stdio.h>


typedef struct
{
    float a, b, c;
    
} vec3;

    
vec3 sum(vec3 x, vec3 y)
{
    vec3 result;
    result.a = x.a + y.a;
    result.b = x.b + y.b;
    result.c = x.c + y.c;
    return result;
}

vec3 scalar(vec3 vec, float scalar)
{
    vec3 result;
    result.a = vec.a*scalar;
    result.b = vec.b*scalar;
    result.c = vec.c*scalar;
    
    return result;
}

float dot (vec3 x, vec3 y){
    return x.a * y.a + x.b * y.b + x.c * y.c;
}

int main()
{
    printf("vamos");
    vec3 v1 = {1.5f,  9.421f, 3.4f};
    float d1 = dot(v1, v1);
    printf("%f", d1);
    return 0;
}