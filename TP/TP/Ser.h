#pragma once

#include "Util.h"

class Caracteristicas;
class Colonia;							// not sure tho..

class Ser {
	int saude;
	int forca;
	int velocidade;
	char id = 'S';
protected:
	vector<Caracteristicas *> ataque;
	vector<Caracteristicas *> defesa;
	// not sure se é preciso 1 ou 2 ...
public:
	Ser();
	~Ser();

	int getSaude() const;
	void aumentaSaude(int s);
	void diminuiSaude(int s);

	int getForca() const;
	void aumentaForca(int f);
	void diminuiForca(int f);

	int getVelocidade();

	void mostraSer();
};