#ifndef __RAY_MATH_TOOLKIT_H
#define __RAY_MATH_TOOLKIT_H

#include <math.h>
#include <stdio.h>
#include <assert.h>

#define DOT(a,b) ((a[0]*b[0])+(a[1]*b[1])+(a[2]*b[2]))
#define SUB_VEC(a,b,c) (c[0]=a[0]-b[0], c[1]=a[1]-b[1], c[2]=a[2]-b[2])
#define MVECS(a,b,out) (out[0]=a[0]*b[0], out[1]=a[1]*b[1], out[2]=a[2]*b[2])
#define MVEC(a,b,out) (out[0]=a[0]*(b), out[1]=a[1]*(b), out[2]=a[2]*(b))
#define ADD(a,b,c) (c[0]=a[0]+b[0], c[1]=a[1]+b[1], c[2]=a[2]+b[2])
#define CDOT(a,b,out) (out[0]=(a[1]*b[2])-(a[2]*b[1]),out[1]=(a[2]*b[0])-(a[0]*b[2]),out[2]=(a[0]*b[1])-(a[1]*b[0]))


static inline __forceinline
void normalize(double *v)
{
    double d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    assert(d != 0.0 && "Error calculating normal");

    v[0] /= d;
    v[1] /= d;
    v[2] /= d;
}

static inline __forceinline
double length(const double *v)
{
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

static inline __forceinline
void scalar_triple_product(const double *u, const double *v, const double *w,
                           double *out)
{
    CDOT(v, w, out);
    MVECS(u, out, out);
}

static inline __forceinline
double scalar_triple(const double *u, const double *v, const double *w)
{
    double tmp[3];
    CDOT(w, u, tmp);
    return DOT(v, tmp);
}

#endif
