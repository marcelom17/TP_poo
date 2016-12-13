#pragma once

#include "Util.h"
#include "Edificio.h"

class Quinta : public Edificio {
	char id = 'Q';

public:
	Quinta();
	virtual string getAsString() const;
};
