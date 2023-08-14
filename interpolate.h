#ifndef _TEXAS_INTERPOLATE_H_
#define _TEXAS_INTERPOLATE_H_

/* Linear interpolation is the simplest method of getting values at positions
 * in between the data points. The points are simply joined by straight line
 * segments.
 * For interpolated values between the two points mu ranges between 0 and 1.
 */
double gos_interpolate_linear(double y1, double y2, double mu);

#endif
