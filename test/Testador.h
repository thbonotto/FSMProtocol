/* 
 * File:   Testador.h
 * Author: msobral
 *
 * Created on 25 de Novembro de 2015, 07:25
 */

#ifndef TESTADOR_H
#define TESTADOR_H

#include <string>
#include <map>

#include "../include/ProtoServidorAPI.h"

class Testador : public Jogo{
public:
    Testador(const string & name);
    Testador(const Testador& orig);
    virtual ~Testador();
    
    // operações do protocolo
  // verifica as credenciais do jogador. Retorna verdadeiro se login autorizado.
  virtual bool login(const string & nome, const string& senha);
 
  // tenta adicionar jogador a uma partida. Retorna verdadeiro em caso de sucesso.
  virtual bool join(const string & name, const string & partida, const string & extra);
 
  // remove jogador da partida em que se encontra
  virtual void leave(const string & name);
 
  // recebe dados de um jogador. Se houver dados para enviar como resposta, eles devem ser inseridos
  // em "resp"
  virtual void data(const string & name, const vector<Par> & data, vector<Par> & resp);
 
  // recebe uma notificação para um assunto
  virtual void notify(const string & assunto, const vector<Par> & data);
 
  // verifica se o assunto pode ser assinado. Retorna verdadeiro caso afirmativo.
  virtual bool subscribe(const string & name, const string & assunto);
    
private:

};

#endif	/* TESTADOR_H */

