#include <WiFi.h>

#include <SPI.h>

#include <HTTPClient.h>

#include <Adafruit_TLC5947.h>

#include <gatltick.h>

#include "types.h"
#include "constdef.h"
#include "gradient.h"
#include "queries.h"
#include "secrets.h"
#include "range.h"
#include "parse.h"
#include "oled.h"
#include "led.h"

#define INTERVAL                  4000

#define TLC5947_COUNT                2
#define TLC5947_CLK_PIN             D3
#define TLC5947_DAT_PIN             D2
#define TLC5947_LAT_PIN             D4

#define MODE_BUTTON_PIN             D5
#define MODE_BUTTON_DEBOUNCE_TIME  300

#define SERIAL_BAUD_RATE          9600

Adafruit_TLC5947 adafruit_ltc5947(TLC5947_COUNT, TLC5947_CLK_PIN, TLC5947_DAT_PIN, TLC5947_LAT_PIN);

::gos::atl::Tick<> tick(INTERVAL);

const char* urlpath;
String payload;

unsigned long current, mode_button_debounce_timer;
int i, location, progress;
int result;

int mode;

Information information[LOCATION_COUNT];

gos_rgb_gradient gradient_1;  // General
gos_rgb_gradient gradient_2;  // For rain
gos_rgb_gradient gradient_3;  // For clouds
gos_rgb_gradient gradient_4;  // For visibility

static void update_all_leds() {
  for (i = 0; i <= progress; i++) {
    tx_set_led(i, &(information[i]), mode);
  }
  tx_led_write();
}

void setup() {
  pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
 
  current = 0;
  location = 0;
  progress = -1;
  mode = MODE_FIRST;
  mode_button_debounce_timer = 0;
  
  tx_create_gradient_1(&gradient_1);
  tx_create_gradient_2(&gradient_2);
  tx_create_gradient_3(&gradient_3);
  tx_create_gradient_4(&gradient_4);
  create_ranges(gradient_1.count - 1, gradient_2.count - 1, gradient_3.count - 1, gradient_4.count - 1);
  tx_led_init(&adafruit_ltc5947, &gradient_1, &gradient_2, &gradient_3, &gradient_4);
  
  for (i = 0; i < LOCATION_COUNT; i++) {
    information[i].temperature = 0.0;
    information[i].pressure = 0;
    information[i].humidity = 0;
    information[i].wind_speed = 0.0;
    information[i].visibility = 0;
    information[i].clouds = 0;
    information[i].rain_1h = 0.0;
    information[i].rain_3h = 0.0;
  }
  tx_oled_init();
  tx_oled_show_status(STATUS_TESTING);
  tx_led_test();

#ifdef SERIAL_BAUD_RATE
  Serial.begin(SERIAL_BAUD_RATE);
#endif
  tx_oled_show_status(STATUS_CONN_WIFI);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef SERIAL_BAUD_RATE
    Serial.print(".");
#endif
  }
#ifdef SERIAL_BAUD_RATE
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
#endif
  // tx_oled_show_status(STATUS_CONNECTED);
  tx_oled_show_mode(mode);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    current = millis();

    if (digitalRead(MODE_BUTTON_PIN) == LOW && current > mode_button_debounce_timer) {
      if (mode < MODE_LAST) {
        mode++;
      } else {
        mode = MODE_FIRST;
      }
      tx_oled_show_mode(mode);
      if (progress >= 0) {
        tx_oled_show_information(&(information[0]), mode);
      }
      update_all_leds();
#ifdef SERIAL_BAUD_RATE
      Serial.print("New Mode: ");
      Serial.println(mode);
#endif
      mode_button_debounce_timer = current + MODE_BUTTON_DEBOUNCE_TIME;
    }

    if (tick.is(current)) {
      // TODO fetch open weather map information
      HTTPClient http;
      urlpath = create_query(location);
      if (urlpath) {
#ifdef SERIAL_BAUD_RATE
        Serial.print(location);
        Serial.println(urlpath);
#endif
        http.begin(urlpath);
        result = http.GET();

        if (result > 0) {
          if (result == HTTP_CODE_OK) {
            payload = http.getString();
            parse_weather_result(&(information[location]), payload);

            tx_set_led(location, &(information[location]), mode);
            tx_led_write();
          }
        }
      }

      if (location > progress) {
        progress = location;
      }

      // Houston information
      if (location == 0) {
        tx_oled_show_information(&(information[0]), mode);
      }

      location++;
      if (location >= LOCATION_COUNT) {
        location = 0;
      }
    }
  }
}