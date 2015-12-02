// as classes concretas que implementam os estados da MEF
#include "States.h"
#include <iostream>
State * State0::handle(Event & e){
	std::cout << "Handling State 0" << std::endl;
	return new State1;
}

State * State1::handle(Event & e){
	std::cout << "Handling State 1" << std::endl;
	return new State2;
}

State * State2::handle(Event & e){
	std::cout << "Handling State 2" << std::endl;
	return new State3;
}

State * State3::handle(Event & e){
	std::cout << "Handling State 3" << std::endl;
	return new State0;
}
