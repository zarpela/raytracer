#ifndef VEC3_H
#define VEC3_H

#if defined(__cplusplus)
#error "This header is for C only"
#endif

#include <math.h>
#include <stdio.h>
 
typedef struct //definicao do struct vec3
{
    double e[3];
} vec3;

typedef vec3 point3; // só pra diferenciar pra calculos geometricos

// construtor
static inline vec3 vec3_new(double x, double y, double z)
{
    vec3 v = { {x,y,z} };
    return v;
}

// acesso aos valores de um struct vec3, uma especie de getter
static inline double vec3_x(const vec3 *v) { return v->e[0]; }
static inline double vec3_y(const vec3 *v) { return v->e[1]; }
static inline double vec3_z(const vec3 *v) { return v->e[2]; }

// funcao debug
static inline void vec3_print(const vec3* a)
{
    double x, y, z;
    x = vec3_x(a);
    y = vec3_y(a);
    z = vec3_z(a);
    printf("x=%.2f, y=%.2f, z=%.2f\n", x, y, z);
}


// funções

static inline double vec3_item(const vec3 *v, int i) 
{
    return v->e[i]; 
}

static inline vec3 vec3_sum(const vec3 *a, const vec3 *b)
{
    //vec3 result = vec3new(a->e[0]+b->e[0], a->e[1]+b->e[1], a->e[2]+b->e[2]);
    vec3 result = vec3_new(
        vec3_x(a)+vec3_x(b),
        vec3_y(a)+vec3_y(b),
        vec3_z(a)+vec3_z(b)
    );
    return result;
}

static inline vec3 vec3_scale(const vec3 *a, double b)
{
    vec3 result = vec3_new(
        vec3_x(a) * b,
        vec3_y(a) * b,
        vec3_z(a) * b
    );
    return result;
}

static inline vec3 vec3_negate(const vec3 *a)
{
     return vec3_scale(a, -1.0);
}

static inline vec3 vec3_div(const vec3 *a, double t)
{
    double inv = 1.0/t;
    vec3 result = vec3_new(
        vec3_x(a) * inv,
        vec3_y(a) * inv,
        vec3_z(a) * inv
    );
    return result;
}

static inline double vec3_length_squared (const vec3 *a)
{
    return vec3_x(a) * vec3_x(a) + vec3_y(a) * vec3_y(a) + vec3_z(a) * vec3_z(a);
}

static inline double vec3_length (const vec3 *a)
{
    return sqrt(vec3_length_squared(a));
}

static inline vec3 vec3_cross(const vec3 *u, const vec3 *v) 
{
    double a,b,c;
    a = vec3_y(u) * vec3_z(v) - vec3_z(u) * vec3_y(v);
    b = vec3_z(u) * vec3_x(v) - vec3_x(u) * vec3_z(v);
    c = vec3_x(u) * vec3_y(v) - vec3_y(u) * vec3_x(v);
    return vec3_new(a,b,c);
}

static inline double vec3_dot(const vec3 *a, const vec3 *b) 
{
    return vec3_x(a) * vec3_x(b) +
           vec3_y(a) * vec3_y(b) +
           vec3_z(a) * vec3_z(b);
}


static inline vec3 vec3_unit_vector(const vec3 *a)
{
    return vec3_div(a, vec3_length(a));
}


#endif