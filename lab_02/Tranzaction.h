#pragma once;
#include <iostream>
#include "Collection.h"
using namespace std;
typedef int TElem;

class Tranzaction
{

private:

    int idTranzactie;
    int suma;
    Collection bani;


public:

    Tranzaction();
    Tranzaction(int idTranzactie, int suma, Collection &banc);
    ~Tranzaction();

    int get_idTranzactie();
    int get_suma();

    Tranzaction& operator= (const Tranzaction& tranz);
    friend ostream& operator<<(ostream &os, const Tranzaction &tranz);



};