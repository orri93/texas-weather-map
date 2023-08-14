#ifndef _TEXAS_PARSE_H_
#define _TEXAS_PARSE_H_

#include <Arduino.h>
#include "types.h"

void parse_weather_result(Information* information, const String& payload);

#endif /* _TEXAS_PARSE_H_ */
