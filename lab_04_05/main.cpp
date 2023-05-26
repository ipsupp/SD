#include <iostream>
#include "TestList.h"
#include "teste.h"
#include "ATM.h"
using namespace std;

int main()
{
    TestList t;
    t.test_size();
    t.test_push_back();
    t.test_delete_element();
    t.test_set_at();
    t.test_is_empty();
    t.test_update();
    cout<<"Testare completa - list."<<endl;
    test_all();
    ATM atm;
    atm.adaugare_bancnote_bancomate(1,6);
    atm.adaugare_bancnote_bancomate(5,6);
    atm.adaugare_bancnote_bancomate(10,4);
    atm.adaugare_bancnote_bancomate(50,3);
    atm.user_menu();
}