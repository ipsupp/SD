#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* last;

public:
    List()
    {
        this->first = nullptr;
        this->last = nullptr;
    }
    List(List<T>& lista);
    int size();
    bool is_empty();
    void update(int index, T element);
    void set_at(int index, T element);
    void push_back(T element);
    T get_at_element(int index);
    int get_indexul(T element);
    int delete_elem(T element);
};

template<class T>
List<T>::List(List<T> &lista)
{
    first = nullptr;
    last = nullptr;
    Node<T>* crt = lista.first;
    while (crt != nullptr)
    {
        push_back(crt->info);
        crt = crt->next;
    }
}

template<class T>
int List<T>::get_indexul(T element)
{
    int index = 0;
    Node<T>* crt = first;
    while (crt->info != element)
    {
        index++;
        crt = crt->next;
    }
    return index;
}


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
T List<T>::get_at_element(int index)
{
    if (index < 0 or index >= size())
        throw invalid_argument("Pozitia nu este valida1.");
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

    if (crt == first && crt == last) {
        first = nullptr;
        last = nullptr;
    }
    else if (crt == first) {
        first = crt->next;
        first->prev = nullptr;
    }
    else if (crt == last) {
        last = crt->prev;
        last->next = nullptr;
    }
    else {
        crt->prev->next = crt->next;
        crt->next->prev = crt->prev;
    }
    delete crt;
    return 1;
}

template<class T>
void List<T>::set_at(int index, T element)
{
    if (index < 0 || index >= size())
        throw invalid_argument("Pozitia nu este valida3.");
    Node<T>* crt = first;
    int count = 0;
    while (count < index) {
        crt = crt->next;
        count++;
    }
    crt->info = element;
}
template<class T>
bool List<T>::is_empty()
{
    if (first == nullptr)
        return true;
    return false;
}

template<class T>
void List<T>::update(int index, T element)
{
    if (index < 0 || index >= size())
        throw invalid_argument("Pozitia nu este valida4.");

    Node<T>* crt = first;
    int nr_elem = 0;
    while (nr_elem < index)
    {
        crt = crt->next;
        nr_elem++;
    }
    crt->info = element;

}
