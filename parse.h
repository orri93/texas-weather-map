#ifndef _TEXAS_PARSE_H_
#define _TEXAS_PARSE_H_

#include <Arduino.h>
#include "types.h"

void parse_weather_result(Information* information, const String& payload);

/* Return the Ordinal day number
   The ordinal number, ranging between 1 and 366 (starting on January 1)
   representing the multiples of a day, called day of the year or ordinal day number */
int parse_world_clock_result(const String& payload);

#endif /* _TEXAS_PARSE_H_ */
