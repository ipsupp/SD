#include "Collection.h"
using namespace std;
Collection::Collection()
{
    this->capacitate = 8;
    this->bancnote[0] = 1;
    this->bancnote[1] = 5;
    this->bancnote[2] = 10;
    this->bancnote[3] = 20;
    this->bancnote[4] = 50;
    this->bancnote[5] = 100;
    this->bancnote[6] = 200;
    this->bancnote[7] = 500;
    for (int i = 0; i < capacitate; i++)
        frecv[i] = 0;
}

Collection::~Collection() {}

int Collection::get_bancnota(int index)
{
    return this->bancnote[index];
}

int Collection::get_frecventa(int index)
{
    return this->frecv[index];
}

int Collection::get_capacitate()
{
    return this->capacitate;
}

bool Collection::add_bancnota(TElem &b)
{
    int poz = -1;
    for (int i = 0; i < this->capacitate; i++)
        if (this->bancnote[i] == b)
            poz = i;

    if (poz != -1)
    {
        this->frecv[poz]++;
        return true;
    }
    return false;
}

bool Collection::delete_bancnota(TElem &b)
{
    int poz = -1;
    for (int i = 0; i < this->capacitate; i++)
        if (this->bancnote[i] == b)
            poz = i;
    if (poz != -1 and frecv[poz] > 0)
    {
        this->frecv[poz]--;
        return true;
    }
    return false;
}

int Collection::suma_bancnote_total()
{
    int s = 0;
    for (int i = 0; i < this->capacitate; i++)
        s = s + bancnote[i] * frecv[i];
    return s;
}

Collection& Collection::operator=(const Collection &col)
{
    for (int i=0; i<this->capacitate; i++)
        this->frecv[i] = col.frecv[i];
    return *this;
}

ostream& operator<<(ostream &os, const Collection &col)
{
    for (int i = 0; i < col.capacitate; i++)
        if (col.frecv[i] > 0)
            os<<"Exista "<<col.frecv[i]<<" de bancnote de "<<col.bancnote[i]<<" lei.";
    return os;
}