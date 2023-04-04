#pragma once

typedef int TElem;
#include "Collection.h"

class Tranzactie
{
private:
    int id_tranzactie;
    int suma;
    Collection<int*>* bancnote_folosite;
    int bancnote_valabile_in_atm[8];


public:

    int random_idTranz();
    Tranzactie(int suma = 0, int v[] = {0});
    ~Tranzactie();
    bool procesare();
    int *creare_bancnota(int x);
    friend std::ostream& operator<<(std::ostream& os, const Tranzactie& tranzactie);
    bool operator==(const Tranzactie& cealalta_tranzactie_de_comparat) const;
    bool tranzactie_indeplinita();
    Collection<int*> *get_bancnote_folosite();
};