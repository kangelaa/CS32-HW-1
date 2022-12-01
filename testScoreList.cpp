//
//  testScoreList.cpp
//  HW1
//
//  Created by Angela Kan on 1/19/21.
//

#include "ScoreList.h"
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    ScoreList s;
    assert(s.add(2));
    assert(s.add(2));
    assert(s.add(1));
    assert(s.add(100));
    assert(s.add(-1)==false);
    assert(s.add(101)==false);
    assert(s.remove(2));
    assert(s.remove(4) == false);
    assert(s.size() == 3);
    assert(s.minimum() == 1  &&  s.maximum() == 100);
    cout << "Passed all tests" << endl;
}
