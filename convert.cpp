#include "convert.h"

//
// Temperature
//
// Kelvin to Celsius
double ktoc(double k) {
  return k - 273.15;
}
// Kelvin to Fahrenheit
double ktof(double k) {
  return 1.8 * ktoc(k) + 32.0;
}

//
// Pressure
//
// hPa to atm
double hpatoatm(double hpa) {
  return hpa * 0.0009869233;
}
// hPa to mbar
double hpatombar(double hpa) {
  return hpa;
}

//
// Wind Speed
//
// m/s to Knots
double mpstoknots(double mps) {
  return mps * 1.944;
}

//
// Visibility
//
// Raw Visibility (0 - 10000) to Percent
double rawvisibilitytopercent(double raw) {
  return raw / 100.0;
}
