#include "Collection.h"
#include <cassert>
#include <iostream>
using namespace std;
typedef int TElem;

void test_add_bancnota()
{
    TElem a = 1, b = 2, c = 5;
    Collection col;
    assert (col.add_bancnota(a) == true);
    assert (col.add_bancnota(b) == false);
    assert (col.add_bancnota(c) == true);

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

void test_all()
{
    cout<<"Testarea incepe..."<<endl;

    test_add_bancnota();
    test_get_capacitate();
    test_get_bancnota();
    test_get_frecventa();
    test_delete_bancnota();
    test_suma_bancnote_totala();

    cout<<"Testare completa!"<<endl;
}
