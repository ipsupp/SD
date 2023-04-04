#include "tranzactie.h"

class ATM{
private:
    Colectie bani;
    Tranzactie tranzactii[10];
    int nrtranzactii;
public:
    ATM();
    ATM(Colectie &c);
    //~ATM();
    void adaugatr(int suma, Colectie b);
    void backtr(int k,int sum,int ches);
    void update(int op,int ches);
    friend ostream& operator<<(ostream &os, ATM &a);
};
