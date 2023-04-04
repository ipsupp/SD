#include <cstring>
#include "colectie.h"

Colectie::Colectie(){
    //cout<<"&\n";
    this -> cap = 8;
    this -> elem[0] = 1, this -> elem[1] = 5, this -> elem[2] = 10, this -> elem[3] = 20;
    this -> elem[4] = 50, this -> elem[5] = 100, this -> elem[6] = 200, this -> elem[7] = 500;
    for(int i=0;i<this->cap;i++)
        this -> fr[i] = 0;
}

int Colectie::getfrelem(int poz){
    return this->fr[poz];
}

void Colectie::setfrelem(int poz, int val){
    //for(int i=0;i<this->cap;i++)
        //if( banc == this->elem[i] )
    this->fr[poz] = val;
}

Colectie::Colectie(const Colectie &bani){
    for(int i=0; i < this->cap; i++)
        this -> fr[i] = bani.fr[i];
}

int Colectie::getcap(){
    return this->cap;
}

int Colectie::getelem(int poz){
    return this->elem[poz];
}

void Colectie::adauga(int elem){
    int poz=-1,i=0;
    while(poz==-1 && i<this->cap){
        if(this->elem[i]==elem)
            poz=i;
        i++;
    }
    if(poz!=-1)
        this->fr[poz]++;
    //else exceptie, nu exista o astfel de bancnota
}

bool Colectie::sterge(int elem){
    int poz=-1,i=0;
    while(poz==-1 && i<this->cap){
        if(this->elem[i]==elem)
            poz=i;
        i++;
    }
    if(poz!=-1 && this->fr[poz]>0){
        this->fr[poz]--;
        return true;
    }

    //else exceptie 2 cazuri
          // cazul 1. nu exista tipul bancnota
          // cazul 2. bancnota a fost deja stearsa din vector
    return false;
}

int Colectie::nrval(){
    int s=0;
    for(int i=0;i<this->cap;i++)
        s+=this->fr[i];
    return s;
}

int Colectie::suma(){
    int s=0;
    for(int i=0;i<this->cap;i++){
        int cont=this->fr[i];
        for(int j=0;j<cont;j++)
            s+=this->elem[i];
    }

    return s;
}

Colectie& Colectie::operator=(const Colectie &c){
    for(int i=0; i < this->cap; i++)
        this -> fr[i] = c.fr[i];
    return *this;
}

ostream& operator<<(ostream &os, const Colectie &c){
    //os << "Exista un numar de " << c.cap << " bancnote.\n";
    for(int i=0;i<c.cap;i++)
        if(c.fr[i]>0)
            os << "pentru bancnota " << c.elem[i] << " exista " << c.fr[i] << " exemplare\n";
    return os;
}
