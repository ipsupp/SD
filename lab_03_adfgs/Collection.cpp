#include "Collection.h"
using namespace std;
Collection::Collection(int capacity)
{
    vector = VectorDinamic(capacity);
}

Collection::~Collection() {}

int Collection::get_bancnota(int index)
{
    return vector.get_elem(index);
}

int Collection::get_index(TElem element)
{
    return vector.get_index(element);
}

int Collection::get_frecventa(TElem element)
{
    return vector.get_frecv(element);
}

void Collection::sterge(TElem element, int fr)
{
    vector.sterge(element,fr);
}

int Collection::get_capacitate()
{
    return vector.get_capacitate();
}

void Collection::add_bancnota(TElem e)
{
    vector.add_el_frecv(e,1);
}

void Collection::add_bancnota_frecv(TElem e, int frecventa)
{
    vector.add_el_frecv(e,frecventa);
}
int Collection::suma_bancnote_total()
{
    int s = 0, size = vector.size();
    for (int i = 0; i < size; i++)
        s = s + vector.get_elem(i) * vector.get_frecv(vector.get_elem(i));
    return s;
}

int Collection::size()
{
    return vector.size();
}
