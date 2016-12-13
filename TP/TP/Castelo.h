#pragma once

#include "Util.h"
#include "Edificio.h"

class Castelo : public Edificio {
	char id = 'C';

public:
	Castelo();
	virtual string getAsString() const;
};
