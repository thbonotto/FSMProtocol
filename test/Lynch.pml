mtype = {ack, nak, err};

typedef Mensagem {
  mtype tipo;
  int car
}

chan canal1 = [1] of { Mensagem };
chan canal2 = [1] of { Mensagem };

int lastdata1
int lastdata2
 
active proctype p1() {
    mtype tipo
    int dado
    do
	:: canal1?tipo,dado; assert(dado != lastdata1)
	if
	:: true -> printf("C1 Recebeu %d do tipo ACK \n", dado) 
		   lastdata1=dado
		   dado++
		   canal2!ack,dado	
	:: true -> printf("C1 Recebeu %d do tipo NACK \n", dado)
		   lastdata1=dado
		   canal2!nak,dado
	:: true -> printf("C1 Recebeu %d do tipo ERR \n", dado)
		   lastdata1=dado
		   canal2!err,dado
	fi
    od 
}
 
 
active proctype p2() {

  // Falha do protocola, iniciar start manual.
  // Envia uma mensagem pelo canal 1
  
  canal1!err,15
  mtype tipo
    int dado
    do
        :: canal2?tipo,dado; assert(dado != lastdata2)
        if
        :: true -> printf("C2 Recebeu %d do tipo ACK \n", dado)
                   lastdata2=dado
  		   dado++
                   canal1!ack,dado
        :: true -> printf("C2 Recebeu %d do tipo NACK \n", dado)
                   lastdata2=dado
                   canal1!nak,dado
        :: true -> printf("C2 Recebeu %d do tipo ERR \n", dado)
                   lastdata2=dado
                   canal1!err,dado
        fi
    od

}
