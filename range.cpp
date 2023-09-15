#include "range.h"

#define MINIMUM_TEMPERATURE             263.0  /* °K  = -10°C  =  14°F */
#define MAXIMUM_TEMPERATURE             318.0  /* °K  =  45°C  = 113°F */

#define MINIMUM_TEMPERATURE_WINTER      263.0  /* °K  = -10°C  =  14°F */
#define MAXIMUM_TEMPERATURE_WINTER      303.0  /* °K  =  30°C  =  86°F */

#define MINIMUM_TEMPERATURE_SUMMER      293.0  /* °K  =  20°C  =  68°F */
#define MAXIMUM_TEMPERATURE_SUMMER      318.0  /* °K  =  45°C  = 113°F */

#define MINIMUM_TEMPERATURE_EQUINOXIAL  283.0  /* °K  =  10°C  =  50°F */
#define MAXIMUM_TEMPERATURE_EQUINOXIAL  308.0  /* °K  =  35°C  =  95°F */

#define MINIMUM_PRESSURE               1000.0  /* hPa */
#define MAXIMUM_PRESSURE               1030.0  /* hPa */

#define MINIMUM_HUMIDITY                  0.0  /* % */
#define MAXIMUM_HUMIDITY                100.0  /* % */

#define MINIMUM_WIND_SPEED                0.0  /* m/s */
#define MAXIMUM_WIND_SPEED              100.0  /* m/s */

#define MINIMUM_VISIBILITY                0.0
#define MAXIMUM_VISIBILITY            10000.0

#define MINIMUM_CLOUDS                    0.0  /* % */
#define MAXIMUM_CLOUDS                  100.0  /* % */

#define MINIMUM_RAIN_1H                   0.0  /* mm */
#define MAXIMUM_RAIN_1H                 300.0  /* mm */

#define MINIMUM_RAIN_3H                   0.0  /* mm */
#define MAXIMUM_RAIN_3H                 600.0  /* mm */

gos_scale scale_temperature;
gos_scale scale_temperature_winter;
gos_scale scale_temperature_summer;
gos_scale scale_temperature_equinoxial;
gos_scale scale_pressure;
gos_scale scale_humidity;
gos_scale scale_wind_speed;
gos_scale scale_visibility;
gos_scale scale_clouds;
gos_scale scale_rain_1h;
gos_scale scale_rain_3h;

// Scale 1 general
// Scale 2 for rain
// Scale 3 for clouds
// Scale 4 for visibility
void create_ranges(double scale1, double scale2, double scale3, double scale4) {
  // Temperature uses scale 1
  scale_temperature.domain.from = MINIMUM_TEMPERATURE;
  scale_temperature.domain.to = MAXIMUM_TEMPERATURE;
  scale_temperature.range.from = 0.0;
  scale_temperature.range.to = scale1;
  scale_temperature_winter.domain.from = MINIMUM_TEMPERATURE_WINTER;
  scale_temperature_winter.domain.to = MAXIMUM_TEMPERATURE_WINTER;
  scale_temperature_winter.range.from = 0.0;
  scale_temperature_winter.range.to = scale1;
  scale_temperature_summer.domain.from = MINIMUM_TEMPERATURE_SUMMER;
  scale_temperature_summer.domain.to = MAXIMUM_TEMPERATURE_SUMMER;
  scale_temperature_summer.range.from = 0.0;
  scale_temperature_summer.range.to = scale1;
  scale_temperature_equinoxial.domain.from = MINIMUM_TEMPERATURE_EQUINOXIAL;
  scale_temperature_equinoxial.domain.to = MAXIMUM_TEMPERATURE_EQUINOXIAL;
  scale_temperature_equinoxial.range.from = 0.0;
  scale_temperature_equinoxial.range.to = scale1;

  // Pressure uses scale 1
  scale_pressure.domain.from = MINIMUM_PRESSURE;
  scale_pressure.domain.to = MAXIMUM_PRESSURE;
  scale_pressure.range.from = 0.0;
  scale_pressure.range.to = scale1;

  // Humidity uses scale 1
  scale_humidity.domain.from = MINIMUM_HUMIDITY;
  scale_humidity.domain.to = MAXIMUM_HUMIDITY;
  scale_humidity.range.from = 0.0;
  scale_humidity.range.to = scale1;

  // Wind speed uses scale 1
  scale_wind_speed.domain.from = MINIMUM_WIND_SPEED;
  scale_wind_speed.domain.to = MAXIMUM_WIND_SPEED;
  scale_wind_speed.range.from = 0.0;
  scale_wind_speed.range.to = scale1;

  // Visibility uses scale 4
  scale_visibility.domain.from = MINIMUM_VISIBILITY;
  scale_visibility.domain.to = MAXIMUM_VISIBILITY;
  scale_visibility.range.from = 0.0;
  scale_visibility.range.to = scale4;

  // Clouds uses scale 3
  scale_clouds.domain.from = MINIMUM_CLOUDS;
  scale_clouds.domain.to = MAXIMUM_CLOUDS;
  scale_clouds.range.from = 0.0;
  scale_clouds.range.to = scale3;

  // Rain 1 hour uses scale 2
  scale_rain_1h.domain.from = MINIMUM_RAIN_1H;
  scale_rain_1h.domain.to = MAXIMUM_RAIN_1H;
  scale_rain_1h.range.from = 0.0;
  scale_rain_1h.range.to = scale2;

  // Rain 3 hours uses scale 2
  scale_rain_3h.domain.from = MINIMUM_RAIN_3H;
  scale_rain_3h.domain.to = MAXIMUM_RAIN_3H;
  scale_rain_3h.range.from = 0.0;
  scale_rain_3h.range.to = scale2;
}
