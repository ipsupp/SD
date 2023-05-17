
#include "TestList.h"
#include "List.h"
#include <cassert>
void TestList::test_size()
{
    List<int> test_list;
    assert(test_list.size() == 0);
}

void TestList::test_push_back()
{
    List<int> test_list;
    test_list.push_back(1);
    test_list.push_back(10);
    test_list.push_back(20);

    assert(test_list.size() == 3);
    assert(test_list.get_at(0) == 1);
    assert(test_list.get_at(1) == 10);
    assert(test_list.get_at(2) == 20);
}

void TestList::test_delete_element()
{
    List<int> test_list;
    test_list.push_back(1);
    test_list.push_back(10);
    test_list.push_back(20);

    test_list.delete_elem(10);
    assert(test_list.delete_elem(1000) == 0);
    assert(test_list.get_at(0) == 1);
    assert(test_list.get_at(1) == 20);
    assert(test_list.size() == 2);
}

