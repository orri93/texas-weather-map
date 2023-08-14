#ifndef _TEXAS_SCALE_H_
#define _TEXAS_SCALE_H_

#include "types.h"

double gos_scale_value(gos_scale* scale, double value);
// double gos_scale_reverse(gos_scale* scale, double value);
int gos_scale_value_with_guard(gos_scale* scale, double value);

#endif
