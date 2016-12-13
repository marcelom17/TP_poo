#pragma once

#include "Util.h"

class Ser;
class Colonia;

class Edificio {
	string nome;

protected:
	int custoMon;
	int saude;
	int defesa;

public:
	Edificio();
	~Edificio();

	virtual string getAsString() = 0;
	string getNome();

	int getSaude() const;
	int getDefesa() const;

	void aumentaSaude(int s);
	void diminuiSaude(int s);
	void aumentaDefesa(int d);
	void diminuiDefesa(int d);
};
