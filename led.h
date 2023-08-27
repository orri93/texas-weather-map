#ifndef _TEXAS_LED_H_
#define _TEXAS_LED_H_

#include <Adafruit_TLC5947.h>
#include "types.h"

void tx_led_init(Adafruit_TLC5947* adafruit_TLC5947, gos_rgb_gradient* gradient_1, gos_rgb_gradient* gradient_2);

void tx_led_test();

void tx_set_led(int led_no, Information* information, int mode);
void tx_led_write();

#endif /* _TEXAS_LED_H_ */
