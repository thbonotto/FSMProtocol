#pragma once

struct Par {
  std::string atributo;
  std::string valor;
};

class Event {

public:

	enum Tipo{

	};

	Event(const Tipo& tipo,
			const std::vector<std::string>& args,
			const std::vector<Par>& dados)
	: mTipo{tipo}, mArgs{args}, mDados{dados} {

	}
protected:
	Tipo mTipo;
	std::vector<std::string> mArgs;
	const std::vector<Par> mDados;
};

