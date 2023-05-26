#pragma once
#include "Collection.h"
#include "Tranzaction.h"

class ATM
{
private:
    Collection bancnote_in_atm;
    Tranzaction tranzactii[101];
    int nr_tranz;
public:
    ATM();
    ~ATM();

    void adaugare_bancnote_bancomate(int elem, int frecv);
    void schimbare_or_stergere_frecv(int elem, int frecv);
    void afisare_bancnote();
    void tranzactie(int suma);
    void afisare_tranzactii();
    int main_menu();
    void user_menu();
};