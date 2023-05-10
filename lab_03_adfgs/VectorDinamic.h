#pragma once

typedef int TElem;

class VectorDinamic
{
private:
    int capacity;
    int nrElems;
    TElem* elems;
    int* frecv ;
    void resize();
public:
    VectorDinamic();
    VectorDinamic(int capacitate);
    ~VectorDinamic();
    void afisare();
    void add_el_frecv(TElem el, int frecv_noua);
    void add_el(TElem el);
    int get_capacitate();
    int get_index(TElem element);
    void set_capacitate(int capacitate);
    int size ();
    TElem get_elem(int index);
    int get_frecv(TElem el);
    void sterge(TElem el, int frecv_noua);
};

