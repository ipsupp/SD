#include "Tranzactie.h"
#include "Collection.h"
#include <cstdlib>


int Tranzactie::random_idTranz()
{
    int randomNumber = rand();
    return randomNumber;
}

Tranzactie::Tranzactie(int suma, int bancnote_valabile_in_atm[]) : bancnote_folosite {new Collection<int*>}//, banc_val {this->banc_val = banc_val}
{
    this->id_tranzactie = Tranzactie::random_idTranz();
    this->suma = suma;

    for (int i = 0; i < 8; i++)
        this->bancnote_valabile_in_atm[i] = bancnote_valabile_in_atm[i];

    bool procesat = procesare();
}

Tranzactie::~Tranzactie()
{
    delete this->bancnote_folosite;
}

int* Tranzactie::creare_bancnota(int x)
{
    int *p;
    p = new int;
    *p = x;
    return p;
}


bool Tranzactie::procesare()
{
    int suma_curenta = this->suma;
    int bancnote[] = {500, 200, 100, 50, 20, 10, 5, 1};
    int index_cea_mai_mare_bancnota = 0;

    while(index_cea_mai_mare_bancnota < 8 and suma_curenta < bancnote[index_cea_mai_mare_bancnota])
        index_cea_mai_mare_bancnota++;

    int bancnote_de_adaugat[10000];
    int numar_de_bancnote_de_adaugat = -1;

    while (suma_curenta != 0 and index_cea_mai_mare_bancnota < 8)
    {
        int numar_de_bancnote = 0;
        if(suma_curenta >= bancnote[index_cea_mai_mare_bancnota])
        {
            numar_de_bancnote = suma_curenta / bancnote[index_cea_mai_mare_bancnota];

            int bancnote_valabile_curente = this->bancnote_valabile_in_atm[index_cea_mai_mare_bancnota];
            if (numar_de_bancnote > bancnote_valabile_curente)
                numar_de_bancnote = bancnote_valabile_curente;

            for (int j=0; j < numar_de_bancnote; j++)
                bancnote_de_adaugat[++numar_de_bancnote_de_adaugat] = bancnote[index_cea_mai_mare_bancnota];
        }
        suma_curenta = suma_curenta - numar_de_bancnote * bancnote[index_cea_mai_mare_bancnota];
        index_cea_mai_mare_bancnota++;
    }

    if (suma_curenta != 0 and index_cea_mai_mare_bancnota <= 8)
    {
        std::cout << "ATM-ul nu are destule bancnote.\n";
        return false;
    }
    else
    {
        for (int i = 0; i <= numar_de_bancnote_de_adaugat; i++)
            this->bancnote_folosite->add(creare_bancnota(bancnote_de_adaugat[i]));
        return true;
    }
}

std::ostream &operator<<(std::ostream &os, const Tranzactie &tranzactie)
{
    os << "Suma = " << tranzactie.suma << '\n';
    for (int i = 0; i < tranzactie.bancnote_folosite->size(); i++)
    {
        if (tranzactie.bancnote_folosite->get_occurence_at_index(i) != 0)
        {
            os << *(tranzactie.bancnote_folosite->get_element_at_index(i)) << " lei: "
               << tranzactie.bancnote_folosite->get_occurence_at_index(i) << " bancnote\n";
        }
    }
    return os;
}

bool Tranzactie::operator==(const Tranzactie &cealalta_tranzactie_de_comparat) const
{
    return this->suma == cealalta_tranzactie_de_comparat.suma;
}

bool Tranzactie::tranzactie_indeplinita()
{
    return this->bancnote_folosite->size() != 0;
}

Collection<int *> *Tranzactie::get_bancnote_folosite()
{
    return this->bancnote_folosite;
}



