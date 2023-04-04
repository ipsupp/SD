#pragma once
#include "Collection.h"
#include "Tranzactie.h"

class ATM
{
private:
    Collection<Tranzactie*> *tranzactii_efectuate;
    Collection<int*> *bancnote;

public:
    ~ATM();
    ATM();
    Tranzactie* creare_instanta_tranzactie(int suma);
    void adauga_tranzactie(Tranzactie* tranzactie_de_adaugat);
    int* creeaza_bancnota(int x);
    void adauga_bancnota_in_atm(int bancnota);
    void get_bancnote_valabile(int v[]);
    Tranzactie* get_tranzactia_numarul(int numar);

};