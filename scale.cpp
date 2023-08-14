#include "scale.h"
#include "geometry.h"

double gos_scale_value(gos_scale* scale, double value) {
  double dd = gos_geometry_distance_1d(&scale->domain);
  double rd = gos_geometry_distance_1d(&scale->range);
  double r = (value - scale->domain.from) / dd;
  return scale->range.from + r * rd;
}

/*
double gos_scale_reverse(gos_scale* scale, double value) {
  double dd = gos_geometry_distance_1d(&scale->domain);
  double rd = gos_geometry_distance_1d(&scale->range);
  double r = (value - scale->range.from) / rd;
  return scale->domain.from + r * dd;
}
*/

int gos_scale_value_with_guard(gos_scale* scale, double value) {
  double s = gos_scale_value(scale, value);
  if (s < scale->range.from) {
    s = scale->range.from;
  } else if (s > scale->range.to) {
    s = scale->range.to;
  }
  return (int)s;
}
