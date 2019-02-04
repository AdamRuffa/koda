//
// Created by Adam on 2019-02-03.
//

#ifndef KODA_KODAT_H
#define KODA_KODAT_H

#include <complex.h>
#include <sys/types.h>

typedef u_int64_t hashcode;
typedef _Complex double cdouble;

#define khash(hashable) hash_##__typeof__(hashable)(hashable)
#define kequals(this, that) eq_##__typeof__(this)(hashable)

typedef struct {
   u_int64_t size;
   double granularity;
   cdouble*set;
} kpointset;
hashcode hash_kpointset(kpointset*sp);

#endif //KODA_KODAT_H
