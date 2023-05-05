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

    VectorDinamic& add_el_frecv(TElem el, int frecv_noua);
    VectorDinamic& add_el(TElem el);
    int get_capacitate();
    TElem sterge(TElem el, int frecv_noua);
    int size ();
    TElem get_elem(int index);
    int get_frecv(TElem el);
    TElem update(TElem el, int frecv_noua);

};

