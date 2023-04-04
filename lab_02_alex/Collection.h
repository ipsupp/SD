
#pragma once
#include <iostream>

template <typename TElem>
class Collection
{

private:
    TElem* elements;
    int* occurences;
    int dist_elem;
    int capacity;
public:
    Collection();
    bool search(TElem el);
    int size();
    void resize();
    void add(TElem el);
    bool remove(TElem el);
    void set_capacity(int n);
    ~Collection();
    TElem get_element_at_index(int index);
    int get_occurence_at_index(int index);
    void set_occurence_at_index(int index, int new_value);
};

template<typename TElem>
void Collection<TElem>::set_occurence_at_index(int index, int new_value)
{
    this->occurences[index] = new_value;
}

template <typename TElem>
Collection<TElem>::Collection()
{
    this->capacity = 10;
    this->elements = new TElem [capacity];
    this->occurences = new int (capacity);
    this->dist_elem = 0;
}

template <typename TElem>
void Collection<TElem>::set_capacity(int n)
{
    this->capacity = n;
}

template <typename TElem>
bool Collection<TElem>::search(TElem el)
{
    for (int i=0; i < this->dist_elem; i++)
        if (this->elements[i] == el)
            return true;
    return false;
}

template <typename TElem>
int Collection<TElem>::size()
{
    int s = 0;
    for (int i=0; i < this->dist_elem; i++)
        s = s + 1;
    return s;
}

template <typename TElem>
void Collection<TElem>::resize()
{
    TElem  *newElems = new TElem [capacity*2];
    for (int i=0; i < dist_elem; i++)
        newElems[i] = elements[i];
    capacity = capacity * 2;
    elements = newElems;
    int* newOcc = new int[capacity];
    for (int i=0; i < dist_elem; i++)
        newOcc[i] = occurences[i];
    occurences = newOcc;

}

template <typename TElem>
void Collection<TElem>::add(TElem el)
{
    int poz = -1;
    for (int i=0; i < this->dist_elem and poz == -1; i++)
    {
        if (*this->elements[i] == *el)
            poz = i;
    }
    if (poz != -1 )
        this->occurences[poz]++;
    else {
        if (this->dist_elem == this->capacity)
            resize();
        this->elements[dist_elem] = el;
        this->occurences[dist_elem] = 1;

        dist_elem++;
    }
}

template <typename TElem>
bool Collection<TElem>::remove(TElem el)
{

    int poz = -1;
    for (int i = 0; i < this->dist_elem and poz == -1; i++)
        if (this->elements[i] == el)
            poz = i;
    if (poz == -1)
        return false;
    else
    {
        if (this->occurences[poz] > 1)
            this->occurences[poz] -- ;
        else{
            for (int i = poz; i < this->dist_elem - 1; i++)
            {
                this->elements[i] = this->elements[i + 1];
                this->occurences[i] = this->elements[i + 1];
            }
            this->dist_elem --;
            return true;
        }
    }
}

template <typename TElem>
Collection<TElem>::~Collection()
{
    delete[] elements;
    delete[] occurences;
}

template <typename TElem>
TElem Collection<TElem>::get_element_at_index(int index)
{
    return this->elements[index];
}

template <typename TElem>
int Collection<TElem>::get_occurence_at_index(int index)
{
    return this->occurences[index];
}
