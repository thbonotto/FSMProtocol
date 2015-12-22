#pragma once

class Event {
public:
	enum EventType{
		LOGIN_REQ, LOGIN_RESP, LOGOUT_REQ, LOGOUT_RESP,
		JOIN_REQ, JOIN_RESP,
		LEAVE_REQ, LEAVE_RESP,
		LIST_REQ, LIST_RESP,
		SETMODE_REQ, SETMODE_RESP,
		DATA, ACK,
		SUBSCRIBE, UNSUBSCRIBE,
		NOTIFY
	};
	Event();
	const EventType& getType(){
		return this->eventId;
	}
protected:
	EventType eventId;
};

class LOGINREQ: public Event {
public:
	LOGINREQ(){
		this->eventId = Event::EventType::LOGIN_REQ;
	}

};
