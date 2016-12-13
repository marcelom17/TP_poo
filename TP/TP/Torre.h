#pragma once

#include "Util.h"
#include "Edificio.h"

class Torre : public Edificio {
	char id = 'T';

public:
	Torre();
	virtual string getAsString() const;

};
