#include "Tranzaction.h"
#include <iostream>
#include <random>
using namespace std;

Tranzaction::Tranzaction()
{
    this->idTranzactie = rand();
    this->suma = 0;

}

Tranzaction::Tranzaction(int idTranzactie, int suma)
{
    this->idTranzactie = idTranzactie;
    this->suma = suma;
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

void Tranzaction::set_suma(int suma)
{
    this->suma = suma;
}
