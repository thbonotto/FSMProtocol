/* 
 * File:   Testador.cpp
 * Author: msobral
 * 
 * Created on 25 de Novembro de 2015, 07:25
 */

#include "Testador.h"
#include "../include/Event/Events.h"
#include <iostream>

using namespace std;

Testador::Testador(const string & name) : Jogo(name) {
}

Testador::Testador(const Testador& orig) : Jogo(orig.get_nome()){
}

Testador::~Testador() {
}

// Operações do protocolo
bool Testador::login(const string& name, const string& senha) {
    cout << "login: nome=" << name << ", senha=" << senha << endl;
    std::string user{name};
    std::string pass{senha};
    LoginReq loginReq{user,pass};
    return true;
}

bool Testador::join(const string& name, const string& partida, const string& extra) {
    cout << "join: nome=" << name << ", partida= " << partida;
    cout << ", extra=" << extra << endl;
    return true;    
}

void Testador::leave(const string& name) {
    cout << "leave: nome=" << name << endl;
}

void Testador::data(const string& name, const vector<Par>& data, vector<Par>& resp) {
    cout << "data: nome=" << name << endl;
    for (vector<Par>::const_iterator it=data.begin(); it != data.end(); it++) {
        cout << "  atributo=" << it->first;
        cout << ", valor=" << it->second << endl;
    }
}

void Testador::notify(const string& assunto, const vector<Par>& data) {
    cout << "notify: assunto=" << assunto << endl;
    for (vector<Par>::const_iterator it=data.begin(); it != data.end(); it++) {
        cout << "  atributo=" << it->first;
        cout << ", valor=" << it->second << endl;
    }
}

bool Testador::subscribe(const string& name, const string& assunto) {
    cout << "subscribe: nome=" << name << ", assunto=" << assunto << endl;
    return true;
}
