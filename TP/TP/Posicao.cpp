#include "Posicao.h"

Posicao::Posicao(int linha, int coluna) {
	this->linha = linha;
	this->coluna = coluna;
}

int Posicao::getLinha()
{
	return linha;
}

void Posicao::setLinha(int l)
{
	linha = l;
}

int Posicao::getColuna()
{
	return coluna;
}

void Posicao::setColuna(int c)
{
	coluna = c;
}
