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

START_TEST(kpointset_hash_granularity_test) {
    cdouble lset[16];
    cdouble rset[16];

    kpointset left = {
        16,
        1.0,
        lset
    };
    kpointset right = {
        16,
        1.1,
        rset
    };
    for(int i = 0; i < 16; i++) {
        left.set[i] = i + i*I;
        right.set[i] = i + i*I;
    }
    if(debug) printf("%llu %llu\n", khash(&left), khash(&right));
    hashcode l = khash(&left),
             r = khash(&right);
    ck_assert(l != r);
} END_TEST

START_TEST(kpointset_hash_data_difference_test) {
    cdouble lset[16];
    cdouble rset[16];

    kpointset left = {
            16,
            1.0,
            lset
    };
    kpointset right = {
            16,
            1.1,
            rset
    };
    for(int i = 0; i < 16; i++) {
        left.set[i] = i + i*I;
        right.set[i] = i;
    }
    if(debug) printf("%llu %llu\n", khash(&left), khash(&right));
    hashcode l = khash(&left),
            r = khash(&right);
    ck_assert(l != r);
} END_TEST

START_TEST(kpointset_hash_size_test) {
    cdouble lset[32];
    cdouble rset[16];

    kpointset left = {
            16,
            1.0,
            lset
    };
    kpointset right = {
            32,
            1.0,
            rset
    };
    for(int i = 0; i < 16; i++) {
        left.set[i] = i + i*I;
        right.set[i] = i + i*I;
    }
    for(int i = 16; i < 32; i++) {
        right.set[i] = i + i*I;
    }
    if(debug) printf("%llu %llu\n", khash(&left), khash(&right));
    hashcode l = khash(&left),
            r = khash(&right);
    ck_assert(l != r);
} END_TESTF
F
Suite*types_tsuite(void) {
    Suite*s = suite_create("kodatest-types");
    TCase*tc_core = tcase_create("core");
    tcase_add_test(tc_core, kpointset_hash_granularity_test);
    tcase_add_test(tc_core, kpointset_hash_data_difference_test);
    tcase_add_test(tc_core, kpointset_hash_size_test);
    suite_add_tcase(s, tc_core);
    return s;
}
