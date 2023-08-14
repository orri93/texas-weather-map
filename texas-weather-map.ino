#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_TLC5947.h>

#include "tick.h"
#include "types.h"
#include "queries.h"
#include "secrets.h"
#include "parse.h"
#include "scale.h"
#include "color.h"
#include "gradient.h"
#include "range.h"

#define INTERVAL         4000

#define LOCATION_COUNT     16

#define TLC5947_COUNT       2
#define TLC5947_CLK_PIN     D3
#define TLC5947_DAT_PIN     D2
#define TLC5947_LAT_PIN     D4

#define SERIAL_BAUD_RATE 9600

Adafruit_TLC5947 adafruit_ltc5947(TLC5947_COUNT, TLC5947_CLK_PIN, TLC5947_DAT_PIN, TLC5947_LAT_PIN);

Tick tick(INTERVAL);

const char* urlpath;
String payload;

unsigned long current;
int i, c, location;
int result;

WeatherItem mode;

Information information[LOCATION_COUNT];

gos_rgb_gradient gradient_1;
gos_rgb_gradient gradient_2;

static void setLed(uint16_t lednum, gos_rgb* rgb) {
  adafruit_ltc5947.setLED(lednum, rgb->r, rgb->g, rgb->b);
}

void setup() {
  location = 0;
  mode = TEMPERATURE;
  tx_create_gradient_1(&gradient_1);
  tx_create_gradient_2(&gradient_2);
  create_ranges(gradient_1.count - 1, gradient_2.count - 1);
  adafruit_ltc5947.begin();
  adafruit_ltc5947.write();
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
#ifdef SERIAL_BAUD_RATE
  Serial.begin(SERIAL_BAUD_RATE);
#endif
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
  for (i = 0; i < gradient_1.count; i++) {
    setLed(0, gradient_1.gradient + i);
    adafruit_ltc5947.write();
    delay(20);
  }
  for (i = 0; i < gradient_2.count; i++) {
    setLed(8, gradient_2.gradient + i);
    adafruit_ltc5947.write();
    delay(20);
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    current = millis();

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

            c = gos_scale_value_with_guard(&scale_temperature, information[location].temperature);
            // c = gos_scale_value_with_guard(&scale_pressure, information[location].rain_1h);
            setLed(location, gradient_1.gradient + c);
            adafruit_ltc5947.write();
          }
        }
      }

      location++;
      if (location >= LOCATION_COUNT) {
        location = 0;
      }
    }
  }
}
