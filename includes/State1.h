#include "State.h"
// as classes concretas que implementam os estados da MEF
class State1 : public State {
 public:
  // a instância de State0 somente pode ser obtida por meio de get_instance
  static State1 * get_instance() {
    if (not single) single = new State0();
    return single;
  }
  State * handle(Event & e);

 private:
  // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
  // fora da classe
  State1();
  State1(const State1 & outro);
  State1& operator=(const State1 & outro);
 
  // ponteiro para a única instância da classe
  static State1 * single;
}; 
