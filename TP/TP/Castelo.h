#ifndef CASTELO_H
#define CASTELO_H

#include "Util.h"
#include "Edificio.h"
#include "Posicao.h"

class Castelo : public Edificio {
	char id = 'C';
	Posicao *pos;

public:
	Castelo(int x, int y);
	string getAsString() const;
};

#endi