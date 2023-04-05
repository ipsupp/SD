#include <iostream>
#include "tests.h"
#include "Collection.h"
using namespace std;
int main()
{
    test_all();

    Collection col;
    int a = 1, b = 5, c = 10;
    for (int i = 0; i < 7; i++)
        col.add_bancnota(a);
    for (int i = 0; i < 5; i++)
        col.add_bancnota(b);
    for (int i = 0; i < 3; i++)
        col.add_bancnota(c);
    cout<<col.get_bancnota(0)<<endl;
    cout<<col.get_frecventa(0)<<endl;
}
