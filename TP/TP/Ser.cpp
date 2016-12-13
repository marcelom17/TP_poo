#include "Ser.h"

Ser::Ser()
{
}

Ser::~Ser()
{
}

int Ser::getSaude() const
{
	return saude;
}

void Ser::aumentaSaude(int s)
{
	saude += s;
}

void Ser::diminuiSaude(int s)
{
	if ((saude -= s) < 0) {
		saude = 0;
	}
	else {
		saude -= s;
	}
}

int Ser::getForca() const
{
	return forca;
}

void Ser::aumentaForca(int f)
{
	forca += f;					// ainda não li se isto tinha maximos
}

void Ser::diminuiForca(int f)
{
	forca -= f;					// ou minimos...
}

int Ser::getVelocidade()
{
	return velocidade;
}

void Ser::mostraSer()
{
	cout << this->id;
}
