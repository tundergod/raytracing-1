#ifndef __RAYTRACING_H
#define __RAYTRACING_H

#include "objects.h"
#include <stdint.h>

#define MAXX 64

typedef struct __ARG {
    uint8_t *pixels;
    color background;
    rectangular_node rectangulars;
    sphere_node spheres;
    light_node lights;
    const viewpoint *View;
    int start_j;
    point3 u, v, w, d;
} arg;

//void raytracing(void* args);

void raytracing(uint8_t *pixels, color background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height);


#endif
