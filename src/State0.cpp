// as classes concretas que implementam os estados da MEF
#include "State0.h"

State0 * State0::single{nullptr};

State0::State0() {

}
State0::State0(const State0 & outro) {

}
State0& State0::operator=(const State0 & outro) {
	this->single = outro.get_instance();
	return *this;
}
State* State0::handle(Event& e) {
	return State1::get_instance();
}
