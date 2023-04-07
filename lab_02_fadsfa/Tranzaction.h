#pragma once
#include <iostream>
#include "Collection.h"
using namespace std;
typedef int TElem;

class Tranzaction
{

private:

    int idTranzactie;
    int suma;
   // Collection bancnote_retrase;


public:

    Tranzaction();
    Tranzaction(int idTranzactie, int suma);
    ~Tranzaction();

    int get_idTranzactie();
    int get_suma();
    void set_suma(int suma);
//    bool procesare(int v[]);
//    void afisare_banc_retrase();
//    void copie_bancnote_retrase(int v[8]);

    Tranzaction& operator= (const Tranzaction& tranz);
    friend ostream& operator<<(ostream &os, const Tranzaction &tranz);



};