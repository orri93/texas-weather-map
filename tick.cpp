#include "tick.h"

Tick::Tick() :
  interval_(0),
  next_tick_(0) {
}

Tick::Tick(const unsigned long& interval) :
  interval_(interval),
  next_tick_(0) {
}

bool Tick::is(const unsigned long& tick) {
  if(tick < next_tick_) {
    return false;
  } else { 
    next_tick_ = tick + interval_;
    return true;
  }
}

unsigned long Tick::get() {
  return interval_;
}

void Tick::set(const unsigned long& interval) {
  interval_ = interval;
}