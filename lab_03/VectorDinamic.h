#pragma once
typedef int TElem;
class VectorDinamic
{
private:
    int capacitate;
    int nr_elemente;
    TElem* elemente;
    void resize();
public:
    VectorDinamic();
    VectorDinamic(int capacitate);
    VectorDinamic(const VectorDinamic &vd);
    ~VectorDinamic();

    int search(TElem elem);
    void push_back(TElem elem);
    void add_at(int index, TElem elem);
    void sterge_element(int index);
    void update(int index, TElem elem);
//    int tranzactie (int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[]);
    TElem get_at_index(int index); // ret element
    int size();
    int get_nr_elemente();

};
