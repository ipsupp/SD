#include "tests.h"
#include <iostream>
using namespace std;
#include <cassert>
#include "VectorDinamic.h"
#include "Collection.h"
#include "Tranzaction.h"
#include "ATM.h"

void test_vector_dinamic()
{
    VectorDinamic vd1(10);
    vd1.push_back(1);
    vd1.push_back(5);
    vd1.push_back(10);
    vd1.push_back(100);

    assert(vd1.get_at_index(0) == 1);
    assert(vd1.get_at_index(1) == 5);
    assert(vd1.get_at_index(2) == 10);
    assert(vd1.get_at_index(3) == 100);
    assert(vd1.size() == 10);
    assert(vd1.get_nr_elemente() == 4);
    VectorDinamic vd2(vd1);
    vd1.sterge_element(2);
    assert(vd1.get_at_index(0) == 1);
    assert(vd1.get_at_index(1) == 5);
    assert(vd1.get_at_index(2) == 100);
    assert(vd1.get_nr_elemente() == 3);
    assert(vd2.get_at_index(0) == 1);
    assert(vd2.get_at_index(1) == 5);
    assert(vd2.get_at_index(2) == 10);
    assert(vd2.get_at_index(3) == 100);

}

void test_collection()
{
    Collection coll;

    coll.adauga_bancnota(1,7);
    coll.adauga_bancnota(5,3);
    coll.adauga_bancnota(50,3);
    coll.adauga_bancnota(10,120);
    assert(coll.get_nr_elemente() == 4);
    assert(coll.get_frecventa(0) == 7);
    assert(coll.get_frecventa(1) == 3);
    assert(coll.get_frecventa(2) == 3);
    assert(coll.get_frecventa(3) == 120);
    int v1[101] = {0}, v2[101] = {0}, suma = 247, k = 0;
    assert(coll.tranzactie(k,suma,v1,v2) == 0);
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

void test_atm()
{
    ATM atm;
    atm.adaugare_bancnote_bancomate(1,7);
    atm.adaugare_bancnote_bancomate(5,3);
    atm.adaugare_bancnote_bancomate(10,7);
    atm.adaugare_bancnote_bancomate(50,5);
    atm.adaugare_bancnote_bancomate(500,1);
    Collection copy = atm.get_bancnote_curente();
    assert (copy.get_bancnota(0) == 1);
    assert (copy.get_bancnota(1) == 5);
    assert (copy.get_bancnota(2) == 10);
    assert (copy.get_bancnota(3) == 50);
    assert (copy.get_bancnota(4) == 500);
    assert (copy.get_frecventa(0) == 7);
    assert (copy.get_frecventa(1) == 3);
    assert (copy.get_frecventa(2) == 7);
    assert (copy.get_frecventa(3) == 5);
    assert (copy.get_frecventa(4) == 1);
    ATM atm2;
    atm2.adaugare_bancnote_bancomate(1,7);
    atm2.adaugare_bancnote_bancomate(5,21);
    atm2.adaugare_bancnote_bancomate(10,7);
    atm2.schimbare_or_stergere_frecv(5,0);
    atm2.schimbare_or_stergere_frecv(10,3);
//    Collection copy2 = atm2.get_bancnote_curente();
//    assert (copy2.get_bancnota(0) == 1);
//    assert (copy2.get_bancnota(1) == 10);
//    assert (copy2.get_frecventa(0) == 7);
//    assert (copy2.get_frecventa(1) == 3);

}

void test_all()
{
    test_vector_dinamic(); // verificat
    test_collection(); // verificat
    test_tranzaction(); // verificat
    test_atm(); // verificat

    cout<<"Testare completa."<<endl;
}