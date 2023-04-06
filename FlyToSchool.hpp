#ifndef FLYTOSCHOOL_H
#define FLYTOSCHOOL_H
#include <iostream>
#include "GoToSchool.hpp"

using namespace std;

class FlyToSchool:public GoToSchool {
  
  void takeTransit() { cout << "We are taking a flight." << endl; }
  void arrive() { cout << "After 2 hours, we arrive." << endl; }

};

#endif
