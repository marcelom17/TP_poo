#pragma once

#include"Util.h"

class Celula {
	int posx, posy;
	int cor;
	bool ocupado;
public:
	int getColor();
	void setColor(int c);
};