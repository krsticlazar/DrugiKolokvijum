#pragma once
#include <iostream>
#include <fstream>
#include "Ispit.h"
using namespace std;

template <class T> 
class Kolekcija
{
	int kapacitet;
	int brojElemenata;
	T* niz;

public:
	
	Kolekcija(int kap);
	~Kolekcija();
	void DodajPodatak(T pod);
	void Obrisi(int id);
	float OdrediProsek();
	T NajveciPodatak();
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
	friend ostream& operator<<(ostream& izlaz, const Kolekcija& kolekcija) {
		izlaz << "   ";
		for (int i = 0;i < (kolekcija.brojElemenata);i++)
			izlaz << kolekcija.niz[i] << "   ";
		izlaz << endl;
		return izlaz;
	}

};

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	delete[] niz;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int kap)
{
	brojElemenata = 0;
	this->kapacitet = kap;
	niz = new T[kap];
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T pod)
{
	if (this->brojElemenata < this->kapacitet)
		niz[(this->brojElemenata)++] = pod;
	else throw "Niz je pun!";
}

template<class T>
inline void Kolekcija<T>::Obrisi(int indeks)
{
	indeks--;
	if (indeks < brojElemenata) {
		niz[indeks] = niz[--brojElemenata];
		cout << "Obrisan podatak! :)\n";
	}
	else
		throw "Nepravilan indeks";
}

template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	float prosek = 0;
	for (int i = 0;i < brojElemenata;i++)
		prosek += this->niz[i];
	return prosek / brojElemenata;
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	T najveci = this->niz[1];
	for (int i = 1;i < brojElemenata;i++)
		if (najveci < this->niz[i])
			najveci = this->niz[i];
	return najveci;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imeFajla) {
	try {
		ofstream file(imeFajla); // Otvorite datoteku direktno ovdje
		if (!file.is_open()) {
			cout << "Ne mogu otvoriti fajl za pisanje: " << imeFajla << endl;
			return;
		}

		file << this->brojElemenata << endl;

		for (int i = 0; i < this->brojElemenata; i++)
			file << niz[i] << "   ";

		file << "\n";
		file.close();
	}
	catch (...) {
		// Hvatanje svih izuzetaka
	}
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	try
	{
		ifstream file(imeFajla);
		if (!file.is_open()) {
			throw  "Ne mogu otvoriti fajl za citanje";
			return;
		}

		file >> this->brojElemenata;

		for (int i = 0;i < this->brojElemenata;i++)
			file >> this->niz[i];

		//file.close;
	}
	catch (...)
	{

	}
}
