//
// Created by Adam on 2019-02-03.
//

#ifndef UNTITLED_KODAMATH_H
#define UNTITLED_KODAMATH_H

#include "../types/kodat.h"

const double ORIGINAL_GRANULARITY;

/**
 * Perform software buffer-derivative of complex double pointset
 * @param ps pointset
 * @param granularity the chosen granularity of output pointset;
 *        if ORIGINAL_GRANULARITY, then preserves granularity as
 *        best possible.
 */
void dx(kpointset*ps, double granularity);

#endif //UNTITLED_KODAMATH_H
