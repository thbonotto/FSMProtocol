#pragma once

#include "Event/Events.h"
#include <mutex>

// A class abstrata que representa um estado
class State {
 public:

  virtual State * handle(const Event & e) = 0;
  /**
    *  It's not gonna work, just to stop Eclipse bothering.
    *  Also, maybe We should use std::call_once on singleton.
    */
};
// as classes concretas que implementam os estados da MEF
class State0 : public State {
 public:

  State * handle(Event & e);

  static State0 * instance(){
	  return _instance;
  }
private:
  static State0 *  _instance;

};

class State1 : public State {
 public:

  State * handle(Event & e);
  static State1 * instance(){
	  return _instance;
  }
private:
  static State1 *  _instance;
};

class State2 : public State {
 public:
  State * handle(Event & e);

  static State2 * instance(){
	  return _instance;
  }
private:
  static State2 *  _instance;
};

class State3 : public State {
 public:

  State * handle(Event & e);

  static State3 * instance(){
	  return _instance;
  }
private:
  static State3 *  _instance;

};
