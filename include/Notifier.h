/*
 * Notifier.h
 *
 *  Created on: 25 de nov de 2015
 *      Author: aluno
 */

#ifndef NOTIFIER_H_
#define NOTIFIER_H_
#include "../include/ProtoClienteAPI.h"

class Notifier : public NotifyCallback{
public:

	void operator() (const string & assunto, const vector<Par> & data){

	}
	virtual ~Notifier();
};
#endif /* NOTIFIER_H_ */
