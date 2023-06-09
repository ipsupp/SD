#pragma once
#include "List.h"

class Collection
{
private:
    List<int> lista_bancnote;
    List<int> lista_frecventa;
public:
    Collection();
    ~Collection();

    void adauga_bancnota(int elem, int frecv);
    void adauga_bancnota_la_index(int index, int elem, int frecv);
    void sterge_bancnota(int elem);
    void schimbare_frecventa(int elem, int frecv);
    int tranzactie(int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[]);
    void afisare_bancnote();

    int get_nr_elemente();
    int get_bancnota(int index);
    int get_frecventa(int index);
};