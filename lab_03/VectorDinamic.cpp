#include "VectorDinamic.h"
#include <stdexcept>
#include <iostream>
using namespace std;

VectorDinamic::VectorDinamic()
{
    capacitate = 10;
    nr_elemente = 0;
}

VectorDinamic::VectorDinamic(int capacitate)
{
    this->capacitate = capacitate;
    this->nr_elemente = 0;
    elemente = new TElem [capacitate];
}

VectorDinamic::~VectorDinamic()
{
    delete[] elemente;
}

VectorDinamic::VectorDinamic(const VectorDinamic &vd)
{
    this->capacitate = vd.capacitate;
    this->nr_elemente = vd.nr_elemente;
    elemente = new TElem [capacitate];
    for (int i = 0; i < nr_elemente; i ++)
        elemente[i] = vd.elemente[i];
}

void VectorDinamic::push_back(TElem elem)
{
    elemente[nr_elemente] = elem;
    nr_elemente++;
}

void VectorDinamic::add_at(int index, TElem elem)
{
    for(int i = nr_elemente; i > index; i--)
        swap(elemente[i], elemente[i-1]);
    elemente[index] == elem;
    nr_elemente++;
}

void VectorDinamic::sterge_element(int index)
{
    if (index < 0 || index >= nr_elemente)
        throw invalid_argument("Pozitie invalida.");
    for (int j = index; j < nr_elemente - 1; j++)
    {
        TElem aux;
        aux = elemente[j+1];
        elemente[j+1] = elemente[j];
        elemente[j] = aux;
    }
    nr_elemente--;
}

void VectorDinamic::update(int index, TElem elem)
{
    elemente[index] = elem;
}

int VectorDinamic::size()
{
    return capacitate;
}
int VectorDinamic::get_nr_elemente()
{
    return nr_elemente;
}

TElem VectorDinamic::get_at_index(int index)
{
    return elemente[index];
}

int VectorDinamic::search(TElem elem)
{
    for (int i = 0; i < nr_elemente; i++)
        if (elemente[i] == elem)
            return i;
}