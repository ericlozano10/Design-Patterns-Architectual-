/**************************************************************************************************
Author: Eric Lozano
Professor: Yongjie Zheng
4/26/2022

Description: This code is a header files which cotains the go to school function and static factory method used in main.

***************************************************************************************************/



#ifndef GOTOSCHOOL_H
#define GOTOSCHOOL_H
#include <iostream>

using namespace std;

class GoToSchool {
    void getUp() { cout << "Get up." << endl; }
    void eatBreakfest() { cout << "Eat breakfest." << endl; }
    virtual void takeTransit() { cout << "Take school bus." << endl; }
    virtual void arrive() = 0;
  public:
  void go()
  {
    getUp();
    eatBreakfest();
    takeTransit();
    arrive();
  }
  //factory static method
  static GoToSchool* pick(int choice);
  
};

#endif
