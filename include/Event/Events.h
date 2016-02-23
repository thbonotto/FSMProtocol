#pragma once

#include <string>
#include <vector>
//TODO Do this in one place only:
typedef std::pair<std::string, std::string> Par;

class Event {
public:

	enum EventType {
		LOGIN_REQ,
		LOGIN_RESP,
		LOGOUT_REQ,
		LOGOUT_RESP,
		JOIN_REQ,
		JOIN_RESP,
		LEAVE_REQ,
		LEAVE_RESP,
		LIST_REQ,
		LIST_RESP,
		SETMODE_REQ,
		SETMODE_RESP,
		DATA,
		ACK,
		SUBSCRIBE,
		UNSUBSCRIBE,
		NOTIFY
	};
	const EventType& getType() {
		return this->eventId;
	}
protected:
	EventType eventId;
};

class LoginReq: public Event {

public:
	LoginReq(std::string& username, std::string& password) :
			mUsername { username }, mPassword { password } {
		this->eventId = Event::EventType::LOGIN_REQ;
	}
	const std::string getUsername() const {
		return this->mUsername;
	}
	const std::string getpassword() const {
		return this->mPassword;
	}

private:
	std::string mUsername;
	std::string mPassword;

};

class LoginResp: public Event {
public:
	LoginResp() {
		this->eventId = Event::EventType::LOGIN_RESP;
	}

};

class LogoutReq: public Event {
public:
	LogoutReq(std::string& username) :
			mUsername { username } {
		this->eventId = Event::EventType::LOGOUT_REQ;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

private:
	std::string mUsername;

};

class LogoutResp: public Event {
public:
	LogoutResp() {
		this->eventId = Event::EventType::LOGOUT_RESP;
	}

};

class JoinReq: public Event {
public:
	JoinReq(std::string& username, std::string& match, std::string& extra) :
			mUsername { username }, mMatch { match }, mExtra { extra } {
		this->eventId = Event::EventType::JOIN_REQ;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

	const std::string getMatch() const {
		return this->mMatch;
	}

	const std::string getExtra() const {
		return this->mExtra;
	}

private:
	std::string mUsername;
	std::string mMatch;
	std::string mExtra;
};

class JoinResp: public Event {
public:
	JoinResp() {
		this->eventId = Event::EventType::JOIN_RESP;
	}

};

class LeaveReq: public Event {
public:
	LeaveReq(std::string& username) :
			mUsername { username } {
		this->eventId = Event::EventType::LEAVE_REQ;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

private:
	std::string mUsername;

};

class LeaveResp: public Event {
public:
	LeaveResp() {
		this->eventId = Event::EventType::LEAVE_RESP;
	}

};

class ListReq: public Event {
public:
	ListReq() {
		this->eventId = Event::EventType::LIST_REQ;
	}

};

class ListResp: public Event {
public:
	ListResp() {
		this->eventId = Event::EventType::LIST_RESP;
	}

};

class SetModeReq: public Event {
public:
	SetModeReq() {
		this->eventId = Event::EventType::SETMODE_REQ;
	}

};

class SetModeResp: public Event {
public:
	SetModeResp() {
		this->eventId = Event::EventType::SETMODE_RESP;
	}

};

class Data: public Event {
public:
	Data(std::string& username, std::vector<Par>& data, std::vector<Par>& resp) :
			mUsername { username }, mData { data }, mResp { resp } {
		this->eventId = Event::EventType::DATA;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

	const std::string getData() const {
		return this->mData;
	}

private:
	std::string mUsername;
	std::vector<Par> mData;
	std::vector<Par>& mResp;

};

class Ack: public Event {
public:
	Ack() {
		this->eventId = Event::EventType::ACK;
	}

};

class Subscribe: public Event {
public:
	Subscribe(std::string& username, std::string& assunto) :
			mUsername { username }, mAssunto { assunto } {
		this->eventId = Event::EventType::SUBSCRIBE;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

	const std::string getAssunto() const {
		return this->mAssunto;
	}

private:
	std::string mUsername;
	std::string mAssunto;

};

class Unsubscribe: public Event {
public:
	Unsubscribe() {
		this->eventId = Event::EventType::UNSUBSCRIBE;
	}

};

class Notify: public Event {
public:
	Notify(std::string& username, std::vector<Par>& data) :
			mUsername { username }, mData { data } {
		this->eventId = Event::EventType::NOTIFY;
	}

	const std::string getUsername() const {
		return this->mUsername;
	}

	const std::string getData() const {
		return this->mData;
	}

private:
	std::string mUsername;
	std::vector<Par> mData;
};
