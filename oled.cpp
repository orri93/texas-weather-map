#include "oled.h"
#include "constdef.h"

#include <U8x8lib.h>

static U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8;

void tx_oled_init() {
  u8x8.begin();
  u8x8.setPowerSave(0);
}

void tx_oled_show_status(int status) {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clearDisplay();
  switch(status) {
  case STATUS_CONN_WIFI:
    u8x8.drawString(0, 1, "Connecting");
    break;
  case STATUS_CONNECTED:
    u8x8.drawString(0, 1, "Connected");
    break;
  }
}

void tx_oled_show_mode(int mode) {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clearDisplay();
  switch(mode) {
case MODE_TEMPERATURE:
    u8x8.drawString(0, 1, "Temperature");
    break;
  case MODE_PRESSURE:
    u8x8.drawString(0, 1, "Pressure");
    break;
  case MODE_HUMIDITY:
    u8x8.drawString(0, 1, "Humidity");
    break;
  case MODE_WIND_SPEED:
    u8x8.drawString(0, 1, "Wind Speed");
    break;
  case MODE_VISIBILITY:
    u8x8.drawString(0, 1, "Visibility");
    break;
  case MODE_CLOUDS:
    u8x8.drawString(0, 1, "Clouds");
    break;
  case MODE_RAIN_1H:
    u8x8.drawString(0, 1, "Rain 1 hour");
    break;
  case MODE_RAIN_3H:
    u8x8.drawString(0, 1, "Rain 3 hours");
    break;
  }
}
