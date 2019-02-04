//
// Created by Adam on 2019-02-03.
//

#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "../koda/math/kmath.h"

START_TEST(hash_test) {

} END_TEST

Suite*types_tsuite(void) {
    Suite*s = suite_create("kodatest-types");
    TCase*tc_core = tcase_create("core");
    tcase_add_test(tc_core, hash_test);
    suite_add_tcase(s, tc_core);
    return s;
}