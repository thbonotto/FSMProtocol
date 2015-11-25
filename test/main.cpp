/* 
 * File:   main.cpp
 * Author: msobral
 *
 * Created on 25 de Novembro de 2015, 07:24
 */

#include <cstdlib>
#include "Testador.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Testador jogo("testador");
    ProtoServidorAPI protocolo("0.0.0.0", 9999, jogo);
    
    protocolo.subscribe("teste");
    
    protocolo.serve_forever();
    
    return 0;
}

