//
// Created by Adam on 2019-02-03.
//

#ifndef KODA_KODAT_H
#define KODA_KODAT_H

#include <complex.h>

typedef struct {
   long long size;
   double granularity;
   _Complex double*set;
} kpointset;

#endif //KODA_KODAT_H
