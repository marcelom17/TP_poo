#pragma once

#include "Util.h"

class Posicao {
	int linha, coluna;


public:
	Posicao() {}
	Posicao(int linha, int coluna);
	~Posicao() {}

	int getLinha();
	int getColuna();

};