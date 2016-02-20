/*
 * LoginRequest.h
 *
 *  Created on: Dec 2, 2015
 *      Author: thiago.b
 */

#pragma once 
#include "../../include/Event/Event.h"

class LoginRequest : public Event {
public:
	LoginRequest();
	virtual ~LoginRequest();
};

/* EVENTS_LOGINREQUEST_H_ */
