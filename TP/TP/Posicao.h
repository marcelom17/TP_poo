#ifndef POSICAO_H
#define POSICAO_H

#include "Util.h"

class Posicao {
	int linha, coluna;

public:
	Posicao() {}
	Posicao(int linha, int coluna);
	~Posicao() {}

	int getLinha();
	void setLinha(int l);
	int getColuna();
	void setColuna(int c);

};

#endif // !POSICAO_H