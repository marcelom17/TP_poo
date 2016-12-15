#include "Castelo.h"

Castelo::Castelo(int l, int c)
{
	custoMon = 0;
	saude = 50;
	defesa = 10;
	pos->setColuna(c);
	pos->setLinha(l);
}

string Castelo::getAsString() const
{
	ostringstream os;
	os << "Castelo:\n\tSaude: " << this->getSaude() << "\n\tDefesa: " << this->getDefesa(); << endl;
	return os.str();
}
