
#include "VectorDinamic.h"
#include <iostream>
using namespace std;
VectorDinamic::VectorDinamic()
{
    this->capacity = 0;
    this->nrElems = 0;
}

VectorDinamic::VectorDinamic(int capacitate)
{
    if (capacitate <= 0)
        throw invalid_argument("Capacitatea trebuie sa fie un nr pozitiv.");
    this->capacity = capacitate;
    this->elems = new TElem [capacitate];
    this->frecv = new int [capacitate];
    this->nrElems = 0;
}

VectorDinamic::~VectorDinamic() {}

void VectorDinamic::resize()
{
    this->capacity = this->capacity * 2;
}

int VectorDinamic::get_capacitate()
{
    return this->capacity;
}

VectorDinamic& VectorDinamic::add_el_frecv(TElem el,int frecv_noua)
{
    if (capacity == nrElems)
        resize();

    int i , element = int(el);
    switch (element)
    {
        case 1:
        {
            i = 0;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;

        };
        case 5:
        {
            i = 1;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 10:
        {
            i = 2;
            frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 20:
        {
            i = 3;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 50:
        {
            i = 4;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 100:
        {
            i = 5;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 200:
        {
            i = 6;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        case 500:
        {
            i = 7;
            this->frecv[i] = frecv[i] + frecv_noua;
            break;
        }
        default:
        {
            cout<<"Bancnota invalida."<<endl;
        }
    }

//    int ok = 0;
//    for (int i = 0; i < this->nrElems; i++)
//    {
//        if (this->elems[i] == el)
//        {
//            this->frecv[i] = frecv[i] + frecv_noua;
//            ok = 1;
//        }
//    }
//
//    if (ok == 0)
//    {
//        this->nrElems++;
//        this->elems[nrElems - 1] = el;
//        this->frecv[nrElems - 1] = frecv_noua;
//    }
}


VectorDinamic& VectorDinamic::add_el(TElem el)
{
    if (capacity == nrElems)
        resize();

    int i , element = int(el);
    switch (element)
    {
        case 1:
        {
            i = 0;
            this->frecv[i] ++;
            break;

        };
        case 5:
        {
            i = 1;
            this->frecv[i] ++;
            break;
        }
        case 10:
        {
            i = 2;
            this->frecv[i] ++;
            break;
        }
        case 20:
        {
            i = 3;
            this->frecv[i] ++;
            break;
        }
        case 50:
        {
            i = 4;
            this->frecv[i] ++;
            break;
        }
        case 100:
        {
            i = 5;
            this->frecv[i] ++;
            break;
        }
        case 200:
        {
            i = 6;
            this->frecv[i] ++;
            break;
        }
        case 500:
        {
            i = 7;
            this->frecv[i] ++;
            break;
        }
        default:
        {
            cout<<"Bancnota invalida."<<endl;
        }
}

int VectorDinamic::size()
{
    return this->nrElems;
}

TElem VectorDinamic::get_elem(int index)
{
    return this->elems[index];
}

int VectorDinamic::get_frecv(TElem el)
{
    for (int i = 0; i < this->nrElems; i++)
    {
        TElem a = this->elems[i];
        if (a == el)
            return this->frecv[i];

    }
    return 0;
}


