#ifndef _TEXAS_RANGE_H_
#define _TEXAS_RANGE_H_

#include "types.h"

extern gos_scale scale_temperature;
extern gos_scale scale_pressure;
extern gos_scale scale_humidity;
extern gos_scale scale_wind_speed;
extern gos_scale scale_visibility;
extern gos_scale scale_clouds;
extern gos_scale scale_rain_1h;
extern gos_scale scale_rain_3h;

void create_ranges(double scale1, double scale2);

#endif
