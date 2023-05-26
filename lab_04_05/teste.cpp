#include "teste.h"
#include "Collection.h"
#include "ATM.h"
#include <iostream>
#include <cassert>


void test_collection()
{
    Collection coll;
    coll.adauga_bancnota(1,7);
    coll.adauga_bancnota(5,3);
    coll.adauga_bancnota(10,4);
    coll.adauga_bancnota(50,3);
    coll.adauga_bancnota(500,1);
    assert(coll.get_nr_elemente() == 5);
    assert(coll.get_bancnota(0) == 1);
    assert(coll.get_bancnota(1) == 5);
    assert(coll.get_bancnota(2) == 10);
    assert(coll.get_bancnota(3) == 50);
    assert(coll.get_bancnota(4) == 500);
    assert(coll.get_frecventa(0) == 7);
    assert(coll.get_frecventa(1) == 3);
    assert(coll.get_frecventa(2) == 4);
    assert(coll.get_frecventa(3) == 3);
    assert(coll.get_frecventa(4) == 1);
    coll.schimbare_frecventa(1,14);
    assert(coll.get_bancnota(0) == 1);
    assert(coll.get_frecventa(0) == 14);
    coll.sterge_bancnota(500);
    assert(coll.get_nr_elemente() == 4);
}


void test_tranzaction()
{
    Tranzaction t;
    t = Tranzaction(1,150);
    assert(t.get_suma() == 150);
    t.set_suma(100);
    assert(t.get_suma() == 100);
    assert(t.get_idTranzactie() != 0);
}


void test_all()
{
    test_collection();
    test_tranzaction();

    cout<<"Testare completa - clase"<<endl;
}
