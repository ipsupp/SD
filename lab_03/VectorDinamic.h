#pragma once
typedef int TElem;
class VectorDinamic
{
private:
    int capacitate;
    int nr_elemente;
    TElem* elemente;
    int* frecventa;
    void resize();
public:
    VectorDinamic();
    VectorDinamic(int capacitate);
    VectorDinamic(const VectorDinamic &vd);
    ~VectorDinamic();

    void adaugare_element_cu_frecventa(TElem elem, int frecv);
    void sterge_element(TElem elem);
    void schimbare_frecventa(TElem elem, int frecv);
    int tranzactie (int &nr_elems_vectori, int &suma, int v_banc[], int v_fr[]);

    TElem get_at_index(int index); // ret element
    int get_at_frecventa(int index);
    int get_index_of(int elem); // ret index
    int get_frecventa_of(TElem elem);
    int get_capacitate();
    int get_nr_elemente();


    //folosite doar pentru testare
    void afisare_element(int index);
    void afisare_vector();

};

