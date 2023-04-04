#include <iostream>
#include "tests.h"
#include "Tranzactie.h"
#include "ATM.h"

using namespace std;

void print_meniu()
{
    cout << "1. Adaugare bancnote in ATM" << '\n';
    cout << "2. Efectuarea tranzactie" << '\n';
    cout << "0. Iesire" << '\n';
}

int main()
{
    ATM* atm = new ATM;
    int alegere = 0;
    while (true)
    {
        print_meniu();
        cin >> alegere;
        switch (alegere)
        {
            case 1: // 1. Adaugare bancnote in ATM
            {

                cout << "Cate bancnote doriti sa adaugati?\n" << "<";
                int numar_bancnote_de_adaugat = 0;
                cin >> numar_bancnote_de_adaugat;
                while (numar_bancnote_de_adaugat)
                {
                    cout << "Introduceti bancnota:\n" << "<";
                    int bancnota_de_adaugat;
                    cin >> bancnota_de_adaugat;
                    atm->adauga_bancnota_in_atm(bancnota_de_adaugat);
                    numar_bancnote_de_adaugat--;
                }
                cout << "Beep boop beep bancnote adaugate!\n";
                break;
            }

            case 2:
            {
                // 2. Efectuarea tranzactie
                cout << "Introduceti suma tranzactiei:\n" << "<";
                int suma = 0;
                cin >> suma;
                Tranzactie* tranzactie_de_adaugat = atm->creare_instanta_tranzactie(suma);

                if (tranzactie_de_adaugat->tranzactie_indeplinita())
                {
                    cout << *tranzactie_de_adaugat;
                    cout << "Doriti sa va efectuati tranzactia? (y/n)\n" << "<";
                    char adaugare_tranzactie;
                    cin >> adaugare_tranzactie;
                    if (adaugare_tranzactie == 'y')
                    {
                        atm->adauga_tranzactie(tranzactie_de_adaugat);
                        cout << "Beep booop beeeeeep beeeeeeep tranzactie adaugata!\n";
                    }
                    else
                    {
                        delete tranzactie_de_adaugat;
                        cout << "Beep boop ;( tranzactie anulata.\n";
                    }
                }
                else
                    cout << "Beep boop ;(.\n";
                break;
            }

            case 0:
            {
                cout << "O zi buna!";
                return 0;
            }
            default:
                cout << "Optiune invalida! Va rog incercati din nou.\n";
        }
    }
}
