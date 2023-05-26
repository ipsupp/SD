#pragma once
#include <iostream>
#include "Collection.h"
using namespace std;

class Tranzaction
{

private:

    int idTranzactie;
    int suma;

public:

    Tranzaction();
    Tranzaction(int idTranzactie, int suma);
    ~Tranzaction();

    int get_idTranzactie();
    int get_suma();
    void set_suma(int suma);
    void afisare_tranz();
};