#include "Caracteristicas.h"

Caracteristicas::Caracteristicas(string n)
{
	nome = n;
}

string Caracteristicas::getNome() const
{
	return nome;
}

int Caracteristicas::getID() const
{
	return id;
}

string Caracteristicas::getAsString()
{
	ostringstream os;
	os << getNome() << "\n\tID: " << getID() << endl;
	return os.str();
}
