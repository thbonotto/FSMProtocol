#pragma once
#include "Events.h"
// A class abstrata que representa um estado
class State {
 public:
  virtual State * handle(Event & e) = 0;
};
// as classes concretas que implementam os estados da MEF
class State0 : public State {
 public:
  virtual State * handle(Event & e);
};

class State1 : public State {
 public:
  virtual State * handle(Event & e);
};

class State2 : public State {
 public:
  virtual State * handle(Event & e);
};

class State3 : public State {
 public:
  virtual State * handle(Event & e);
};
