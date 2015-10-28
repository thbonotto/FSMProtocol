#include "Events.h"
// A class abstrata que representa um estado

class State {
 public:
  virtual State * handle(Event & e) = 0;
};
