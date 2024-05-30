#include "Ispit.h"
#include <string.h>

Ispit::Ispit()
{
	ocena = espb = 0;naziv = " ";
}

Ispit::Ispit(const char* naz, int oc, int es) :ocena(oc), espb(es), naziv(naz)
{
	
}

Ispit::operator int() const
{
	return ocena;
}

Ispit& Ispit::operator=(const Ispit& other)
{
	if (this != &other) {
		naziv = other.naziv;
		ocena = other.ocena;
		espb = other.espb;
	}
	return *this;
}

bool Ispit::operator<(const Ispit& other) const
{
	return ocena < other.ocena;
}

Ispit& Ispit::operator+=(const Ispit& other)
{
	ocena += other.ocena;
	return *this;
}

bool Ispit::operator==(const Ispit& other) const
{
	return ocena == other.ocena;
}

ostream& operator<<(ostream& izlaz, const Ispit& ispit)
{
	//izlaz << ispit.naziv << ", ocena: " << ispit.ocena << ", espb: " << ispit.espb << endl;
	izlaz << ispit.naziv << "  " << ispit.ocena << "  " << ispit.espb << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Ispit& ispit)
{
	char nazivTmp[100];
	ulaz >> nazivTmp >> ispit.ocena >> ispit.espb;
	ispit.naziv = _strdup(nazivTmp);
	return ulaz;
}

