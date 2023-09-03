#ifndef _TEXAS_OLED_H_
#define _TEXAS_OLED_H_

#include "types.h"

void tx_oled_init();

void tx_oled_show_status(int status);

void tx_oled_show_mode(int mode, int season);

void tx_oled_show_information(Information* information, int mode);

#endif /* _TEXAS_OLED_H_ */
