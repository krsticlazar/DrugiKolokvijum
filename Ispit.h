#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Ispit
{
	const char* naziv;
	int ocena;
	int espb;

public:
    Ispit();
	Ispit(const char* naz,int oc, int es);

    friend ostream& operator<<(ostream& izlaz, const Ispit& ispit);
    friend istream& operator>>(istream& ulaz, Ispit& ispit);

    operator int() const;  
    Ispit& operator=(const Ispit& other);
    bool operator<(const Ispit& other) const;
    Ispit& operator+=(const Ispit& other);
    bool operator==(const Ispit& other) const;
};

