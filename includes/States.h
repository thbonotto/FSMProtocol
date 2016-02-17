#pragma once
#include "Event/Event.h"
// A class abstrata que representa um estado
class State {
 public:
  virtual State * handle(const Event & e) = 0;
};
// as classes concretas que implementam os estados da MEF
class State0 : public State {
 public:
  virtual State * handle(const Event & e);
};

class State1 : public State {
 public:
  virtual State * handle(const Event & e);
};

class State2 : public State {
 public:
  virtual State * handle(const Event & e);
};

class State3 : public State {
 public:
  virtual State * handle(const Event & e);
};
