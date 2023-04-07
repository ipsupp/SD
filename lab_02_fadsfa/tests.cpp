#include "Collection.h"
#include "Tranzaction.h"
#include "ATM.h"
#include <cassert>
#include <iostream>
using namespace std;
typedef int TElem;

//teste colectie

void test_add_bancnota()
{
    TElem a = 1, b = 2, c = 5;
    Collection col;
    col.add_bancnota(a);
    col.add_bancnota(b);
    col.add_bancnota(c);
    assert (col.get_bancnota(0) == a);
    assert (col.get_bancnota(1) ==c);
    assert (col.get_bancnota(1) != b);

}

void test_get_capacitate()
{
    Collection col;
    assert (col.get_capacitate() == 8);
}

void test_get_bancnota()
{
    int a = 1, b = 10, c = 5;
    Collection col;
    col.add_bancnota(a);
    col.add_bancnota(b);
    col.add_bancnota(c);
    assert(col.get_bancnota(0) == 1);
    assert(col.get_bancnota(1) == 5);
    assert(col.get_bancnota(2) == 10);
}

void test_get_frecventa()
{
    int a = 1, b = 5, c = 10;
    Collection col;
    col.add_bancnota(a);
    col.add_bancnota(b);
    col.add_bancnota(b);
    col.add_bancnota(c);
    assert(col.get_frecventa(0) == 1);
    assert(col.get_frecventa(1) == 2);
    assert(col.get_frecventa(2) == 1);
}

void test_delete_bancnota()
{
    int a = 1, b = 5, c = 10;
    Collection col;
    col.add_bancnota(a);
    col.add_bancnota(b);
    col.add_bancnota(b);
    col.add_bancnota(c);
    assert(col.get_frecventa(1) == 2);
    assert(col.get_bancnota(1) == 5);
    col.delete_bancnota(b);
    assert(col.get_frecventa(1) == 1);
    assert(col.get_bancnota(1) == 5);
}

void test_suma_bancnote_totala()
{

    int a = 1, b = 5, c = 10;
    Collection col;
    col.add_bancnota(a);
    col.add_bancnota(b);
    col.add_bancnota(b);
    col.add_bancnota(c);
    col.add_bancnota(c);
    col.add_bancnota(c);
    assert(col.suma_bancnote_total() == 41);
}

//teste tranzactie

void test_get_idTranzactie()
{
    Tranzaction t;
    assert(t.get_idTranzactie() != 0);
}

void test_get_and_set_suma()
{
    Tranzaction t;
    t.set_suma(100);
    assert(t.get_suma() == 100);
}

//teste atm

void test_adaugare_bancnote()
{
    ATM a;
    a = ATM();
    a.adauga_bancnote_bancomat(10,7);
    a.adauga_bancnote_bancomat(5,7);
    a.adauga_bancnote_bancomat(1,7);
    a.adauga_bancnote_bancomat(2,7);
    a.adauga_bancnote_bancomat(50,7);

    assert(a.get_bancnote(10) == true);
    assert(a.get_bancnote(5) == true);
    assert(a.get_bancnote(1) == true);
    assert(a.get_bancnote(50) == true);
    assert(a.get_bancnote(2) == false);

    assert(a.get_nr_bancnote(10) == 7);
    assert(a.get_nr_bancnote(5) == 7);
    assert(a.get_nr_bancnote(1) == 7);
    assert(a.get_nr_bancnote(50) == 7);
    assert(a.get_nr_bancnote(2) == -1);

}

void test_get_bancnote_valabile()
{
    int v[8] = {0};
    ATM a;
    a = ATM();
    a.adauga_bancnote_bancomat(10,7);
    a.adauga_bancnote_bancomat(5,7);
    a.adauga_bancnote_bancomat(1,7);
    a.adauga_bancnote_bancomat(2,7);
    a.adauga_bancnote_bancomat(50,7);

    a.get_bancnote_valabile(v);
//    for (int i = 0;i<8;i++)
//        cout<<i<< " "<<v[i]<<"; ";

    assert(v[0] == 7);
    assert(v[1] == 7);
    assert(v[2] == 7);
    assert(v[3] == 0);
    assert(v[4] == 7);
    assert(v[5] == 0);
    assert(v[6] == 0);
    assert(v[7] == 0);
}

void test_stergere_bancnote_atm()
{
    int v[8] = {0};
    ATM a;
    a = ATM();
    a.adauga_bancnote_bancomat(10,7);
    a.adauga_bancnote_bancomat(5,7);
    a.adauga_bancnote_bancomat(1,7);
    a.adauga_bancnote_bancomat(2,7);
    a.adauga_bancnote_bancomat(50,7);
    a.get_bancnote_valabile(v);

    assert(v[0] == 7);
    assert(v[1] == 7);

    a.sterge_bancnote(1,5);
    a.sterge_bancnote(5,2);
    a.get_bancnote_valabile(v);

    assert(v[0] == 2);
    assert(v[1] == 5);

}

void test_all()
{
    cout<<"Testarea incepe..."<<endl;

    test_add_bancnota();
    test_get_capacitate();
    test_get_bancnota();
    test_get_frecventa();
    test_delete_bancnota();
    test_suma_bancnote_totala();

    test_get_idTranzactie();
    test_get_and_set_suma();

    test_adaugare_bancnote();
    test_get_bancnote_valabile();
    test_stergere_bancnote_atm();

    cout<<"Testare completa!"<<endl;
}
