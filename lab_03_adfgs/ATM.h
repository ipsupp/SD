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
    ATM(int capacity);
    ~ATM();
    void adauga_bancnote_bancomat(TElem element, int q);
    void afisare_bancnote_valabile();
    bool get_bancnote(int x);
    int get_nr_bancnote(int x);
    Collection get_bancnote_valabile();


    void tranzactie(int suma);
    void adaugare_tranzactie(Tranzaction &tranz_de_adaugat);
    void sterge_bancnote(int x, int q);

};