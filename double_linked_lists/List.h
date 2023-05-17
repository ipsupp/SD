#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* last;

public:
    List(){
        this->first = nullptr;
        this->last = nullptr;
    }
    int size();
    void push_back(T element);
    T get_at(int index);
    int delete_elem(T element);
};



template<class T>
int List<T>::size()
{
    int nr = 0;
    Node<T>* crt = first;
    while (crt != nullptr)
    {
        nr++;
        crt = crt->next;
    }
    return nr;
}

template<class T>
void List<T>::push_back(T element)
{
    Node<T>* new_node = new Node<T>(element);
    if (first == nullptr)
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->prev = last;
        last->next = new_node;
        last = new_node;
    }
}

template <class T>
T List<T>::get_at(int index)
{
    if (index < 0 or index >= size())
        throw invalid_argument("Pozitia nu este valida.");
    Node<T>* crt = first;
    int nr_elem = 0;
    while (nr_elem < index)
    {
        crt = crt->next;
        nr_elem++;
    }
    return crt->info;
}

template <class T>
int List<T>::delete_elem(T element) {
    if (first == nullptr)
        return 0;

    Node<T> *crt = first;
    while (crt != nullptr and crt->info != element) {
        crt = crt->next;
    }

    if (crt == nullptr)
        return 0;
    if (crt == first and crt == last) {
        first = nullptr;
        last = nullptr;
        delete crt;
        return 1;
    }
    else
    {
        if (crt == first)
        {
        first = crt->next;
        first->prev = nullptr;
        }
        if (crt == last)
        {
        last = crt->prev;
        last->next = nullptr;
        }
        crt->prev->next = crt->next;
        crt->next->prev = crt->prev;
        return 1;
    }
}
