#include "Tranzaction.h"
#include "ATM.h"
#include <iostream>
#include <random>
using namespace std;

Tranzaction::Tranzaction()
{
    this->idTranzactie = rand();
    this->suma = 0;

}

Tranzaction::Tranzaction(int idTranzactie, int suma)
{
    this->idTranzactie = idTranzactie;
    this->suma = suma;

}

Tranzaction::~Tranzaction() {}

int Tranzaction::get_idTranzactie()
{
    return this->idTranzactie;
}
int Tranzaction::get_suma()
{
    return this->suma;
}

void Tranzaction::set_suma(int suma)
{
    this->suma = suma;
}


//
//bool Tranzaction::procesare(int v[])
//{
//    int suma_curenta = this->suma;
//    int bancnote[] = {500,200,100,50,20,10,5,1};
//    int index_cea_mai_mare_bancnota = 0;
//
//    while (index_cea_mai_mare_bancnota < 8 and suma_curenta < bancnote[index_cea_mai_mare_bancnota])
//            index_cea_mai_mare_bancnota++;
//
//    int bancnote_de_adaugat[1000];
//    int numar_de_bancnote_de_adaugat = -1;
//
//    while (suma_curenta !=0 and index_cea_mai_mare_bancnota < 8)
//    {
//        int nr_banc = 0;
//        if (suma_curenta >= bancnote[index_cea_mai_mare_bancnota])
//        {
//            nr_banc = suma_curenta / bancnote[index_cea_mai_mare_bancnota];
//
//        }
//    }
//
//}

//
//bool Tranzaction::procesare()
//{
//    int suma_curenta = this->suma;
//    int bancnote[] = {500, 200, 100 , 50, 20, 10, 5, 1};
//    int index_cea_mai_mare_bancnota = 0;
//
//    while (index_cea_mai_mare_bancnota < 8  and suma_curenta < bancnote[index_cea_mai_mare_bancnota])
//        index_cea_mai_mare_bancnota++;
//
//    int bancnote_de_adaugat[100] = {0};
//    int numar_de_bancnote_de_adaugat = -1;
//
//    while(suma_curenta != 0 and index_cea_mai_mare_bancnota < 8)
//    {
//        int numar_de_bancnote = 0;
//        if(suma_curenta >= bancnote[index_cea_mai_mare_bancnota])
//        {
//            numar_de_bancnote = suma_curenta / bancnote[index_cea_mai_mare_bancnota];
//
//            int bancnote_valabile_curente = this->bancnote_valabile_in_atm[index_cea_mai_mare_bancnota];
//            if(numar_de_bancnote > bancnote_valabile_curente)
//                numar_de_bancnote = bancnote_valabile_curente;
//
//            for (int j = 0; j < numar_de_bancnote; j++)
//                bancnote_de_adaugat[++numar_de_bancnote_de_adaugat] = bancnote[index_cea_mai_mare_bancnota];
//        }
//        suma_curenta = suma_curenta - numar_de_bancnote * bancnote[index_cea_mai_mare_bancnota];
//        index_cea_mai_mare_bancnota++;
//    }
//
//    if (suma_curenta != 0 and index_cea_mai_mare_bancnota <= 8)
//    {
//        cout<<"ATM-ul nu are destule bacnote pentru aceasta retragere."<<endl;
//        return false;
//    }
//    else
//    {
//        for (int i = 0; i <= numar_de_bancnote_de_adaugat; i++)
//            this->bancnote_retrase.add_bancnota(bancnote_de_adaugat[i]);
//        return true;
//    }
//
//}
//
//
//void Tranzaction::copie_bancnote_retrase(int v[8])
//{
//    for (int i = 0;i< 8; i++)
//    {
//        v[i]=bancnote_retrase.get_frecventa(i);
//    }
//}
//void Tranzaction::afisare_banc_retrase()
//{
//    for (int i = 0; i < 8; i++)
//    {
//        cout<<bancnote_retrase;
//    }
//}

Tranzaction& Tranzaction::operator=(const Tranzaction& tranz)
{
    this->idTranzactie = tranz.idTranzactie;
    this->suma = tranz.suma;
 //   this->bancnote_retrase = tranz.bancnote_retrase;
    return *this;
}

ostream& operator<<(ostream &os, const Tranzaction &tranz)
{
    os<<"Id-ul tranzactiei: "<<tranz.idTranzactie<<endl;
    os<<"Suma tranzactiei: "<<tranz.suma<<endl;
   //os<<"Urmatoarele bancnote efectueaza plata: "<<endl;
   // os<<tranz.bancnote_retrase;
    return os;
}
