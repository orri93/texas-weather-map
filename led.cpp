#include "led.h"
#include "color.h"
#include "gradient.h"
#include "constdef.h"
#include "range.h"
#include "scale.h"
#include "types.h"

static Adafruit_TLC5947* tlc5947;
static gos_rgb_gradient* g1;
static gos_rgb_gradient* g2;

static int i, c;

static void tx_set_a_led(uint16_t lednum, gos_rgb* rgb) {
  tlc5947->setLED(lednum, rgb->r, rgb->g, rgb->b);
}

void tx_led_init(Adafruit_TLC5947* adafruit_TLC5947, gos_rgb_gradient* gradient_1, gos_rgb_gradient* gradient_2) {
  tlc5947 = adafruit_TLC5947;
  tlc5947->begin();
  tlc5947->write();
  g1 = gradient_1;
  g2 = gradient_2;
}

void tx_led_test() {
  // Test gradient (can be removed later)
  for (i = 0; i < g1->count; i++) {
    tx_set_a_led(0, g1->gradient + i);
    tlc5947->write();
    delay(20);
  }
  for (i = 0; i < g2->count; i++) {
    tx_set_a_led(8, g2->gradient + i);
    tlc5947->write();
    delay(20);
  }
}

void tx_set_led(int led_no, Information* information, int mode) {
  switch(mode) {
  case MODE_TEMPERATURE:
    c = gos_scale_value_with_guard(&scale_temperature, information->temperature);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_PRESSURE:
    c = gos_scale_value_with_guard(&scale_pressure, (double)information->pressure);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_HUMIDITY:
    c = gos_scale_value_with_guard(&scale_humidity, (double)information->humidity);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_WIND_SPEED:
    c = gos_scale_value_with_guard(&scale_wind_speed, information->wind_speed);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_VISIBILITY:
    c = gos_scale_value_with_guard(&scale_visibility, (double)information->visibility);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_CLOUDS:
    c = gos_scale_value_with_guard(&scale_clouds, (double)information->clouds);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_RAIN_1H:
    c = gos_scale_value_with_guard(&scale_rain_1h, information->rain_1h);
    tx_set_a_led(led_no, g2->gradient + c);
    break;
  case MODE_RAIN_3H:
    c = gos_scale_value_with_guard(&scale_rain_3h, information->rain_3h);
    tx_set_a_led(led_no, g2->gradient + c);
    break;
  }
}

void tx_led_write() {
  tlc5947->write();
}
