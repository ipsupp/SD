#include "VectorDinamic.h"
#include <stdexcept>
#include <iostream>
using namespace std;
VectorDinamic::VectorDinamic()
{
    this->capacitate = 10;
    this->nr_elemente = 0;
}

VectorDinamic::VectorDinamic(int capacitate)
{
    this->capacitate = capacitate;
    this->nr_elemente = 0;
    elemente = new TElem [capacitate];
    frecventa = new int [capacitate];
    for (int i = 0 ; i < capacitate; i++)
        frecventa[i] = 0;
}

VectorDinamic::VectorDinamic(const VectorDinamic &vd)
{
    this->capacitate = vd.capacitate;
    this->nr_elemente = vd.nr_elemente;
    elemente = new TElem [capacitate];
    frecventa = new int [capacitate];
    for (int i = 0; i < nr_elemente; i ++)
    {
        elemente[i] = vd.elemente[i];
        frecventa[i] = vd.frecventa[i];
    }
}
VectorDinamic::~VectorDinamic()
{
    delete[] elemente;
    delete[] frecventa;
}

void VectorDinamic::resize()
{
    this->capacitate = this->capacitate * 2;
}

void VectorDinamic::adaugare_element_cu_frecventa(TElem elem, int frecv)
{
    int ok = 0;
    for (int i = 0; i < nr_elemente; i++)
    {
        if (elemente[i] == elem)
        {
            frecventa[i] = frecventa[i] + frecv;
            ok = 1;
        }
    }
    if (ok == 0)
    {
        if (nr_elemente == capacitate)
            resize();
        elemente[nr_elemente] = elem;
        frecventa[nr_elemente] = frecv;
        nr_elemente++;
    }
}

void VectorDinamic::sterge_element(TElem elem)
{
    int ok = 0;
    for (int i = 0; i < nr_elemente; i++)
    {
        if (elemente[i] == elem)
        {
            for (int j = i; j < nr_elemente - 1; j++)
            {
                TElem aux;
                aux = elemente[j+1];
                elemente[j+1] = elemente[j];
                elemente[j] = aux;
            }
            for (int j = i; j < nr_elemente - 1; j++)
            {
                TElem aux;
                aux = frecventa[j+1];
                frecventa[j+1] = frecventa[j];
                frecventa[j] = aux;

            }
            ok = 1;
            i = nr_elemente + 2;
            nr_elemente--;
        }
    }
    if (ok == 0)
        throw invalid_argument("Elementul nu exista.");

}

void VectorDinamic::schimbare_frecventa(TElem elem, int frecv)
{

    if (frecv < 0)
        throw invalid_argument ("Frecventa nu poate fi negativa.");
    int ok = 0;
    if (frecv > 0)
    {
        for (int i = 0; i < nr_elemente; i++)
            if (elemente[i] == elem)
            {
                frecventa[i] = frecv;
                ok = 1;
            }
    }
    else if (frecv == 0)
    {
        for (int i = 0; i < nr_elemente; i++)
            if (elemente[i] == elem)
            {
                sterge_element(elem);
                ok = 1;
            }
    }
    if (ok == 0)
        throw invalid_argument("Elementul nu exista.");

}

// se apeleaza cu o copie la suma si vector(collection) in atm
int VectorDinamic::tranzactie(int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[])
{
    //int suma_copie = suma;
    int index_bancnota_max = 0;
    int maxim = 0;
    int nr_elems_vectori_cpy = 0;
    for (int i = 0; i < nr_elemente; i ++)
    {
        if (elemente[i] > maxim and frecventa[i] > 0)
        {
            maxim = elemente[i];
            index_bancnota_max = i;
        }
    }
    while (index_bancnota_max >= 0 and suma != 0)
    {
        int nr_bancnote = 0;
        int bancnota = 0, freq = 0;
        bancnota = elemente[index_bancnota_max];
        freq = frecventa[index_bancnota_max];
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
                sterge_element(bancnota);
            }

        }
        maxim = -2147483647;
        if (bancnota != 1)
        {
            for (int i = 0; i < nr_elemente; i++)
                if (elemente[i] > maxim and elemente[i] < bancnota and frecventa[i] > 0)
                {
                    maxim = elemente[i];
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
// -1 = nu sunt destule bancnote;  0 = sunt destule bancnote si se poate realiza


TElem VectorDinamic::get_at_index(int index)
{
    if (index < 0 or index == nr_elemente)
        throw invalid_argument("Index invalid.");
    return elemente[index];
}

int VectorDinamic::get_at_frecventa(int index)
{
    if (index < 0 or index >= nr_elemente)
        throw invalid_argument("Pozitie invalida.");
    return frecventa[index];
}

int VectorDinamic::get_frecventa_of(TElem elem)
{
    for (int i = 0; i < nr_elemente; i++)
        if (elem == get_at_index(i))
            return frecventa[i];
    throw invalid_argument("Elementul nu exista.");
}

int VectorDinamic::get_index_of(int elem)
{
    for (int i = 0; i < nr_elemente; i++)
        if (elem == get_at_index(i))
            return i;
}

int VectorDinamic::get_capacitate()
{
    return this->capacitate;
}
int VectorDinamic::get_nr_elemente()
{
    return this->nr_elemente;
}
//functiile de afisare sunt folosite doar pentru observatii in timpul procesului de testare


void VectorDinamic::afisare_element(int index)
{
    cout<<elemente[index]<<" * "<<frecventa[index]<<endl;
}

void VectorDinamic::afisare_vector()
{
    cout<<"Bancnotele din ATM:"<<endl;
    for (int i = 0; i < nr_elemente; i++)
        afisare_element(i);
}
