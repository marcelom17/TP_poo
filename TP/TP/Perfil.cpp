#include "Perfil.h"

Perfil::Perfil(char letra)
{
	id = letra;
}

string Perfil::toString()
{
	ostringstream os;
	os << "Perfil : " << getID();
	return os.str();
}

char Perfil::getID()
{
	return id;
}
