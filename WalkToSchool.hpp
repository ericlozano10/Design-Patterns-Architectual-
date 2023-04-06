#ifndef WALKTOSCHOOL_H
#define WALKTOSCHOOL_H
#include <iostream>
#include "GoToSchool.hpp"

using namespace std;

class WalkToSchool:public GoToSchool {
    void takeTransit() { cout << "We are walking to school." << endl; }
    void arrive() { cout << "After 10 minutes, we arrive." << endl; }

};

#endif
