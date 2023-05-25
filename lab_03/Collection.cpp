#include "Collection.h"
#include <iostream>
using namespace std;
Collection::Collection()
    : vector_frecventa(10),vector_bancnote(10)
{}

Collection::Collection(const Collection &coll)
{
    vector_bancnote = coll.vector_bancnote;
    vector_frecventa = coll.vector_frecventa;
}
Collection::~Collection() {
}

void Collection::adauga_bancnota(TElem elem, int frecv)
{
    vector_bancnote.push_back(elem);
    vector_frecventa.push_back(frecv);
}

void Collection::sterge_bancnota(int index)
{
    vector_bancnote.sterge_element(index);
    vector_frecventa.sterge_element(index);
}

void Collection::afisare_bancnote()
{
    int size = vector_frecventa.get_nr_elemente();
    for (int i = 0; i < size; i++)
        cout<<vector_bancnote.get_at_index(i)<<" * "<<vector_frecventa.get_at_index(i)<<";"<<endl;
}

int Collection::get_capacitate()
{
    return vector_bancnote.size();
}

int Collection::get_nr_elemente()
{
    return vector_bancnote.get_nr_elemente();
}

TElem Collection::get_bancnota(int index)
{
    return vector_bancnote.get_at_index(index);
}

int Collection::get_frecventa(int index)
{
    return vector_frecventa.get_at_index(index);
}

void Collection::schimbare_frecventa(TElem elem, int frecv)
{
    int index = vector_bancnote.search(elem);
    vector_frecventa.update(index, frecv);
}

int Collection::tranzactie(int &nr_elems_vectori, int &suma, int *v_banc, int *v_fr)
{
    //int suma_copie = suma;
    int index_bancnota_max = 0;
    int maxim = 0;
    int nr_elems_vectori_cpy = 0;
    int size = vector_bancnote.get_nr_elemente();
    for (int i = 0; i < size; i ++)
    {
        if (vector_bancnote.get_at_index(i) > maxim and vector_frecventa.get_at_index(i) > 0)
        {
            maxim = vector_bancnote.get_at_index(i);
            index_bancnota_max = i;
        }
    }
    while (index_bancnota_max >= 0 and suma != 0)
    {
        int nr_bancnote = 0;
        int bancnota = 0, freq = 0;
        bancnota = vector_bancnote.get_at_index(index_bancnota_max);
        freq = vector_frecventa.get_at_index(index_bancnota_max);
        if (suma >= bancnota)
        {
            nr_bancnote = suma / bancnota;
            if (freq >= nr_bancnote and bancnota != 0 )
            {
                v_banc[nr_elems_vectori_cpy] = bancnota;
                v_fr[nr_elems_vectori_cpy] = nr_bancnote;
                nr_elems_vectori_cpy++;
                suma = suma - bancnota * nr_bancnote;
                schimbare_frecventa(bancnota, freq - nr_bancnote);
            }
            else if (freq < nr_bancnote and bancnota != 0)
            {
                v_banc[nr_elems_vectori_cpy] = bancnota;
                v_fr[nr_elems_vectori_cpy] = freq;
                nr_elems_vectori_cpy++;
                suma = suma - bancnota * freq;
                int index = vector_bancnote.search(bancnota);
                vector_bancnote.sterge_element(index);
                vector_frecventa.sterge_element(index);
            }

        }
        maxim = -2147483647;
        if (bancnota != 1)
        {
            for (int i = 0; i < size; i++)
                if (vector_bancnote.get_at_index(i) > maxim and vector_bancnote.get_at_index(i) < bancnota and vector_frecventa.get_at_index(i) > 0)
                {
                    maxim = vector_bancnote.get_at_index(i);
                    index_bancnota_max = i;
                }
        }
        else index_bancnota_max = -1;

    }
    nr_elems_vectori  = nr_elems_vectori_cpy;
    if (suma != 0)
        return -1;
    if (suma == 0)
        return 0;
}