/**************************************************************************************************
Author: Eric Lozano
Professor: Yongjie Zheng
4/26/2022

Description: This code basically uses a static factory method to to decide wether to walk to school or go to school.

***************************************************************************************************/


#include <iostream>
#include <vector>
//#include "WalkToSchool.hpp"
//#include "FlyToSchool.hpp"

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

class WalkToSchool:public GoToSchool {
  void takeTransit() { cout << "We are walking to school." << endl; }
  void arrive() { cout << "After 10 minutes, we arrive." << endl; }

};


class FlyToSchool:public GoToSchool {

  void takeTransit() { cout << "We are taking a flight." << endl; }
  void arrive() { cout << "After 2 hours, we arrive." << endl; }

};



int main()
{
  //create vector
  vector <GoToSchool*> t1;
  int choice;//int for choice selection
  while(true)// while true enter 
    {
      //dsiplay prompt
      cout<<"WalkToSchool(1) FlyToSchool(2) GO(0): "<<endl;
      cin>>choice;
      if(choice == 0)//if choice 0 then break out of loop
	{
	  break;
	}
      t1.push_back(GoToSchool::pick(choice));//call vector and push static factory method
    }
  //loop through vector
  for(int i = 0; i < t1.size(); i++)
    {
      t1[i]->go();//call go function in GoToSchool
    }
  //loop thorugh vector
  for(int i = 0; i <t1.size();i++)
    {
      delete t1[i];//delete object at position i.
    }

  return 0;
}

// returns a go to school oobject
// parameter: is int choice
GoToSchool *GoToSchool::pick(int choice)
{
  //choice selection
  if(choice == 1)//if 1 enter
    {
      return new WalkToSchool; //return walk to school;
    }
  else
    {
      return new FlyToSchool;//return Fly to school
    }
}
