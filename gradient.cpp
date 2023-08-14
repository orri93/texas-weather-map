#include "gradient.h"
#include "color.h"

#define TX_COLOR_STOP_COUNT_1 6
#define TX_COLOR_SIZE_1 64

#define TX_COLOR_STOP_COUNT_2 3
#define TX_COLOR_SIZE_2 64

bool tx_create_gradient_1(gos_rgb_gradient* gradient) {
  int i;
  int* gsizeat;
  int gradientsize[TX_COLOR_STOP_COUNT_1 - 1];
  gos_rgb stops[TX_COLOR_STOP_COUNT_1];
  gos_rgb* rgbat = stops;

  gos_color_assign_rgb32(rgbat++, 0x07049b);  /* Dark blue */
  gos_color_assign_rgb32(rgbat++, 0x02f7f3);  /* Cyan */
  gos_color_assign_rgb32(rgbat++, 0x09f725);  /* Green */
  gos_color_assign_rgb32(rgbat++, 0xf4ec04);  /* Yellow */
  gos_color_assign_rgb32(rgbat++, 0xf79d01);  /* Orange */
  gos_color_assign_rgb32(rgbat++, 0x8c0101);  /* Dark red */

  /* Equal sized gradient */
  gsizeat = gradientsize;
  for (i = 0; i < TX_COLOR_STOP_COUNT_1 - 1; i++) {
    *(gsizeat++) = TX_COLOR_SIZE_1;
  }

  return gos_color_create_rgb_gradient(
    gradient,
    stops,
    gradientsize,
    TX_COLOR_STOP_COUNT_1,
    GOS_COLOR_GAMMA);
}

bool tx_create_gradient_2(gos_rgb_gradient* gradient) {
  int i;
  int* gsizeat;
  int gradientsize[TX_COLOR_STOP_COUNT_2 - 1];
  gos_rgb stops[TX_COLOR_STOP_COUNT_2];
  gos_rgb* rgbat = stops;

  gos_color_assign_rgb32(rgbat++, 0xf4ec04);  /* Yellow */
  gos_color_assign_rgb32(rgbat++, 0x09f725);  /* Green */
  gos_color_assign_rgb32(rgbat++, 0x02f7f3);  /* Cyan */

  /* Equal sized gradient */
  gsizeat = gradientsize;
  for (i = 0; i < TX_COLOR_STOP_COUNT_2 - 1; i++) {
    *(gsizeat++) = TX_COLOR_SIZE_2;
  }

  return gos_color_create_rgb_gradient(
    gradient,
    stops,
    gradientsize,
    TX_COLOR_STOP_COUNT_2,
    GOS_COLOR_GAMMA);
}
