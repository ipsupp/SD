#include "tests.h"
#include "ATM.h"
#include <iostream>
using namespace std;

void option_meniu()
{
    cout<<"1. Adauga bancnote in ATM."<<endl;
    cout<<"2. Retragere numerar."<<endl;
    cout<<"3. Afisare bancnote."<<endl;
    cout<<"x. Iesire"<<endl;
}

int main()
{
    //test_all();
    ATM atm;
    atm = ATM();

    int ok = 1;
    while (ok == 1)
    {
        option_meniu();
        char option;
        cout<<"Alegeti optiunea dorita: "<<endl;
        cin>>option;
        switch (option)
        {
            case '1':
            {
                int x,q;
                cout<<"Ce bancnota adaugati?"<<endl;
                cin>>x;
                cout<<"Cate bancnote adaugati?"<<endl;
                cin>>q;
                atm.adauga_bancnote_bancomat(x,q);
                break;
            }
            case '2':
            {
                int suma;
                cout<<"Suma pe care o retrageti: "<<endl;
                cin>>suma;
                atm.tranzactie(suma);
                break;
            }
            case '3':
            {
                atm.afisare_bancnote_valabile();
                break;
            }
            case 'x':
            {
                ok = 0;
                break;
            }

            default:
            {
                cout<<"Optiune invalida!"<<endl;
                break;
            }
        }
    }
}