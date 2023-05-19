#include "test.h"
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
    vd1.adaugare_element_cu_frecventa(1,7);
    vd1.adaugare_element_cu_frecventa(5,4);
    vd1.adaugare_element_cu_frecventa(10,4);
    vd1.adaugare_element_cu_frecventa(100,1);
    assert(vd1.get_at_index(0) == 1);
    assert(vd1.get_at_index(1) == 5);
    assert(vd1.get_at_index(2) == 10);
    assert(vd1.get_at_index(3) == 100);
    assert(vd1.get_at_frecventa(0) == 7);
    assert(vd1.get_at_frecventa(1) == 4);
    assert(vd1.get_at_frecventa(2) == 4);
    assert(vd1.get_at_frecventa(3) == 1);
    assert(vd1.get_index_of(1) == 0);
    assert(vd1.get_index_of(5) == 1);
    assert(vd1.get_index_of(10) == 2);
    assert(vd1.get_index_of(100) == 3);
    assert(vd1.get_frecventa_of(1) == 7);
    assert(vd1.get_frecventa_of(5) == 4);
    assert(vd1.get_frecventa_of(10) == 4);
    assert(vd1.get_frecventa_of(100) == 1);
    assert(vd1.get_capacitate() == 10);
    assert(vd1.get_nr_elemente() == 4);
    VectorDinamic vd2(vd1);
    vd1.sterge_element(10);
    assert(vd1.get_at_index(0) == 1);
    assert(vd1.get_at_index(1) == 5);
    assert(vd1.get_at_index(2) == 100);
    assert(vd1.get_nr_elemente() == 3);
    assert(vd2.get_at_index(0) == 1);
    assert(vd2.get_at_index(1) == 5);
    assert(vd2.get_at_index(2) == 10);
    assert(vd2.get_at_index(3) == 100);
    assert(vd2.get_at_frecventa(0) == 7);
    assert(vd2.get_at_frecventa(1) == 4);
    assert(vd2.get_at_frecventa(2) == 4);
    assert(vd2.get_at_frecventa(3) == 1);
    vd2.sterge_element(1);
    vd2.sterge_element(100);
    assert(vd2.get_at_index(0) == 5);
    assert(vd2.get_at_index(1) == 10);
    assert(vd2.get_at_frecventa(0) == 4);
    assert(vd2.get_at_frecventa(1) == 4);
    assert(vd2.get_nr_elemente() == 2);
    VectorDinamic vd3(10);
    vd3.adaugare_element_cu_frecventa(1,7);
    vd3.adaugare_element_cu_frecventa(5,4);
    vd3.adaugare_element_cu_frecventa(10,4);
    vd3.adaugare_element_cu_frecventa(100,2);
    int v1[101] = {0}, v2[101] = {0}, suma = 256, k = 0;
    assert(vd3.tranzactie(k,suma,v1,v2) == 0);
    assert(v1[0] == 100);
    assert(v2[0] == 2);
    assert(suma == 0);
    assert(k == 4);
    VectorDinamic vd4(10);
    vd4.adaugare_element_cu_frecventa(1,7);
    vd4.adaugare_element_cu_frecventa(5,4);
    vd4.adaugare_element_cu_frecventa(10,4);
    vd4.adaugare_element_cu_frecventa(100,2);
    v1[101] = {0}; v2[101] = {0}; suma = 500; k = 0;
    assert(vd4.tranzactie(k,suma,v1,v2) == -1);
}

void test_collection()
{
    Collection coll(10);

    coll.adauga_bancnota(1,4);
    coll.adauga_bancnota(5,3);
    coll.adauga_bancnota(10,6);
    coll.adauga_bancnota(20,1);
    coll.adauga_bancnota(50,3);
    assert(coll.get_nr_elemente() == 5);
    assert(coll.get_capacitate() == 10);
    assert(coll.get_bancnota(0) == 1);
    assert(coll.get_bancnota(1) == 5);
    assert(coll.get_bancnota(2) == 10);
    assert(coll.get_bancnota(3) == 20);
    assert(coll.get_bancnota(4) == 50);
    assert(coll.get_frecventa(0) == 4);
    assert(coll.get_frecventa(1) == 3);
    assert(coll.get_frecventa(2) == 6);
    assert(coll.get_frecventa(3) == 1);
    assert(coll.get_frecventa(4) == 3);
    Collection coll2(coll);
    coll.schimbare_frecventa(5,5);
    assert(coll.get_frecventa(1) == 5);
    coll.sterge_bancnota(20);
    assert(coll.get_bancnota(3) == 50);
    int v1[101] = {0}, v2[101] = {0}, suma = 247, k = 0;
    assert(coll2.tranzactie(k,suma,v1,v2) == 0);
    v1[101] = {0}; v2[101] = {0}; suma = 5000; k = 0;
    assert(coll2.tranzactie(k,suma,v1,v2) == -1);
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
    ATM atm(10);
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
    ATM atm2(10);
    atm2.adaugare_bancnote_bancomate(1,7);
    atm2.adaugare_bancnote_bancomate(5,21);
    atm2.adaugare_bancnote_bancomate(10,7);
    atm2.schimbare_or_stergere_frecv(5,0);
    atm2.schimbare_or_stergere_frecv(10,3);
    Collection copy2 = atm2.get_bancnote_curente();
    assert (copy2.get_bancnota(0) == 1);
    assert (copy2.get_bancnota(1) == 10);
    assert (copy2.get_frecventa(0) == 7);
    assert (copy2.get_frecventa(1) == 3);

}

void test_all()
{
    test_vector_dinamic(); // verificat
    test_collection(); // verificat
    test_tranzaction(); // verificat
    test_atm(); // verificat

    cout<<"Testare completa."<<endl;
}