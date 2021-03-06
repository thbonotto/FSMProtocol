/*
 * ProtoClienteAPI.h
 *
 *  Created on: 25 de nov de 2015
 *      Author: Thiago Bonotto
 */
#pragma once

#include <vector>
#include <string>

using namespace std;

// códigos de retorno para operações do protocolo
enum Codigos_Retorno {
  OK,
  ERRO,
  RECUSADO,
  TIMEOUT
};

// um par atributo, valor, usado para as trocas de dados entre entidades do protocolo
//struct Par {
//  string atributo;
//  string valor;
//};

typedef std::pair<std::string,std::string> Par;

// Uma classe abstrata para implementar um objeto-função. Isso pode ser usado para
// implementar o callback para recebimento de notificações (notify)
// Deve-se especializá-la, sobrescrevendo o método "operator()"
class NotifyCallback {
  public:
   virtual void operator()(const string & assunto, const vector<Par> & data) = 0;
};

// A interface de acesso ao serviço é implementada na classe ProtoClienteAPI
class ProtoClienteAPI {
 private:
  string IP; //o IP da outra entidade de protocolo
  int port; // o port da outra entidade de protocolo
  string jogador; // o identificador do jogador usado pelo protocolo
  NotifyCallback * notify_cb; // o callback para receber notificações ... inicialmente NULL
 public:
  ProtoClienteAPI(const string & IP, int port);
  ~ProtoClienteAPI();

  // Define o callback para receber notificações
  void set_notify(NotifyCallback & cb) { notify_cb = &cb;}

  // As operações do protocolo a seguir disparam exceções quando falham

  // solicita um login no jogo
  void login(const string & nome, const string & senha);

  // Solicita uma listagem, o que depende do contexto e isso depende da aplicação. Por exemplo:
  // - se cliente está logado, então obtém uma listagem das partidas existentes
  // - se cliente é membro de uma partida, obtém uma listagem dos demais participantes da partida
  // O resultado é uma lista de pares ... isso dá flexibilidade para a aplicação gerar a informação que achar
  // pertinente a cada listagem.
  void lista_info(vector<Par> & lista);

  // Entra em uma partida
  void join(const string & partida, const string & extra);

  // Sai de uma partida
  void leave();

  // Sai do jogo
  void logout();

  // Envia dados pro jogo. Usa lista de pares para enviar dados genéricos. A resposta do servidor
  // é retornada no argumento "resp"
  void send(const vector<Par> & data, vector<Par> & resp);

  // Assina algum assunto no jogo
  void subscribe(const string & assunto);

  // Cancela assinatura de um assunto
  void unsubscribe(const string & assunto);

  // Publica dados relativos a um assunto
  void publish(const string & assunto, vector<Par> & data);

  // Verifica se alguma notificação de um assunto foi recebida. Só faz sentido usar isto
  // se o callback para receber notificações não foi definido.
  void poll_notify(const string & assunto, vector<Par> & data);

 private:
  // o tratador de evento da máquina de estados do protocolo
  // as operações solicitadas pela aplicação por meio dos métodos desta classe
  // são tratadas como eventos para a máquina de estados
  // Os argumentos do tratador de evento dependem da implementação de cada um ...
  //handle(...);
};
