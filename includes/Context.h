#pragma once

// A classe Context é a parte visível da MEF
#include <States.h>
#include "Event.h"

class Context {
 protected:
  State * estado;
 public:
  Context(State * inicio) : estado(inicio) {}
 
  virtual ~Context() {}
 
  void Request(const Event & e) {
    State * novo = estado->handle(e);
 
    if (novo) {
      estado = novo;
    }
  //  else throw exception();
  }
};
