#include "Castelo.h"

Castelo::Castelo()
{
	custoMon = 0;
	saude = 50;
	defesa = 10;
}

string Castelo::getAsString() const
{
	ostringstream os;
	os << "Castelo:\n\tSaude: " << this->getSaude() << "\n\tDefesa: " << this->getDefesa() << endl;
	return os.str();
}
