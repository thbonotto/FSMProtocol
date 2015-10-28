// as classes concretas que implementam os estados da MEF
#include "State1.h"

State1 * State1::single{nullptr};

State1::State1() {

}
State1::State1(const State0 & outro) {

}
State1& State1::operator=(const State1 & outro) {
	this->single = outro.get_instance();
	return *this;
}
State* State1::handle(Event& e) {
	return State1::get_instance();
}
