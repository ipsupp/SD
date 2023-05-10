#include "tests.h"
#include "VectorDinamic.h"
#include "Collection.h"
#include "Tranzaction.h"
#include "ATM.h"

#include <iostream>
#include <cassert>
using namespace std;

void test_vector_dinamic()
{
    VectorDinamic vd(10);

    vd.add_el_frecv(5, 20);
    vd.add_el_frecv(10, 50);
    vd.add_el_frecv(20,1);

    assert (vd.size() == 3);

    assert(vd.get_elem(0) == 5);
    assert(vd.get_elem(1) == 10);
    assert(vd.get_elem(2) == 20);

    assert(vd.get_frecv(5) == 20);
    assert(vd.get_frecv(10) == 50);
    assert(vd.get_frecv(20) == 1);

    vd.sterge(10,20);
    assert(vd.get_frecv(10) == 30);
}

void test_collection()
{
    Collection ch(101);
//    ch = Collection(101);
    ch.add_bancnota_frecv(1,20);
    ch.add_bancnota(5);
    ch.add_bancnota_frecv(10,100);

    assert(ch.get_capacitate() == 101);
    assert(ch.suma_bancnote_total() == 1025);
    assert(ch.get_bancnota(0) == 1);
    assert(ch.get_frecventa(1) == 20);
    assert(ch.get_bancnota(1) == 5);
    assert(ch.get_frecventa(5) == 1);
    assert(ch.get_bancnota(2) == 10);
    assert(ch.get_frecventa(10) == 100);
}

void test_tranzactie()
{
    Tranzaction t;
    t = Tranzaction();

    t.set_suma(100);
    assert(t.get_suma() == 100);
    assert(t.get_idTranzactie() != 0);
}


void test_atm()
{
    ATM atm(101) ;

    atm.adauga_bancnote_bancomat(1,10);
    atm.adauga_bancnote_bancomat(5,5);
    atm.adauga_bancnote_bancomat(100,2);
    assert(atm.get_bancnote(10) == false);
    assert(atm.get_bancnote(100) == true);
    assert(atm.get_nr_bancnote(1) == 10);
    assert(atm.get_nr_bancnote(5) == 5);
    assert(atm.get_nr_bancnote(100) == 2);
    atm.sterge_bancnote(1,3);
    assert(atm.get_nr_bancnote(1) == 7);
    Collection copy(101);
    copy = atm.get_bancnote_valabile();
    assert(copy.get_bancnota(0) == 1);
    assert(copy.get_bancnota(1) == 5);
    assert(copy.get_bancnota(2) == 100);
    assert(copy.get_frecventa(1) == 7);
    assert(copy.get_frecventa(5) == 5);
    assert(copy.get_frecventa(100) == 2);
   //atm.tranzactie(125);




}

void test_all()
{
    test_vector_dinamic();
    test_collection();
    test_tranzactie();
    test_atm();

    cout<<"Testare completa!"<<endl;
}