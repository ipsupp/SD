#pragma once
#include "Collection.h"
#include "Tranzaction.h"

class ATM
{

private:
    Collection bancnote_valabile;
    Tranzaction tranzactii[100];
    int nr_tranz;

public:

    ATM();
    ~ATM();
    void afisare_bancnote_valabile();
    void adauga_bancnote_bancomat(int x, int q);

    bool get_bancnote(int x);
    int get_nr_bancnote(int x);
    void get_bancnote_valabile(int v[8]);

    void tranzactie(int suma);
    void adaugare_tranzactie(Tranzaction &tranz_de_adaugat);
    void sterge_bancnote(int x, int q);

};