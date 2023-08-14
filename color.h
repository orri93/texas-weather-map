#ifndef _TEXAS_COLOR_H_
#define _TEXAS_COLOR_H_

#include <Arduino.h>

#include "types.h"

#define GOS_COLOR_GAMMA 0.43

#define GOS_COLOR_MAX_RGB_F 255.0
#define GOS_COLOR_ROUND_RGB_F 255.5

/* Convert each color component from 0..255 to 0..1 */
#define GOS_COLOR_NORMALIZE(c) (((double) ( c ) ) / GOS_COLOR_MAX_RGB_F)

/* Convert each color component from 0..255 to 0..1 */
#define GOS_COLOR_DENORMALIZE(c) ((uint8_t)(GOS_COLOR_ROUND_RGB_F * (c)))

void gos_color_assign(gos_color* co, double a, double b, double c);
void gos_color_assign_rgb(gos_rgb* co, uint8_t r, uint8_t g, uint8_t b);
void gos_color_assign_rgb32(gos_rgb* co, uint32_t rgb);

bool gos_color_initialize_rgb_gradient(gos_rgb_gradient* gradient, int size);
void gos_color_free_rgb_gradient(gos_rgb_gradient* gradient);

double gos_color_min_f(double a, double b, double c);
double gos_color_max_f(double a, double b, double c);

bool gos_color_is_black(gos_color* c);

double gos_color_sum(gos_color* c);

double gos_color_brightness(gos_color* c, double gamma);

/* Returns a sRGB value in the range [0,1] for linear input in [0,1]. */
double gos_color_s_rgb_f(double x);

/* Returns a linear value in the range [0,1] for sRGB input in [0,255]. */
double gos_color_s_rgb_i(double x);

void gos_color_s_rgb_fa(gos_color* c, gos_color* i);

void gos_color_s_rgb_ia(gos_color* c, gos_rgb* rgb);

void gos_color_normalize_rgb(gos_color* normalized, gos_rgb* rgb);
void gos_color_denormalize_rgb(gos_rgb* rgb, gos_color* normalized);

void gos_color_interpolate_linear(
  gos_color* co,
  gos_color* c1,
  gos_color* c2,
  double f);

/* Color gradient algorithm
 * https://stackoverflow.com/questions/22607043/color-gradient-algorithm
 * https://github.com/rofrol/color-gradient-algorithm
 */
void gos_color_perceptual_steps(
  gos_rgb* crgbo,
  gos_rgb* crgb1,
  gos_rgb* crgb2,
  double gamma,
  int steps);

bool gos_color_create_rgb_gradient(
  gos_rgb_gradient* gradient,
  gos_rgb* stop,
  int* size,
  int count,
  double gamma);

void gos_color_rgb_to_hsl(
  uint8_t r, uint8_t g, uint8_t b,
  double* h, double* s, double* l);

void gos_color_rgb_to_hsv(
  uint8_t r, uint8_t g, uint8_t b,
  double* h, double* s, double* v);

void gos_color_hsl_to_rgb(
  double h, double s, double l,
  uint8_t* r, uint8_t* g, uint8_t* b);

void gos_color_hsv_to_rgb(
  double h, double s, double v,
  uint8_t* r, uint8_t* g, uint8_t* b);

uint8_t gos_color_hue(double p, double q, double t);

#endif
