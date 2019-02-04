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
        calloc(16, sizeof(_Complex double))
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

int main(int argc, char**argv) {
    int failed;
    Suite*s=math_tsuite();
    SRunner*sr=srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return !failed ? EXIT_SUCCESS : EXIT_FAILURE;
}