#include "ATM.h"
#include <iostream>
#include <cstring>
using namespace std;

ATM::ATM()
{
    this->nr_tranz = 0;
}

ATM::~ATM() {}

void ATM::adauga_bancnote_bancomat(int x, int q)
{
    for (int i = 0; i < q; i ++)
        bancnote_valabile.add_bancnota(x);
}

void ATM::sterge_bancnote(int x, int q)
{
    int k,index;
    if (x == 500)
        index = 7;
    if (x == 200)
        index = 6;
    if (x == 100)
        index = 5;
    if (x == 50)
        index = 4;
    if (x == 20)
        index = 3;
    if (x == 10)
        index = 2;
    if (x == 5)
        index = 1;
    if (x == 1)
        index = 0;
    k = bancnote_valabile.get_frecventa(index) - q;
    bancnote_valabile.set_frecventa(index, k);
}

bool ATM::get_bancnote(int x)
{
    if (x == 500 or x == 200 or x == 100 or x == 50 or x == 20 or x == 10 or x == 5 or x == 1)
        return true;
    return false;
}


int ATM::get_nr_bancnote(int x)
{
    if (x == 500 and bancnote_valabile.get_frecventa(7) !=0)
        return bancnote_valabile.get_frecventa(7);
    if (x == 200 and bancnote_valabile.get_frecventa(6) !=0)
        return bancnote_valabile.get_frecventa(6);
    if (x == 100 and bancnote_valabile.get_frecventa(5) !=0)
        return bancnote_valabile.get_frecventa(5);
    if (x == 50 and bancnote_valabile.get_frecventa(4) !=0)
        return bancnote_valabile.get_frecventa(4);
    if (x == 20 and bancnote_valabile.get_frecventa(3) !=0)
        return bancnote_valabile.get_frecventa(3);
    if (x == 10 and bancnote_valabile.get_frecventa(2) !=0)
        return bancnote_valabile.get_frecventa(2);
    if (x == 5 and bancnote_valabile.get_frecventa(1) !=0)
        return bancnote_valabile.get_frecventa(1);
    if (x == 1 and bancnote_valabile.get_frecventa(0) !=0)
        return bancnote_valabile.get_frecventa(0);
    return -1;
}


// v[8] = {1, 5, 10, 20, 50, 100, 200, 500}
// index:  0  1  2   3   4   5    6    7
void ATM::get_bancnote_valabile(int v[8])
{
    for (int i=0; i <  this->bancnote_valabile.get_capacitate();i++)
    {
        int current_element = this->bancnote_valabile.get_bancnota(i);
        int frecv = this->bancnote_valabile.get_frecventa(i);
        if (current_element == 1)
            v[0] = frecv;
        if (current_element == 5)
            v[1] = frecv;
        if (current_element == 10)
            v[2] = frecv;
        if (current_element == 20)
            v[3] = frecv;
        if (current_element == 50)
            v[4] = frecv;
        if (current_element == 100)
            v[5] = frecv;
        if (current_element == 200)
            v[6] = frecv;
        if (current_element == 500)
            v[7] = frecv;
    }
}

void ATM::adaugare_tranzactie(Tranzaction &tranz_de_adaugat)
{
    this->tranzactii[this->nr_tranz++] = tranz_de_adaugat;
}

void ATM::tranzactie(int suma)
{

    Tranzaction tranz;
    tranz.set_suma(suma);
    int vector_bancnote[8] = {0};
    int vector_frecventa[8] = {0};
    int bancnote[] = {1, 5,10,20,50,100,200,500};
    int bancnote_din_atm[8];
    get_bancnote_valabile(bancnote_din_atm);

//    for (int i=0; i<8;i++)
//        cout<<bancnote_din_atm[i]<<" ";
//    cout<<endl;
    int suma_curenta = tranz.get_suma();
    int index_cea_mai_mare_bancnota = 7;

    while (index_cea_mai_mare_bancnota >=0 and suma != 0)
    {
        int nr_banc, ok = 0;
        if (suma_curenta >= bancnote[index_cea_mai_mare_bancnota])
        {
            nr_banc = suma_curenta / bancnote[index_cea_mai_mare_bancnota];
            if (bancnote_din_atm[index_cea_mai_mare_bancnota] >= nr_banc)
            {
                vector_frecventa[index_cea_mai_mare_bancnota] = nr_banc;
                vector_bancnote[index_cea_mai_mare_bancnota] = bancnote[index_cea_mai_mare_bancnota];
                ok = 1;
            }
        }
        if (ok == 1)
            suma_curenta = suma_curenta - bancnote[index_cea_mai_mare_bancnota] * nr_banc;
        index_cea_mai_mare_bancnota--;
    }

    if (suma_curenta != 0 and index_cea_mai_mare_bancnota < 0)
    {
        cout << "ATM-ul nu are destule bancnote."<<endl;
    }
    else if (suma_curenta == 0)
    {
        cout << "Tranzactia va fi efectuata cu urmatoarele bancnote:" << endl;
        for (int i = 0; i < 8; i++)
            if (vector_frecventa[i] != 0)
                cout << vector_bancnote[i] << " * " << vector_frecventa[i] << " ; ";

        cout << "Confirmati? Y/N" << endl;
        char a;
        cin >> a;
        if (a == 'Y')
        {
            for (int i = 0; i < 8; i++)
                if (vector_frecventa[i] != 0)
                    sterge_bancnote(vector_bancnote[i], vector_frecventa[i]);
            adaugare_tranzactie(tranz);
            cout << "Tranzactie completa." << endl;
        }
        else cout << "Tranzactie anulata.";
    }

}

void ATM::afisare_bancnote_valabile()
{
    for (int i = 0; i < 8; i++)
        if (bancnote_valabile.get_frecventa(i) != 0)
            cout<<bancnote_valabile.get_bancnota(i)<<" * "<<bancnote_valabile.get_frecventa(i)<<" ; ";
    cout<<endl;
}