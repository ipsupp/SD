#include <iostream>

using namespace std;

#include "atm.h"

ATM::ATM()
{
    this -> nrtranzactii = 0;
}

ATM::ATM(Colectie &c)
{
    this -> bani = c;
    this -> nrtranzactii = 0;
}

ostream& operator<<(ostream &os, ATM &a)
{
    os << "in atm exista urmatoarea colectie de bani: \n";
    os<<a.bani;
    os<<"\n";
    os << "s-a efectuat un numar de "<<a.nrtranzactii<<" tranzactii.";
    if(a.nrtranzactii>0){
        os<<" acestea sunt: \n";
        for(int i=0; i<a.nrtranzactii; i++)
            os<<"\n"<<a.tranzactii[i];
    }
    os<<"\n";
    return os;
}

int n=4, x[11], a[11], cont=-1;
Colectie c[10];

void afisare(int k)
{
    cont++;
    cout<<cont<<endl;
    for(int i = 0 ; i < k  ; i++)
        c[cont].setfrelem(i,x[i]);
    cout<<c[cont];
}


void ATM::backtr(int k, int sum, int ches)
{
    //cout<<"*";
    if(k<=n&&sum<ches)//
    {
        //cout<<"&";
        for(int i=0; i<=this->bani.getfrelem(k) && sum+this->bani.getelem(k)*i <= ches ; i++)
        {
            x[k]=i;
            a[k]=this->bani.getelem(k);
            //cout<<k<<" ";
            //cout<<a[k]<<" "<<x[k]<<endl;
            backtr(k+1, sum+this->bani.getelem(k)*i, ches);
        }
    }
    else if(sum==ches) afisare(k);
}

void ATM::update(int op,int ches){
    Tranzactie t(this->nrtranzactii,ches,c[op]);
    //cout<<t<<endl;
    this->tranzactii[this->nrtranzactii] = t;
    this->nrtranzactii++;
    //cout<<c[op]<<endl;
    for(int i=0;i<this->bani.getcap();i++){

        int dif=this->bani.getfrelem(i)-c[op].getfrelem(i);
        //cout<<dif<<endl;
        this->bani.setfrelem(i,dif);
        //cout<<this->bani<<endl;
    }
}

/**

int x[20], a[20], S=11,n=8;

void afisare(int k){
    for(int i = 0 ; i <=k  ; i++ )
        cout <<"**" << a[i] << " in numar de " << x[i]<<"**\n";
    cout<<endl;
}

int suma(int k){
    int s=0;
    for(int i=0;i<=k;i++)
        s+=x[i]*a[i];
    return s;
}

void ATM::backtr(int k){
    if(suma(k)<S)
        for(int i=1; i <= this->bani.getfrelem(k) ; i++){
            x[k]=i;
            a[k]=this->bani.getelem(k);
            cout<<a[k]<<" "<<x[k]<<" "<<suma(k)<<endl;
            if(suma(k)<S) backtr(k+1);
            else backtr(k);
    }
    else if(suma(k)==S) afisare(k);
}

/**


for(int i = 1 ; i <= this->bani.getfrelem(k) && !ok; i++)//
    {
        cout<<"pozitie: "<<k;
        cout<<" bancnota: "<<this->bani.getelem(k)<<" "<<"nr banc: "<<i;
        x[k] = i;
        sp += x[k] * this->bani.getelem(k);
        cout<<" suma: "<<sp<<endl<<endl;
        if(sp <= s )//&& k <= n
        {
            if( sp == s) afisare(k);     ///k == n &&
            else backtr(k + 1 , sp);   ///if(k < n)
        }
        sp -= x[k] * this->bani.getelem(k);
    }




void ATM::backtr(int k, int s)
{
    int i=0;
    while(i <= 7 )
    {
        int cont = this->bani.getfrelem(i);
        if(cont>0)
        {
            x[k].adauga(this->bani.getelem(i));
            this->bani.setfrelem(i,cont-1);
            cont--;
            cout<<cont<<" "<<k<<"\n"<<x[k];
            if( OK(k,i,cont) )
                if( x[k].suma() == s)
                    cout<<"**************"<<x[k];
                else{
                    if(cont>0)
                        backtr(k,s);
                    else backtr(k+1,s);
                }

        }
        else
            i++;
    }
}




void adaugatr(int suma, Colectie b){
    int id=this->nrtranzactii;
    Tranzactie t(id,suma,b);
    this -> tranzactii[this->nrtranzactii]=t;
    this->nrtranzactii++;
}*/
