//
// Created by Adam on 2019-02-03.
//

#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "../koda/math/kmath.h"

START_TEST(dx_test) {
    kpointset c = {
        16,
        1.0,
        calloc(16, sizeof(cdouble))
    };
    for(int i = 0; i < 16; i++) {
        c.set[i] = i + i*I;
    }
    dx(&c, ORIGINAL_GRANULARITY);
    for(int i = 0; i < 16; i++) {
        ck_assert(c.set[i] == (!i?0:(1+I)));
    }
} END_TEST

Suite*math_tsuite(void) {
    Suite*s = suite_create("kodatest-math");
    TCase*tc_core = tcase_create("core");
    tcase_add_test(tc_core, dx_test);
    suite_add_tcase(s, tc_core);
    return s;
}

