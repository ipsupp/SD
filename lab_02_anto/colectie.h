#include <fstream>
#include <iostream>

using namespace std;

class Colectie{
private:
    int elem[8];
    int fr[8];
    int cap;
public:
    Colectie();
    Colectie(const Colectie &bani);
    //~Colectie();
    int getcap();
    int getelem(int poz);
    int getfrelem(int poz);
    void setfrelem(int poz, int val);
    void adauga(int elem);
    bool sterge(int elem);
    int nrval();
    int suma();
    Colectie& operator=(const Colectie &c);
    friend ostream& operator<<(ostream &os, const Colectie &c);
};
