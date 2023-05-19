#include "Collection.h"

Collection::Collection(int capacitate) :vector(capacitate)
{
//    VectorDinamic vector(capacitate); // why does it work
}

Collection::Collection(const Collection &coll) :vector(coll.vector) {}

Collection::~Collection(){}

void Collection::afisare_bancnote()
{
    vector.afisare_vector();
}

void Collection::adauga_bancnota(TElem elem, int frecv)
{
    vector.adaugare_element_cu_frecventa(elem,frecv);
}

void Collection::sterge_bancnota(TElem elem)
{
    vector.sterge_element(elem);
}

void Collection::schimbare_frecventa(TElem elem, int frecv)
{
    vector.schimbare_frecventa(elem,frecv);
}

int Collection::tranzactie(int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[])
{
    return vector.tranzactie(nr_elems_vectori,suma,v_banc,v_fr);
}

int Collection::get_capacitate()
{
    return vector.get_capacitate();
}

int Collection::get_nr_elemente()
{
    return vector.get_nr_elemente();
}

TElem Collection::get_bancnota(int index)
{
    return vector.get_at_index(index);
}

int Collection::get_frecventa(int index)
{
    return vector.get_at_frecventa(index);
}


