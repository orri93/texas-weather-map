#include "oled.h"
#include "constdef.h"
#include "convert.h"

#include <U8x8lib.h>

#define OLED_X                   0
#define OLDE_Y_FIRST_LINE        0
#define OLDE_Y_SECOND_LINE       2

#define BUFFER_SIZE_MAIN        64
#define BUFFER_SIZE_NUMBER      64

#define NUMBER_WIDTH             8

static U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8;

static char buffer_main[BUFFER_SIZE_MAIN];
static char buffer_number[BUFFER_SIZE_NUMBER];

static void tx_format_double(double value, unsigned int prec, const char* unit) {
  memset(buffer_main, 0, BUFFER_SIZE_MAIN);
  memset(buffer_number, 0, BUFFER_SIZE_NUMBER);
  dtostrf(value, NUMBER_WIDTH, prec, buffer_number);
  sprintf(buffer_main, "%s %s", buffer_number, unit);
}

static void tx_format_int(int value, const char* unit) {
  memset(buffer_main, 0, BUFFER_SIZE_MAIN);
  sprintf(buffer_main, "%d %s", value, unit);
}

void tx_oled_init() {
  u8x8.begin();
  u8x8.setPowerSave(0);
}

void tx_oled_show_status(int status) {
  u8x8.setFont(u8x8_font_8x13B_1x2_r);
  u8x8.clearDisplay();
  switch(status) {
  case STATUS_CONN_WIFI:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Connecting");
    break;
  case STATUS_CONNECTED:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Connected");
    break;
  case STATUS_TESTING:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Testing");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, "0.00 Euc");
    break;
  }
}

void tx_oled_show_mode(int mode, int season) {
  u8x8.setFont(u8x8_font_8x13B_1x2_r);
  u8x8.clearDisplay();
  switch(mode) {
  case MODE_TEMPERATURE:
    switch(season) {
    case SEASON_UNKNOWN:
      u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Temperature");
      break;
    case SEASON_WINTER:
      u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Temperature Win.");
      break;
    case SEASON_SPRING:
      u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Temperature Spr.");
      break;
    case SEASON_SUMMER:
      u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Temperature Sum.");
      break;
    case SEASON_AUTMN:
      u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Temperature Aut.");
      break;
    }
    break;
  case MODE_PRESSURE:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Pressure");
    break;
  case MODE_HUMIDITY:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Humidity");
    break;
  case MODE_WIND_SPEED:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Wind Speed");
    break;
  case MODE_VISIBILITY:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Visibility");
    break;
  case MODE_CLOUDS:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Clouds");
    break;
  case MODE_RAIN_1H:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Rain 1 hour");
    break;
  case MODE_RAIN_3H:
    u8x8.drawString(OLED_X, OLDE_Y_FIRST_LINE, "Rain 3 hours");
    break;
  }
}

void tx_oled_show_information(Information* information, int mode) {
  double value;
  switch(mode) {
  case MODE_TEMPERATURE:
    value = ktof(information->temperature);
    tx_format_double(value, 1, "°F");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_PRESSURE:
    tx_format_int(information->pressure, "hPa");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_HUMIDITY:
    tx_format_int(information->humidity, "%");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_WIND_SPEED:
    tx_format_double(information->wind_speed, 1, "m/s");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_VISIBILITY:
    value = rawvisibilitytopercent(information->visibility);
    tx_format_double(value, 1, "%");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_CLOUDS:
    tx_format_int(information->clouds, "%");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_RAIN_1H:
    tx_format_double(information->rain_1h, 1, "mm");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  case MODE_RAIN_3H:
    tx_format_double(information->rain_3h, 1, "mm");
    u8x8.drawString(OLED_X, OLDE_Y_SECOND_LINE, buffer_main);
    break;
  }
}
