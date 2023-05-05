#include "tests.h"
#include "VectorDinamic.h"
#include "Collection.h"
#include "Tranzaction.h"
#include "ATM.h"

#include <iostream>
#include <cassert>
using namespace std;


void test_tranzactie()
{
    Tranzaction t;
    t = Tranzaction();

    t.set_suma(100);
    assert(t.get_suma() == 100);
    assert(t.get_idTranzactie() != 0);
}

void test_collection()
{
    Collection ch;
    ch = Collection();
    ch.add_bancnota_frecv(5,20);
    ch.add_bancnota(5);
    assert(ch.suma_bancnote_total() == 100);
    assert(ch.get_frecventa(1) == 20);
    assert(ch.get_bancnota(1) == 5);
    assert(ch.get_capacitate() == 1);

//    assert(ch.get_frecventa(1) == 1);
//    assert(ch.get_bancnota(1) == 10);
}

void test_vector_dinamic()
{
    VectorDinamic vd = VectorDinamic(2);

    vd.add_el_frecv(10, 50);
    vd.add_el_frecv(5, 20);
    vd.add_el(20);
    assert (vd.size() == 3);

    assert(vd.get_elem(1) == 5);
    assert(vd.get_elem(2) == 10);
    assert(vd.get_elem(3) == 20);

    assert(vd.get_frecv(10) == 50);
    assert(vd.get_frecv(5) == 20);
    assert(vd.get_frecv(20) == 1);
}



void test_all()
{
    test_vector_dinamic();
    test_collection();

    cout<<"Testare completa!"<<endl;
}