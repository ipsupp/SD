#include "ATM.h"

ATM::ATM(): bancnote_in_atm(Collection())
{
    nr_tranz = 0;
}

ATM::~ATM() {}

int ATM::main_menu()
{
    cout<<"1. Adauga bancnote in ATM."<<endl;
    cout<<"2. Retragere numerar."<<endl;
    cout<<"3. Afisare bancnote."<<endl;
    cout<<"4. Afisare tranzactii."<<endl;
    cout<<"0. Iesire"<<endl;
    int optiune = -1;
    cout<<"Optiune dorita?"<<endl;
    cin>>optiune;
    return optiune;
}

void ATM::user_menu()
{
    int ok = 1;
    int optiune;
    while (ok == 1)
    {
        optiune = main_menu();
        switch (optiune)
        {
            case 1:
            {
                int banc, freq;
                cout<<"Ce bancnota adaugati?"<<endl;
                cin>>banc;
                cout<<"Cate bancnote adaugati?"<<endl;
                cin>>freq;
                adaugare_bancnote_bancomate(banc,freq);
                break;
            }
            case 2:
            {
                int suma;
                cout<<"Suma pe care o retrageti: "<<endl;
                cin>>suma;
                tranzactie(suma);
                break;
            }
            case 3:
            {
                afisare_bancnote();
                break;
            }
            case 4:
            {
                afisare_tranzactii();
                break;
            }
            case 0:
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

void ATM::adaugare_bancnote_bancomate(TElem elem, int frecv)
{
    bancnote_in_atm.adauga_bancnota(elem,frecv);
}

void ATM::schimbare_or_stergere_frecv(TElem elem, int frecv)
{
    bancnote_in_atm.schimbare_frecventa(elem,frecv);
}

Collection ATM::get_bancnote_curente()
{
    int size = bancnote_in_atm.get_nr_elemente();
    Collection copy;
    for (int i = 0; i < size; i++)
    {
        int banc = bancnote_in_atm.get_bancnota(i);
        int freq = bancnote_in_atm.get_frecventa(i);
        copy.adauga_bancnota(banc,freq);
    }
    return copy;
}

void ATM::tranzactie(int suma)
{
    int copie_suma = suma, nr_elemente = 0, v_banc[101] = {0}, v_freq[101] = {0};
//    Collection copy = get_bancnote_curente();
    int rezultat = bancnote_in_atm.tranzactie(nr_elemente,copie_suma,v_banc,v_freq);
    if (rezultat == -1)
        cout<<"ATM-ul nu are destule bancnote pentru a finaliza tranzactia."<<endl;
    else if (rezultat == 0 )
    {
        cout<<"Tranzactia va fi efectuata cu urmatoarele bancnote:"<<endl;
        for (int i = 0; i < nr_elemente; i++)
            cout<<v_banc[i]<<" * "<<v_freq[i]<<endl;
        cout<<"Confirmati? Y/N"<<endl;
        char msg;
        cin>>msg;
        if (msg == 'Y')
        {
            for (int i = 0; i < nr_elemente; i++)
            {
                int size = bancnote_in_atm.get_nr_elemente();
                for (int j = 0; j < size; j++)
                {
                    if (v_banc[i] == bancnote_in_atm.get_bancnota(j))
                    {
                        int frecv = bancnote_in_atm.get_frecventa(j);
                        if (frecv > v_freq[i])
                             bancnote_in_atm.schimbare_frecventa(v_banc[i], frecv - v_freq[i]);
                        else if (frecv == v_freq[i])
                            bancnote_in_atm.sterge_bancnota(j);
                    }
                }
            }
            Tranzaction aux;
            aux.set_suma(suma);
            tranzactii[nr_tranz] = aux;
            nr_tranz++;
        }
        else if (msg == 'N')
            cout << "Tranzactie anulata." << endl;
        else cout<<"Input invalid."<<endl;
    }
}

void ATM::afisare_bancnote()
{
    bancnote_in_atm.afisare_bancnote();
}

void ATM::afisare_tranzactii()
{
    if (nr_tranz != 0)
    {
        for (int i = 0; i < nr_tranz; i++)
        {
            cout << i + 1 << ". ";
            tranzactii[i].afisare_tranz();
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    else if (nr_tranz == 0)
        cout<<"Nu exista tranzactii."<<endl;
}