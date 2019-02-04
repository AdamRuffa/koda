//
// Created by Adam on 2019-02-03.
//

#include <stdlib.h>
#include <check.h>
#include <printf.h>
#include "math.h"
#include "types.h"

typedef struct {
    Suite *(*suiteptr)(void);
    char *name;
}suiteptr;
/* array of pointers to all koda test suite constructor methods */
suiteptr suites[] = {
    {&math_tsuite, "Core Math Functions"},
    {&types_tsuite, "Core Type Definitions and Functions"}
};
const int NUM_TESTS = sizeof(suites) / sizeof(suiteptr);

int main(int argc, char**argv) {
    int failed;
    for(int i = 0; i < NUM_TESTS; i++) {
        printf("Commencing \'%s\' Unit Tests\n", suites[i].name);
        Suite*s = suites[i].suiteptr();
        SRunner*sr=srunner_create(s);
        srunner_run_all(sr, CK_NORMAL);
        failed = srunner_ntests_failed(sr);
        srunner_free(sr);
        if(failed) return EXIT_FAILURE;
    }
    printf("All tests for Koda passed");
    return EXIT_SUCCESS;
}