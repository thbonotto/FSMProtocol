/*
 * Timeout.h
 *
 *  Created on: 22 de dez de 2015
 *      Author: aluno
 */

#pragma once
#include <exception>
class TimeoutException : public std::exception {
 public:

};

/// Selector

#include <sys/select.h>

/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int timeout() {
  cout << "Este programa mostra como limitar o tempo de espera para que ";
  cout << "se tecle alguma coisa ..." << endl;

  cout << endl << "Esperando que se tecle ENTER ... " ;
  cout.flush();

  int fd = 0; // o descritor 0 corresponde à entrada padrão ...

  struct timeval timeout; // para especificar o timeout
  timeout.tv_sec = 2; //timeout de 2 segundos
  timeout.tv_usec = 0;

  fd_set espera;
  FD_ZERO(&espera);
  FD_SET(fd, &espera);

  if (select(1, &espera, NULL, NULL, &timeout) == 0) { // timeout !!
    cout << "Timeout !" << endl;
  } else {
    cout << "Algo foi teclado ..." << endl;
  }
}
