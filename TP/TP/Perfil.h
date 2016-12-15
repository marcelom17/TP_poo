#ifndef PERFIL_H
#define PERFIL_H

#include "Util.h"

class Caracteristicas;

class Perfil {
	char id;
	vector <Caracteristicas *> caracteristicas;
public:
	Perfil(char letra);							// neste momento só vai servir para mostrar o perfil na consola

	string toString();
	char getID();
};

#endif
