#include "Collection.h"
using namespace std;
Collection::Collection()
{}

Collection::~Collection() {}

int Collection::get_bancnota(int index)
{
    return vector.get_elem(index);
}

int Collection::get_frecventa(int index)
{
    return vector.get_frecv(index);
}

void Collection::set_frecventa(int index, int fr)
{
    vector.add_el_frecv(vector.get_elem(index),fr);
}

int Collection::get_capacitate()
{
    return vector.get_capacitate();
}

void Collection::add_bancnota(TElem e)
{
    vector.add_el(e);
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

