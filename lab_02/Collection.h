#pragma once
#include <iostream>
using namespace std;
typedef int TElem;

class Collection
{

private:

    TElem bancnote[8];
    int frecv[8];
    int capacitate;

public:
    Collection();
    ~Collection();

    int get_capacitate();
    int get_bancnota(int index);
    int get_frecventa(int index);
    bool add_bancnota(TElem &b);
    bool delete_bancnota(TElem &b);
    int suma_bancnote_total();
    Collection get_colectie();

    Collection& operator=(const Collection &col);
    friend ostream& operator<<(ostream &os, const Collection &col);

};