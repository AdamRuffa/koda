//
// Created by Adam on 2019-02-03.
//

#include "calc.h"

void dx(double*in, int l) {
    for(int i = l - 1; i > 0; i--) {
        in[i] = in[i] - in[i - 1];
    }
}