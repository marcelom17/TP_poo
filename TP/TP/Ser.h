#ifndef SER_H
#define SER_H

#include "Util.h"
#include "Perfil.h"
#include "Posicao.h"

class Colonia;							// not sure tho..

class Ser {
	Perfil *perfil;
	int saude;
	int forca;
	int velocidade;
	Posicao *pos;

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

#endif // !SER_H