#include "Quinta.h"

Quinta::Quinta()
{
	custoMon = 20;
	saude = 20;
	defesa = 10;
}

string Quinta::getAsString() const
{
	ostringstream os;
	os << "Quinta:\n\tSaude: " << this->getSaude() << "\n\tDefesa: " << this->getDefesa() << endl;
	return os.str();
}
