#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct
{
    point3 origin;
    vec3 direction;
} ray;

static inline ray ray_new(const point3 *origin, const vec3 *direction) // construtor
{
    ray r;
    r.origin = *origin;
    r.direction = *direction;
    return r;
}

// getters
static inline point3 ray_origin(const ray *r)
{
    return r->origin;
}
static inline vec3 ray_direction(const ray *r)
{
    return r->direction;
}


static inline point3 ray_at(const ray *r, double t)
{
    vec3 scaled_dir = vec3_scale(&(r->direction), t);
    point3 result = vec3_sum(&(r->origin), &scaled_dir);
    return result;
}



#endif