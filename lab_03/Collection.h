#pragma once
#include "VectorDinamic.h"
typedef int TElem;
class Collection
{
private:
    VectorDinamic vector;
public:
    Collection(int capacitate);
    Collection(const Collection &coll);
    ~Collection();

    void adauga_bancnota(TElem elem, int frecv);
    void sterge_bancnota(TElem elem);
    void schimbare_frecventa(TElem elem, int frecv);
    int tranzactie(int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[]);
    void afisare_bancnote();

    int get_capacitate();
    int get_nr_elemente();
    TElem get_bancnota(int index);
    int get_frecventa(int index);
//    void set_frecventa(int index, int frecv); inlocuita cu schimbare frecvent


};
