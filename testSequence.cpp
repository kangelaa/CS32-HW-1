//
//  testSequence.cpp
//  HW1
//
//  Created by Angela Kan on 1/19/21.
//
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;
//
void test()
{
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
}

void test2(){
    Sequence s;
    assert(s.empty());
    assert(s.find(42) == -1);
    assert(s.insert(42) == 0);
    assert(s.size() == 1  &&  s.find(42) == 0);
}

int main()
{
    test();
    test2();
    cout << "Passed all tests" << endl;
}
//
//#include <string>
//
//void test()
//{
//    Sequence s;
//    s.insert(0, "lavash");
//    s.insert(0, "tortilla");
//    assert(s.size() == 2);
//    ItemType x = "injera";
//    assert(s.get(0, x) && x == "tortilla");
//    assert(s.get(1, x) && x == "lavash");
//}
//
//void test2(){
//    Sequence s;
//    assert(s.empty());
//    assert(s.find("laobing") == -1);
//    assert(s.insert("laobing") == 0);
//    assert(s.size() == 1  &&  s.find("laobing") == 0);
//}
//
//void test3(){
//    Sequence s;
//    s.insert(0, "a");
//    s.insert(1, "b");
//    s.insert(2, "c");
//    s.insert(3, "b");
//    s.insert(4, "e");
//    assert(s.remove("b") == 2);
//    assert(s.size() == 3);
//    string x;
//    assert(s.get(0, x)  &&  x == "a");
//    assert(s.get(1, x)  &&  x == "c");
//    assert(s.get(2, x)  &&  x == "e");
//}
//
//void test4(){
//    Sequence s1;
//    s1.insert(0, "paratha");
//    s1.insert(0, "focaccia");
//    Sequence s2;
//    s2.insert(0, "roti");
//    s1.swap(s2);
//    assert(s1.size() == 1  &&  s1.find("roti") == 0  &&  s2.size() == 2  &&
//                s2.find("focaccia") == 0  &&  s2.find("paratha") == 1);
//}
//
//void test5(){
//    Sequence s;
//    s.insert(0, "dosa");
//    s.insert(1, "pita");
//    s.insert(2, "");
//    s.insert(3, "matzo");
//    assert(s.find("") == 2);
//    s.remove("dosa");
//    assert(s.size() == 3  &&  s.find("pita") == 0  &&  s.find("") == 1  &&
//                s.find("matzo") == 2);
//}
//
//int main()
//{
//    test();
//    test2();
//    test3();
//    test4();
//    test5();
//    cout << "Passed all tests" << endl;
//}
