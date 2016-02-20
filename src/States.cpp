// as classes concretas que implementam os estados da MEF
#include "States.h"

#include <iostream>

#include "Event/Events.h"
#include "Timeout.h"

State0 * State0::_instance{nullptr};
State1 * State1::_instance{nullptr};
State2 * State2::_instance{nullptr};
State3 * State3::_instance{nullptr};

/**
 * Wait for login State
 * Accepted events are LOGIN_REQ, this will leave you to Login Handler State
 */

State * State0::handle(Event & e){
	if(e.getType() == Event::EventType::LOGIN_REQ){
		std::cout << "Handling State 0" << std::endl;
	}
	std::cout << "Returning to State 0" << std::endl;
	return State0::instance();
}

State * State1::handle(Event & e){
	if(e.getType() == Event::EventType::LOGIN_REQ){
		std::cout << "Handling State 1" << std::endl;
	}
	std::cout << "Returning to State 2" << std::endl;
	return State2::instance();
}

State * State2::handle(Event & e){
	if(e.getType() == Event::EventType::LOGIN_REQ){
		std::cout << "Handling State 2" << std::endl;
	}
	std::cout << "Returning to State 3" << std::endl;
	return State3::instance();
}

State * State3::handle(Event & e){
	if(e.getType() == Event::EventType::LOGIN_REQ){
		std::cout << "Handling State 3" << std::endl;
	}
	std::cout << "Returning to State 1" << std::endl;
	return State1::instance();
}
