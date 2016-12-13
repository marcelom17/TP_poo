#include "Edificio.h"

Edificio::Edificio()
{
}

Edificio::~Edificio()
{
}

string Edificio::getNome()
{
	return nome;
}

int Edificio::getSaude() const
{
	return saude;
}

int Edificio::getDefesa() const
{
	return defesa;
}

void Edificio::aumentaSaude(int s)
{
	saude += s;
}

void Edificio::diminuiSaude(int s)
{
	if ((saude -= s) < 0) {
		saude = 0;
	}
	else {
		saude -= s;
	}
}

void Edificio::aumentaDefesa(int d)
{
	defesa += d;
}

void Edificio::diminuiDefesa(int d)
{

	if ((defesa -= d) < 0) {
		defesa = 0;
	}
	else {
		defesa -= d;
	}
}
