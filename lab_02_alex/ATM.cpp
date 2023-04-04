
#include "ATM.h"

ATM::ATM(): tranzactii_efectuate {new Collection<Tranzactie*>}, bancnote{new Collection<int*>}
{

}

ATM::~ATM()
{
    delete tranzactii_efectuate;
    delete bancnote;
}

void ATM::get_bancnote_valabile(int v[8])
{
    for (int i=0;i <  this->bancnote->size();i++)
    {
        int* current_element = this->bancnote->get_element_at_index(i);
        int frecv = this->bancnote->get_occurence_at_index(i);

        if (*current_element == 500)
            v[0] = frecv;
        if (*current_element == 200)
            v[1] = frecv;
        if (*current_element == 100)
            v[2] = frecv;
        if (*current_element == 50)
            v[3] = frecv;
        if (*current_element == 20)
            v[4] = frecv;
        if (*current_element == 10)
            v[5] = frecv;
        if (*current_element == 5)
            v[6] = frecv;
        if (*current_element == 1)
            v[7] = frecv;
    }
}

Tranzactie* ATM::creare_instanta_tranzactie(int suma)
{
    int bancnote_valabile[8] = {0};
    get_bancnote_valabile(bancnote_valabile);

    auto* nouaTranz = new Tranzactie(suma,bancnote_valabile);
    return nouaTranz;
}

void ATM::adauga_tranzactie(Tranzactie* tranzactie_de_adaugat)
{
    this->tranzactii_efectuate->add(tranzactie_de_adaugat);
    Collection<int*> *bancnote_folosite_in_tranzactie = tranzactie_de_adaugat->get_bancnote_folosite();
    for (int i = 0; i < bancnote_folosite_in_tranzactie->size(); i++)
    {
        int bancnota_folosita_in_tranzactie = *(bancnote_folosite_in_tranzactie->get_element_at_index(i));
        int numar_bancnote_folosite_in_tranzactie = bancnote_folosite_in_tranzactie->get_occurence_at_index(i);
        for (int j = 0; j < this->bancnote->size(); j++)
        {
            int bancnota_curenta_in_atm = *(this->bancnote->get_element_at_index(j));
            int numar_bancnota_curenta_in_atm = this->bancnote->get_occurence_at_index(j);
            if (bancnota_folosita_in_tranzactie == bancnota_curenta_in_atm)
                this->bancnote->set_occurence_at_index(j, numar_bancnota_curenta_in_atm - numar_bancnote_folosite_in_tranzactie);
        }
    }
}

int* ATM::creeaza_bancnota(int x)
{
    int *p = new int;
    *p = x;
    return p;
}

void ATM::adauga_bancnota_in_atm(int bancnota)
{
    int *p = creeaza_bancnota(bancnota);
    this->bancnote->add(p);
}

Tranzactie *ATM::get_tranzactia_numarul(int numar)
{
    return this->tranzactii_efectuate->get_element_at_index(numar - 1);
}

