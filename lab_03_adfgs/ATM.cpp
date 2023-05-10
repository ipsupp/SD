#include "ATM.h"
#include <iostream>
using namespace std;

ATM::ATM(int capacity): bancnote_valabile(Collection(capacity)), nr_tranz(0)
{
    bancnote_valabile = Collection(capacity);
    nr_tranz = 0;
}

ATM::~ATM() {}

void ATM::adauga_bancnote_bancomat(TElem element, int q)
{
    bancnote_valabile.add_bancnota_frecv(element,q);
}

void ATM::afisare_bancnote_valabile()
{
    int a = bancnote_valabile.get_capacitate();
    for (int i = 0 ; i < a ; i++)
        if (bancnote_valabile.get_frecventa(bancnote_valabile.get_bancnota(i)) != 0)
            cout<<bancnote_valabile.get_bancnota(i)<< " * "<<bancnote_valabile.get_frecventa(bancnote_valabile.get_bancnota(i))<<endl;
}

int ATM::get_nr_bancnote(int x)
{
    int a = bancnote_valabile.get_capacitate();
    for (int i = 0 ; i < a ; i++)
    {
        int banc = bancnote_valabile.get_bancnota(i);
        int freq = bancnote_valabile.get_frecventa(banc);
        if (freq != 0 and banc == x)
            return freq;

    }
}

bool ATM::get_bancnote(int x)
{
    int a = bancnote_valabile.get_capacitate();
    for (int i = 0 ; i < a ; i++)
    {
        int banc = bancnote_valabile.get_bancnota(i);
        int freq = bancnote_valabile.get_frecventa(banc);
        if (freq != 0 and banc == x)
            return true;
    }
    return false;
}

void ATM::sterge_bancnote(int x, int q)
{
    int a = bancnote_valabile.get_capacitate();
    for (int i = 0 ; i < a ; i++)
    {
        int banc = bancnote_valabile.get_bancnota(i);
        int freq = bancnote_valabile.get_frecventa(banc);
        if (freq != 0 and banc == x)
            bancnote_valabile.sterge(x,q);

    }
}

Collection ATM::get_bancnote_valabile()
{
    int a = bancnote_valabile.size();
    Collection copy(bancnote_valabile.get_capacitate());

    for (int i = 0 ; i < a ; i++)
    {
        int banc = bancnote_valabile.get_bancnota(i);
        int freq = bancnote_valabile.get_frecventa(banc);
        copy.add_bancnota_frecv(banc,freq);
    }
    return copy;
}

void ATM::tranzactie(int suma)
{
    Tranzaction t;
    t.set_suma(suma);
    Collection banc_val = get_bancnote_valabile();
    int index_cea_mai_mare_bancnota = 0;
    int minn = 0, suma_curenta = suma;
    int a = banc_val.get_capacitate();
    int k = 0;
    for (int i = 0; i < a; i++)
    {
        if (banc_val.get_bancnota(i) > minn)
        {
            minn = banc_val.get_bancnota(i);
            index_cea_mai_mare_bancnota = i;
        }
    }
    int vector_bancnote[101] = {0};
    int vector_frecventa[101] = {0};

    while (index_cea_mai_mare_bancnota >= 0 and suma_curenta != 0)
    {
        int nr_banc = 0;
        int banc = 0, freq = 0;
        banc = banc_val.get_bancnota(index_cea_mai_mare_bancnota);
        freq = banc_val.get_frecventa(index_cea_mai_mare_bancnota);
        if (suma_curenta >= banc)
        {
            nr_banc = suma_curenta / banc;

            if (freq >= nr_banc and banc != 0)
            {
                vector_frecventa[index_cea_mai_mare_bancnota] = nr_banc;
                vector_bancnote[index_cea_mai_mare_bancnota] = banc;
                k++;
            }
        }

        suma_curenta  = suma_curenta - banc * nr_banc;
        banc_val.sterge(banc,freq);
        for (int i = 0; i < a; i++)
            if (banc_val.get_bancnota(i) > minn and banc_val.get_frecventa(banc_val.get_bancnota(i)) != 0)
            {
                minn = banc_val.get_bancnota(i);
                index_cea_mai_mare_bancnota = i;
            }
    }
    if (suma_curenta != 0 and index_cea_mai_mare_bancnota < 0)
        cout<<"ATM-ul nu are destule bancnote."<<endl;
    else if (suma_curenta == 0)
    {
        cout<<"Tranzactia va fi efectuata cu urmatoarele bancnote:"<< endl;
        for (int i = 0; i < k; i++)
            if (vector_frecventa[i] != 0)
                cout<<vector_bancnote[i]<<" * " <<vector_frecventa[i]<<" ; ";
        cout << "Confirmati? Y/N" << endl;
        char msg;
        cin >> msg;
        if (msg == 'Y')
        {
            for (int i = 0; i < k; i++)
                if (vector_frecventa[i] != 0)
                    sterge_bancnote(vector_bancnote[i], vector_frecventa[i]);

            adaugare_tranzactie(t);
            cout << "Tranzactie completa." << endl;
        }
        else cout << "Tranzactie anulata." << endl;

    }
}

//{
//    Tranzaction tranz;
//    tranz.set_suma(suma);
//    Collection banc_val(101);
//    banc_val = get_bancnote_valabile();
//    int index_cea_mai_mare_bancnota = 0;
//    int minn = 0, suma_curenta = suma ;
//    int a = bancnote_valabile.get_capacitate();
//    for (int i = 0; i < a; i++)
//        if (banc_val.get_bancnota(i)> minn)
//        {
//            minn = banc_val.get_bancnota(i);
//            index_cea_mai_mare_bancnota = i;
//        }
//
//    int vector_bancnote[101] = {0};
//    int vector_frecventa[101] = {0};
//    while (index_cea_mai_mare_bancnota >=0 and suma != 0)
//    {
//        int nr_banc, ok = 0;
//        int banc = 0, freq = 0;
//        banc = banc_val.get_bancnota(index_cea_mai_mare_bancnota);
//        freq = banc_val.get_frecventa(a);
//        if (suma_curenta >= a)
//        {
//
//            nr_banc = suma_curenta / banc;
//            if (freq >= nr_banc and banc != 0)
//            {
//                vector_frecventa[index_cea_mai_mare_bancnota] = nr_banc;
//                vector_bancnote[index_cea_mai_mare_bancnota] = banc;
//                ok = 1;
//            }
//        }
//        if (ok == 1)
//            suma_curenta = suma_curenta - banc * nr_banc;
//        int minn = 0;
//        for (int i = 0; i < a; i++)
//            if (banc_val.get_bancnota(i) > minn and banc_val.get_bancnota(i) < banc_val.get_bancnota(index_cea_mai_mare_bancnota))
//            {
//                minn = banc_val.get_bancnota(i);
//                index_cea_mai_mare_bancnota = i;
//            }
//    }
//    if (suma_curenta !=0 and index_cea_mai_mare_bancnota < 0)
//        cout<<"ATM-ul nu are destule bancnote."<<endl;
//    else if(suma_curenta == 0)
//    {
//        cout << "Tranzactia va fi efectuata cu urmatoarele bancnote:" << endl;
//        for (int i = 0; i < 8; i++)
//            if (vector_frecventa[i] != 0)
//                cout << vector_bancnote[i] << " * " << vector_frecventa[i] << " ; ";
//
//        cout << "Confirmati? Y/N" << endl;
//        char msg;
//        cin >> msg;
//        if (msg == 'Y')
//        {
//            for (int i = 0; i < a; i++)
//                if (vector_frecventa[i] != 0)
//                    sterge_bancnote(vector_bancnote[i], vector_frecventa[i]);
//            adaugare_tranzactie(tranz);
//            cout << "Tranzactie completa." << endl;
//        }
//        else cout << "Tranzactie anulata.";
//    }
//}

void ATM::adaugare_tranzactie(Tranzaction &tranz_de_adaugat)
{
    tranzactii[nr_tranz] = tranz_de_adaugat;
}