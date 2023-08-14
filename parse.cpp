#include <Arduino_JSON.h>
#include "parse.h"

static double parse_double(JSONVar object, const char* key) {
  if (object.hasOwnProperty(key)) {
    return (double)object[key];
  } else {
    return 0.0;
  }
}

static int parse_int(JSONVar object, const char* key) {
  if (object.hasOwnProperty(key)) {
    return (int)object[key];
  } else {
    return 0;
  }
}

void parse_weather_result(Information* information, const String& payload) {
  String s;
  JSONVar weatherObject = JSON.parse(payload);
  JSONVar mainObject = weatherObject["main"];
  information->temperature = parse_double(mainObject, "temp");
  information->pressure = parse_int(mainObject, "pressure");
  information->humidity = parse_int(mainObject, "humidity");
  JSONVar windObject = weatherObject["wind"];
  information->wind_speed = parse_double(windObject, "speed");
  information->visibility = parse_int(weatherObject, "visibility");
  JSONVar cloudsObject = weatherObject["clouds"];
  information->clouds = parse_int(cloudsObject, "all");
  JSONVar rainObject = weatherObject["rain"];
  information->rain_1h = parse_double(rainObject, "1h");
  information->rain_3h = parse_double(rainObject, "3h");
}
