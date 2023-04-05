#include "Tranzaction.h"
#include <iostream>
#include <random>
using namespace std;

Tranzaction::Tranzaction()
{
    this->idTranzactie = rand();
    this->suma = 0;
}

Tranzaction::Tranzaction(int idTranzactie, int suma, Collection &banc)
{
    this->idTranzactie = idTranzactie;
    this->suma = suma;
    this->bani = banc;
}

Tranzaction::~Tranzaction() {}

int Tranzaction::get_idTranzactie()
{
    return this->idTranzactie;
}
int Tranzaction::get_suma()
{
    return this->suma;
}

Tranzaction& Tranzaction::operator=(const Tranzaction& tranz)
{
    this->idTranzactie = tranz.idTranzactie;
    this->suma = tranz.suma;
    this->bani = tranz.bani;
    return *this;
}

ostream& operator<<(ostream &os, const Tranzaction &tranz)
{
    os<<"Id-ul tranzactiei: "<<tranz.idTranzactie<<endl;
    os<<"Suma tranzactiei: "<<tranz.suma<<endl;
    os<<"Urmatoarele bancnote efectueaza plata: "<<endl;
    os<<tranz.bani;
    return os;
}