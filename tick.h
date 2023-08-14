#ifndef _FDS_ARDUINO_LIBRARY_TICK_H_
#define _FDS_ARDUINO_LIBRARY_TICK_H_

class Tick {
public:
  Tick();
  Tick(const unsigned long& interval);
  bool is(const unsigned long& tick);
  unsigned long get();
  void set(const unsigned long& interval);
private:
  unsigned long interval_;
  unsigned long next_tick_;
};

#endif /* FDS_MC_TICK_H_ */