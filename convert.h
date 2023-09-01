#ifndef _TEXAS_CONVERT_H_
#define _TEXAS_CONVERT_H_

// Temperature
double ktoc(double k);          // Kelvin to Celsius
double ktof(double k);          // Kelvin to Fahrenheit

// Pressure
double hpatoatm(double hpa);    // hPa to atm
double hpatombar(double hpa);   // hPa to mbar

// Wind Speed
double mpstoknots(double mps);  // m/s to Knots

// Visibility
double rawvisibilitytopercent(double raw);  // Raw Visibility (0 - 10000) to Percent

#endif /* _TEXAS_CONVERT_H_ */
