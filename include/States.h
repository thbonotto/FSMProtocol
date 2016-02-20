#pragma once

<<<<<<< HEAD
#include "../include/Event/Event.h"
=======
#include "../include/Events.h"
#include <mutex>
>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
// A class abstrata que representa um estado
class State {
 public:
<<<<<<< HEAD
  virtual State * handle(const Event & e) = 0;
=======
  virtual State * handle(Event & e) = 0;
  /**
    *  It's not gonna work, just to stop Eclipse bothering.
    *  Also, maybe We should use std::call_once on singleton.
    */
>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
};
// as classes concretas que implementam os estados da MEF
class State0 : public State {
 public:
<<<<<<< HEAD
  virtual State * handle(const Event & e);
=======
  virtual State * handle(Event & e);

  static State0 * instance(){
	  return _instance;
  }
private:
  static State0 *  _instance;

>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
};

class State1 : public State {
 public:
<<<<<<< HEAD
  virtual State * handle(const Event & e);
=======
  virtual State * handle(Event & e);
  static State1 * instance(){
	  return _instance;
  }
private:
  static State1 *  _instance;
>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
};

class State2 : public State {
 public:
<<<<<<< HEAD
  virtual State * handle(const Event & e);
=======
  virtual State * handle(Event & e);
  static State2 * instance(){
	  return _instance;
  }
private:
  static State2 *  _instance;
>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
};

class State3 : public State {
 public:
<<<<<<< HEAD
  virtual State * handle(const Event & e);
=======
  virtual State * handle(Event & e);
  static State3 * instance(){
	  return _instance;
  }
private:
  static State3 *  _instance;
>>>>>>> branch 'master' of https://github.com/thbonotto/FSMProtocol
};
