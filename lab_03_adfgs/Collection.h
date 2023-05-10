#pragma once
#include <iostream>
#include "VectorDinamic.h"
using namespace std;
typedef int TElem;

class Collection
{
private:
    VectorDinamic vector;
public:
    Collection(int capacity);
    ~Collection();

    int get_capacitate();
    int get_bancnota(int index);
    int get_frecventa(TElem element);
    int get_index(TElem element);
    void set_frecventa(int index, int fr);
    void add_bancnota(TElem e);
    void add_bancnota_frecv(TElem e, int frecventa);
    bool delete_bancnota(TElem e);
    int suma_bancnote_total();
    void sterge(TElem element, int fr);
    int size();
};