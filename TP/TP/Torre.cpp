#include "Torre.h"

Torre::Torre()
{
	custoMon = 30;
	saude = 20;
	defesa = 10;
}

string Torre::getAsString() const
{
	ostringstream os;
	os << "Torre:\n\tSaude: " << this->getSaude() << "\n\tDefesa: " << this->getDefesa(); << endl;
	return os.str();
}
