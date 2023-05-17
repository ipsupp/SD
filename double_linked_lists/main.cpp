#include <iostream>
#include "TestList.h"
using namespace std;
int main() {
    TestList t;
    t.test_size();
    t.test_push_back();
    t.test_delete_element();
    cout<<"Testare completa."<<endl;
}
