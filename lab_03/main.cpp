#include "tests.h"
#include "ATM.h"
#include <iostream>
using namespace std;
int main()
{
    test_all();
    ATM atm_crt;
    atm_crt.adaugare_bancnote_bancomate(1,7);
    atm_crt.adaugare_bancnote_bancomate(5,7);
    atm_crt.adaugare_bancnote_bancomate(10,4);
    atm_crt.adaugare_bancnote_bancomate(50,5);
    atm_crt.user_menu();

    return 0;
}