//
// Created by Adam on 2019-02-03.
//

#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../koda/math/kmath.h"

/* manually toggle to print exact hashcodes */
const bool debug = true;

void after(kpointset*l, kpointset*r) {
    free(l->set);
    free(r->set);
}

START_TEST(kpointset_hash_granularity_test) {
    kpointset left = {
        16,
        1.0,
        calloc(16, sizeof(cdouble))
    };
    kpointset right = {
        16,
        1.1,
        calloc(16, sizeof(cdouble))
    };
    for(int i = 0; i < 16; i++) {
        left.set[i] = i + i*I;
        right.set[i] = i + i*I;
    }
    if(debug) printf("%llu %llu\n", hash_kpointset(&left), hash_kpointset(&right));
    ck_assert(hash_kpointset(&left) != hash_kpointset(&right));
    after(&left, &right);
} END_TEST

START_TEST(kpointset_hash_size_test) {
    kpointset left = {
            16,
            1.0,
            calloc(16, sizeof(cdouble))
    };
    kpointset right = {
            17,
            1.0,
            calloc(16, sizeof(cdouble))
    };
    for(int i = 0; i < 16; i++) {
        left.set[i] = i + i*I;
        right.set[i] = i + i*I;
    }
    left.set[16] = 99;
    if(debug) printf("%llu %llu\n", hash_kpointset(&left), hash_kpointset(&right));
    ck_assert(hash_kpointset(&left) != hash_kpointset(&right));
    after(&left, &right);
} END_TEST

Suite*types_tsuite(void) {
    Suite*s = suite_create("kodatest-types");
    TCase*tc_core = tcase_create("core");
    tcase_add_test(tc_core, kpointset_hash_granularity_test);
    tcase_add_test(tc_core, kpointset_hash_size_test);
    suite_add_tcase(s, tc_core);
    return s;
}