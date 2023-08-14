#ifndef _TEXAS_TYPES_H_
#define _TEXAS_TYPES_H_

#include <stdint.h>

typedef struct gos_range_1d {
  double from;
  double to;
} gos_range_1d;

/* Scale */
typedef struct gos_scale {
  gos_range_1d domain;
  gos_range_1d range;
} gos_scale;

typedef struct gos_color {
  double a;
  double b;
  double c;
} gos_color;

typedef struct gos_rgb {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} gos_rgb;

typedef struct gos_rgb_gradient {
  gos_rgb* gradient;
  int count;
} gos_rgb_gradient;

typedef enum {
  TEMPERATURE,
  PRESSURE,
  HUMIDITY,
  WIND_SPEED,
  VISIBILITY,
  CLOUDS,
  RAIN_1H,
  RAIN_3H
} WeatherItem;

typedef struct Information {
  double temperature;
  int    pressure;
  int    humidity;
  double wind_speed;
  int    visibility;
  int    clouds;
  double rain_1h;
  double rain_3h;
} Information;

#endif /* _TEXAS_TYPES_H_ */
