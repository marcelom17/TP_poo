#pragma once

#include "Util.h"

class Ser;
class Colonia;

class Caracteristicas {
	string nome;

protected:
	int id;
	int custoMon;
	int custoForca;

public:
	Caracteristicas(string n);

	string getNome() const;
	int getID() const;

	virtual string getAsString();
	virtual void inicioJogo() = 0;
};
