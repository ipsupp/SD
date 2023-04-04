#include <iostream>

using namespace std;

#include "atm.h"

void print_meniu(){
    cout<<"1. detalii despre atm\n";
    cout<<"2. scoate o suma de bani\n";
    cout<<"0. iesire\n";
}

void meniu(){
    int ok=1;
    Colectie c;
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(5);
    c.adauga(5);
    c.adauga(10);
    c.adauga(10);
    c.adauga(10);
    c.adauga(10);
    //cout<<c;
    ATM atm(c);
    while(ok==1){
        print_meniu();
        cout<<"dati optiunea: ";
        int optiune;
        cin>>optiune;
        if(optiune == 1) cout<<atm;
        else if(optiune == 2){
            int ches;
            cout<<"da suma: ";
            cin>>ches;
            cout<<"optiunile sunt: \n";
            atm.backtr(0,0,ches);
            //if(cont==0) cout<<"nu exista optiuni\n";
                cout<<"alege optiunea: ";
                int op;
                cin>>op;
                atm.update(op,ches);


        }
        else if(optiune == 0) ok=0;
        else cout<<"optiune gresita\n";
    }
}
