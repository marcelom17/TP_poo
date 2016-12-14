#include "Jogo.h"

void Jogo::Inicia_jogo(){
	//limpar o ecra

	//usar consola para mostrar as coisas

}

int Jogo::avanca_instancia(int n){
	//avançar a instancia, podemos fazer tudo de uma vez, ou tem de ser um ciclo, para avançar uma a uma por causa do cpu fazer jogada uma a uma ?
	instancia += n;
	return instancia;
	//ou em ciclo

}
