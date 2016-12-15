#include "Posicao.h"

Posicao::Posicao(int linha, int coluna){
	this->linha = linha;
	this->coluna = coluna;
}

int Posicao::getLinha()
{
	return linha;
}

int Posicao::getColuna()
{
	return coluna;
}
