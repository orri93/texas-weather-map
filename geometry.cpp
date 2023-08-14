#include "types.h"
#include "geometry.h"

double gos_geometry_distance_1d(gos_range_1d* r) {
  return r->to - r->from;
}
