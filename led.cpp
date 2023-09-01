#include "led.h"
#include "color.h"
#include "gradient.h"
#include "constdef.h"
#include "range.h"
#include "scale.h"
#include "types.h"

static Adafruit_TLC5947* tlc5947;
static gos_rgb_gradient* g1;  // General
static gos_rgb_gradient* g2;  // For rain
static gos_rgb_gradient* g3;  // For clouds
static gos_rgb_gradient* g4;  // For visibility

static int i, j, c;

static void tx_set_a_led(uint16_t lednum, gos_rgb* rgb) {
  tlc5947->setLED(lednum, rgb->r, rgb->g, rgb->b);
}

static void tx_clear_all_leds() {
  for (i = 0; i < LOCATION_COUNT; i++) {
    tlc5947->setLED(i, 0, 0, 0);
  }
}

void tx_led_init(
  Adafruit_TLC5947* adafruit_TLC5947,
  gos_rgb_gradient* gradient_1, // General
  gos_rgb_gradient* gradient_2, // For rain
  gos_rgb_gradient* gradient_3, // For clouds
  gos_rgb_gradient* gradient_4  // For visibility
) {
  tlc5947 = adafruit_TLC5947;
  tlc5947->begin();
  tlc5947->write();
  g1 = gradient_1;
  g2 = gradient_2;
  g3 = gradient_3;
  g4 = gradient_4;
}

void tx_led_test() {
  // Test LEDs
  for (i = 0; i < LOCATION_COUNT; i++) {
    tlc5947->setLED(i, 255, 0, 0);
    tlc5947->write();
    delay(300);
    tlc5947->setLED(i, 0, 255, 0);
    tlc5947->write();
    delay(300);
    tlc5947->setLED(i, 0, 0, 255);
    tlc5947->write();
    delay(300);
    tlc5947->setLED(i, 0, 0, 0);
  }

  // Test gradient 1
  for (i = 0; i < g1->count; i++) {
    for (j = 0; j < LOCATION_COUNT; j++) {
      tx_set_a_led(j, g1->gradient + i);
    }
    tlc5947->write();
    delay(20);
  }
  tx_clear_all_leds();
  tlc5947->write();
  delay(300);

  // Test gradient 2
  for (i = 0; i < g2->count; i++) {
    for (j = 0; j < LOCATION_COUNT; j++) {
      tx_set_a_led(j, g2->gradient + i);
    }
    tlc5947->write();
    delay(20);
  }
  tx_clear_all_leds();
  tlc5947->write();
  delay(300);

  // Test gradient 3
  for (i = 0; i < g3->count; i++) {
    for (j = 0; j < LOCATION_COUNT; j++) {
      tx_set_a_led(j, g3->gradient + i);
    }
    tlc5947->write();
    delay(20);
  }
  tx_clear_all_leds();
  tlc5947->write();
  delay(300);

  // Test gradient 4
  for (i = 0; i < g4->count; i++) {
    for (j = 0; j < LOCATION_COUNT; j++) {
      tx_set_a_led(j, g4->gradient + i);
    }
    tlc5947->write();
    delay(20);
  }
  tx_clear_all_leds();
  tlc5947->write();
  delay(300);

  // Clear all LEDS
  tx_clear_all_leds();
  tlc5947->write();
}

void tx_set_led(int led_no, Information* information, int mode) {
  switch(mode) {
  case MODE_TEMPERATURE:
    // Temperature uses general gradient 1
    c = gos_scale_value_with_guard(&scale_temperature, information->temperature);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_PRESSURE:
    // Pressure uses general gradient 1
    c = gos_scale_value_with_guard(&scale_pressure, (double)information->pressure);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_HUMIDITY:
    // Humidity uses general gradient 1
    c = gos_scale_value_with_guard(&scale_humidity, (double)information->humidity);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_WIND_SPEED:
    // Wind Speed uses general gradient 1
    c = gos_scale_value_with_guard(&scale_wind_speed, information->wind_speed);
    tx_set_a_led(led_no, g1->gradient + c);
    break;
  case MODE_VISIBILITY:
    // Visibility uses gradient 4
    c = gos_scale_value_with_guard(&scale_visibility, (double)information->visibility);
    tx_set_a_led(led_no, g4->gradient + c);
    break;
  case MODE_CLOUDS:
    // Clouds uses gradient 3
    c = gos_scale_value_with_guard(&scale_clouds, (double)information->clouds);
    tx_set_a_led(led_no, g3->gradient + c);
    break;
  case MODE_RAIN_1H:
    // Rain 1 hour uses gradient 2
    c = gos_scale_value_with_guard(&scale_rain_1h, information->rain_1h);
    tx_set_a_led(led_no, g2->gradient + c);
    break;
  case MODE_RAIN_3H:
    // Rain 3 hours uses gradient 2
    c = gos_scale_value_with_guard(&scale_rain_3h, information->rain_3h);
    tx_set_a_led(led_no, g2->gradient + c);
    break;
  }
}

void tx_led_write() {
  tlc5947->write();
}
