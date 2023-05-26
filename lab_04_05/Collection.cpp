
#include "Collection.h"
#include <iostream>
using namespace std;
Collection::Collection() {}

Collection::~Collection() {}

void Collection::adauga_bancnota(int elem, int frecv)
{
    lista_bancnote.push_back(elem);
    lista_frecventa.push_back(frecv);
}

void Collection::adauga_bancnota_la_index(int index, int elem, int frecv)
{
    lista_bancnote.set_at(index,elem);
    lista_frecventa.set_at(index, frecv);
}

void Collection::schimbare_frecventa(int elem, int frecv)
{
    if (frecv == 0)
    {
        lista_bancnote.delete_elem(elem);
        lista_frecventa.delete_elem(frecv);
    }
    else
    {
        if (frecv < 0)
            throw invalid_argument("Frecventa nu poate fi negativa.");
        else {
            int index = lista_bancnote.get_indexul(elem);
            lista_bancnote.update(index,elem);
            lista_frecventa.update(index, frecv);
        }
    }
}

void Collection::sterge_bancnota(int elem)
{
    int index = lista_bancnote.get_indexul(elem);
    int element = lista_frecventa.get_at_element(index);
    lista_bancnote.delete_elem(elem);
    lista_frecventa.delete_elem(element);
}

int Collection::get_frecventa(int index)
{
    return lista_frecventa.get_at_element(index);
}

int Collection::get_bancnota(int index)
{
    return lista_bancnote.get_at_element(index);
}

int Collection::get_nr_elemente()
{
    return lista_bancnote.size();
}

void Collection::afisare_bancnote()
{
    int size = lista_bancnote.size();
    for (int i = 0; i < size; i ++)
    {
        cout<<lista_bancnote.get_at_element(i)<<" * "<<lista_frecventa.get_at_element(i)<<endl;
    }
}


int Collection::tranzactie(int &nr_elems_vectori, int &suma, int *v_banc, int *v_fr)
{
    int index_bancnota_max = 0;
    int maxim = 0;
    int nr_elems_vectori_cpy = 0;
    int size = lista_bancnote.size();
    for (int i = 0; i < size; i ++)
    {
        if (lista_bancnote.get_at_element(i) > maxim and lista_frecventa.get_at_element(i) > 0)
        {
            maxim = lista_bancnote.get_at_element(i);
            index_bancnota_max = i;
        }
    }
    while (index_bancnota_max >= 0 and suma != 0)
    {
        int nr_bancnote = 0;
        int bancnota = 0, freq = 0;
        bancnota = lista_bancnote.get_at_element(index_bancnota_max);
        freq = lista_frecventa.get_at_element(lista_bancnote.get_indexul(bancnota));
        if (suma >= bancnota)
        {
            nr_bancnote = suma / bancnota;
            if (freq >= nr_bancnote and bancnota != 0 )
            {
                v_banc[nr_elems_vectori_cpy] = bancnota;
                v_fr[nr_elems_vectori_cpy] = nr_bancnote;
                nr_elems_vectori_cpy++;
                suma = suma - bancnota * nr_bancnote;
            }
            else if (freq < nr_bancnote and bancnota != 0)
            {
                v_banc[nr_elems_vectori_cpy] = bancnota;
                v_fr[nr_elems_vectori_cpy] = freq;
                nr_elems_vectori_cpy++;
                suma = suma - bancnota * freq;
            }

        }
        maxim = -2147483647;
        if (bancnota != 1)
        {
            int size = lista_bancnote.size();
            for (int i = 0; i < size; i++)
                if (lista_bancnote.get_at_element(i) > maxim and lista_bancnote.get_at_element(i) < bancnota and lista_frecventa.get_at_element(i) > 0)
                {
                    maxim = lista_bancnote.get_at_element(i);
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