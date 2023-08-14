#include "interpolate.h"

/* Precise method, which guarantees v = v1 when t = 1.
 * See https://en.wikipedia.org/wiki/Linear_interpolation
 */
double gos_interpolate_linear(double y1, double y2, double mu) {
  return y1 * (1.0 - mu) + y2 * mu;
}
