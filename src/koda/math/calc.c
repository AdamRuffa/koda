//
// Created by Adam on 2019-02-03.
//

#include "kmath.h"

const double ORIGINAL_GRANULARITY = 0.;

void dx(kpointset*ps, double granularity) {
    if(granularity==ORIGINAL_GRANULARITY) {
        for(long long i = ps->size - 1; i > 0; i--) {
            ps->set[i] = ps->set[i] - ps->set[i - 1];
        }
    }
}

