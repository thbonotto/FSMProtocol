// as classes concretas que implementam os estados da MEF
#include "State0.h"

State0 : public State {
 public:
  virtual State * handle(Event & e);
};
 
