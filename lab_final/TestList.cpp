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
    assert(test_list.get_at_element(0) == 1);
    assert(test_list.get_at_element(1) == 10);
    assert(test_list.get_at_element(2) == 20);
}

void TestList::test_delete_element()
{
    List<int> test_list;
    test_list.push_back(1);
    test_list.push_back(10);
    test_list.push_back(20);

    test_list.delete_elem(10);
    assert(test_list.delete_elem(1000) == 0);
    assert(test_list.get_at_element(0) == 1);
    assert(test_list.get_indexul(1) == 0);
    assert(test_list.get_at_element(1) == 20);
    assert(test_list.size() == 2);
}

void TestList::test_set_at()
{
    List<int> test_list;
    test_list.push_back(1); // 0
    test_list.push_back(10); // 1
    test_list.push_back(20); // 2
    test_list.set_at(1, 50);
    assert(test_list.get_at_element(0) == 1);
    assert(test_list.get_at_element(1) == 50);
    assert(test_list.get_at_element(2) == 20);

}

void TestList::test_is_empty()
{
    List<int> test_list1;
    assert(test_list1.is_empty() == true);
    List<int> test_list2;
    test_list2.push_back(1);
    assert(test_list2.is_empty() == false);
}

void TestList::test_update()
{
    List<int> test_list;
    test_list.push_back(1);
    test_list.push_back(10);
    test_list.push_back(20);
    test_list.update(0,5);
    assert(test_list.get_at_element(0) == 5);
    assert(test_list.get_at_element(1) == 10);
    assert(test_list.get_at_element(2) == 20);
}