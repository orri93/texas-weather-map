#include "season.h"
#include "constdef.h"

// Equal divide the year into 4
//#define SEASON_END_OF_WINTER  46
//#define SEASON_END_OF_SPRING 138
//#define SEASON_END_OF_SUMMER 230
//#define SEASON_END_OF_AUTMN  321

#define SEASON_END_OF_WINTER  32  /* Winter ends in the end of january   */
#define SEASON_END_OF_SPRING 122  /* Spring ends in the end of April     */
#define SEASON_END_OF_SUMMER 275  /* Summer ends in the end of September */
#define SEASON_END_OF_AUTMN  335  /* Autmn  ends in the end of November  */ 


#define SEASON_END_OF_YEAR   366

int tx_season_from_ordinal_day(int ordinal_day) {
  if (ordinal_day <= 0) {
    return SEASON_UNKNOWN;
  } else if (ordinal_day <= SEASON_END_OF_WINTER) {
    return SEASON_WINTER;
  } else if (ordinal_day <= SEASON_END_OF_SPRING) {
    return SEASON_SPRING;
  } else if (ordinal_day <= SEASON_END_OF_SUMMER) {
    return SEASON_SUMMER;
  } else if (ordinal_day <= SEASON_END_OF_AUTMN) {
    return SEASON_AUTMN;
  } else if (ordinal_day <= SEASON_END_OF_YEAR) {
    return SEASON_WINTER;
  } else {
    return SEASON_UNKNOWN;
  }
}
