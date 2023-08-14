#include <Arduino.h>

#include "queries.h"
#include "secrets.h"

#define QUERY_PREFIX  "http://api.openweathermap.org/data/2.5/weather?"
#define QUERY_POSTFIX "&appid="

#define QUERY_HO "lat=29.7589382&lon=-95.3676974"  /* Houston */
#define QUERY_GA "lat=29.299328&lon=-94.7945882"   /* Galveston */
#define QUERY_BE "lat=30.0860459&lon=-94.1018461"  /* Beaumont */
#define QUERY_CC "lat=27.7635302&lon=-97.4033191"  /* Corpus Christi */
#define QUERY_SA "lat=29.4246002&lon=-98.4951405"  /* San Antonio */
#define QUERY_AU "lat=30.2711286&lon=-97.7436995"  /* Austin */
#define QUERY_FW "lat=32.753177&lon=-97.3327459"   /* Fort Worth */
#define QUERY_DA "lat=32.7762719&lon=-96.7968559"  /* Dallas */
#define QUERY_EP "lat=31.7865623&lon=-106.441207"  /* El Paso */
#define QUERY_AM "lat=35.2072185&lon=-101.833824"  /* Amarillo */
#define QUERY_LU "lat=33.5635206&lon=-101.879336"  /* Lubbock */
#define QUERY_AN "lat=31.4649685&lon=-100.4405094" /* San Angelo */
#define QUERY_MI "lat=31.9973662&lon=-102.077948"  /* Midland */
#define QUERY_HA "lat=26.1907543&lon=-97.6960599"  /* Harlingen */
#define QUERY_LA "lat=27.5236998&lon=-99.497352"   /* Laredo */
#define QUERY_CR "lat=28.6834097&lon=-99.8274585"  /* Crystal City */

const char* create_query(int location) {
  switch(location) {
    case 0x0: return QUERY_PREFIX QUERY_HO QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x1: return QUERY_PREFIX QUERY_GA QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x2: return QUERY_PREFIX QUERY_BE QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x3: return QUERY_PREFIX QUERY_CC QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x4: return QUERY_PREFIX QUERY_SA QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x5: return QUERY_PREFIX QUERY_AU QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x6: return QUERY_PREFIX QUERY_FW QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x7: return QUERY_PREFIX QUERY_DA QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x8: return QUERY_PREFIX QUERY_EP QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0x9: return QUERY_PREFIX QUERY_AM QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xa: return QUERY_PREFIX QUERY_LU QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xb: return QUERY_PREFIX QUERY_AN QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xc: return QUERY_PREFIX QUERY_MI QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xd: return QUERY_PREFIX QUERY_HA QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xe: return QUERY_PREFIX QUERY_LA QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    case 0xf: return QUERY_PREFIX QUERY_CR QUERY_POSTFIX OPEN_WEATHER_MAP_API_KEY;
    default: return NULL;
  }
}
