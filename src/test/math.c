//
// Created by Adam on 2019-02-03.
//

#include <printf.h>
#include <check.h>
#include <stdlib.h>
#include "../koda/math/kmath.h"

START_TEST(dx_test) {
    double c[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    dx(c, 16);
    for(int i = 0; i < 16; i++) {
        ck_assert(c[i] == (!i?0:1));
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