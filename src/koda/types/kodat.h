//
// Created by Adam on 2019-02-03.
//

#ifndef KODA_KODAT_H
#define KODA_KODAT_H

#include <complex.h>
#include <sys/types.h>

typedef u_quad_t hashcode;
typedef _Complex double cdouble;

typedef struct {
   long long size;
   double granularity;
   cdouble*set;
} kpointset;
inline hashcode hash_kpointset(kpointset*sp);

#endif //KODA_KODAT_H
