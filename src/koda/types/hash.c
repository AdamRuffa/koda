//
// Created by Adam on 2019-02-03.
//


#include "kodat.h"

const hashcode hashprimes[] = {
    1, 3, 7, 13, 29, 59, 83, 127,
    1<<3, 3<<3, 7<<3, 17<<3, 31<<3, 59<<3, 83<<3, 127<<3,
    1<<7, 3<<7, 7<<7, 17<<7, 31<<7, 59<<7, 83<<7, 127<<7,
    1<<15, 3<<15, 7<<15, 17<<15, 31<<15, 59<<15, 83<<15, 127<<15,
    1<<21, 3<<21, 7<<21, 17<<21, 31<<21, 59<<21, 83<<21, 127<<21,
    1<<27, 3<<27, 7<<27, 17LL<<27, 31LL<<27
};
const int HASHPRIMES = sizeof(hashprimes) / sizeof(hashcode);

inline int log2_u64(u_int64_t l) {
    int log;
    for(log = 0; l != 0; l >>= 1) log++;
    return log;
}

typedef union {
    double d;
    hashcode l;
} ld64;

inline int pr(u_int64_t group) {
    group%=HASHPRIMES;
    int g = 0,
        ham = __builtin_popcount(group) >> 3;
    ham = !ham ? 1 : ham;
    for(int i = 0; i < ham; i++) {
        g ^= hashprimes[group + ((i*27)%HASHPRIMES)];
    }
    return g;
}

inline hashcode hash_cdouble(cdouble c, u_int64_t group) {
    ld64 _lor = {creal(c)};
    ld64 _loc = {creal(c)};
    ld64 _hir = {cimag(c)};
    ld64 _hic = {cimag(c)};
    u_int32_t lor = (u_int32_t)(_lor.l & 0xFFFFFFFFL);
    u_int32_t hir = (u_int32_t)(_hir.l >> 32);
    u_int32_t loc = (u_int32_t)(_loc.l & 0xFFFFFFFFL);
    u_int32_t hic = (u_int32_t)(_hic.l >> 32);
    return ((hashcode)(pr(group) * lor ^ pr(group + 1) * hic) << 32)
        ^   (hashcode)(pr(group + 2) * hir ^ pr(group + 3) * loc);
}


hashcode hash_kpointset(kpointset*sp) {
    hashcode acc = 0L;
    int size = log2_u64(sp->size);
    for(u_int64_t i = 0; i < sp->size; i += size) {
        acc ^= hash_cdouble(sp->set[i], i);
    }
    ld64 g = {sp->granularity};
    return acc ^ g.l ^ (hashcode)sp->size;
}



