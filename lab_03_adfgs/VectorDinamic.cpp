
#include "VectorDinamic.h"
#include <iostream>
using namespace std;
VectorDinamic::VectorDinamic()
{
    this->capacity = 0;
    this->nrElems = 0;
}

VectorDinamic::VectorDinamic(int capacitate)
{
    if (capacitate <= 0)
        throw invalid_argument("Capacitatea trebuie sa fie un nr pozitiv.");
    this->capacity = capacitate;
    this->elems = new TElem [capacitate];
    this->frecv = new int [capacitate];
    for (int i = 0;i <capacitate; i ++)
        frecv[i] = 0;
    this->nrElems = 0;
}

void VectorDinamic::add_el_frecv(TElem el, int frecv_noua)
{

    int ok = 0;
    for (int i = 0 ;i <nrElems; i++)
    {
        if (elems[i] == el)
        {
            frecv[i] = frecv[i] + frecv_noua;
            ok = 1;
        }
    }
    if (ok == 0)
    {
        if (capacity == nrElems)
            resize();
        elems[nrElems] = el;
        frecv[nrElems] = frecv_noua;
        nrElems++;
    }
}

VectorDinamic::~VectorDinamic() {}

void VectorDinamic::resize()
{
    this->capacity = this->capacity * 2;
    for (int i = 0;i <capacity; i ++)
        frecv[i] = 0;
}

int VectorDinamic::get_capacitate()
{
    return capacity;
}

void VectorDinamic::set_capacitate(int capacitate)
{
    this->capacity = capacitate;
}

int VectorDinamic::size()
{
    return this->nrElems;
}

TElem VectorDinamic::get_elem(int index)
{
    return this->elems[index];
}

int VectorDinamic::get_frecv(TElem el)
{
    for (int i = 0; i < nrElems; i++)
        if (elems[i] == el)
            return frecv[i];
    return 0;
}



int VectorDinamic::get_index(TElem element)
{
    for (int i = 0; i<nrElems;i++)
        if (elems[i] == element)
            return i;


}

void VectorDinamic::sterge(TElem el, int frecv_noua)
{
    for (int i = 0; i<nrElems;i++)
        if (elems[i] == el and frecv[i]!=0)
            frecv[i] = frecv[i] - frecv_noua;
}
