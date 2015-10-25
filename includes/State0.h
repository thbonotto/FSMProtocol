#include "State.h"
// as classes concretas que implementam os estados da MEF
class State0 : public State {
 public:
  // a instância de State0 somente pode ser obtida por meio de get_instance
  static State0 * get_instance() {
    if (not single) single = new State0();
    return single;
  }
 
  virtual State * handle(Event & e);
 private:
  // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
  // fora da classe
  State0() {}
  State0(const State0 & outro) {}
  State0& operator=(const State0 & outro) {return *this;}
 
  // ponteiro para a única instância da classe
  static State0 * single = nullptr;
}; 
