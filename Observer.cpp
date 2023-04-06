/**************************************************************************************************
Author: Eric Lozano
Professor: Yongjie Zheng
4/26/2022

Description: This code is supposed to be an example of observer pattern. We are meant to make People and
Organizations into observers/listeners/subscribers and make Fire/Police department subjects/posters/publishers.

***************************************************************************************************/



#include <iostream>
#include <vector>

using namespace std;


//create class observer
class observer
{
  //string protected name
protected:
  string name;//string name
public:
  observer (string s)//observer takes a string s which will ne the subscribers name in main
  {
    name = s;//s is saved to name
  }
  virtual void action (string s) = 0;//pure virtual used to be overwritten by derrived child classes in people and organization
  
};

//create class subject
class subject
{
public:
  //create attach fuction to attach the observers to the listeners
  void attach(observer *o)
  {
    listeners.push_back(o);//insrt observers
  }
  //void detach just deletes the observers
  void detach(observer *o)
  {
    int count = listeners.size();//get size of vector
    int i;//int it
    for(i = 0; i < count; i++)//loop through vector
      {
	if(listeners[i] == o)//if listeners i is the same as observer object enter if
	  {
	    break;//break we found the desired observer object
	  }
      }
    //if we are less then count we are withinng the vector size
    if (i < count)
      {
	listeners.erase(listeners.begin()+i);//delete vsector at starting position + i
      }
  }

  virtual void notify() = 0;//pure virtual void function meant to be overwritten by child derrived classes in Fire/Police dept.

  //we want to be able to inherit vector but not give the piublic access to it.
protected:
  vector < observer * > listeners;//create listeners vector.
};

//create People class that inherits observer class.
class People:public observer
{
public:
  //inherit constructor of parent 
  People(string s): observer(s) {
     
  }
  //action just print a string
  void action(string s)
  {
    cout << name << " is running away from a " << s << endl;
  }
};

//create organization class that inherits observer class
class Organization:public observer
{
public:
  //organization inherits observer constructor.
  Organization(string s): observer(s) {

  }
  //action just prints a cout
  void action(string s)
  {
    cout << name << " is paying attention on a " << s << endl;
  }
};

//create class fire department that inherits subject class
class FireDept: public subject
{

public:
  //compiler complained about these values being private so moved them to public
  string location;
  FireDept()
  {
    //nothing
  }
  void setAlarm(string locat)
  {
    //we set location to locat
    //then we call notify since once the alarm is triggered notify notifies subs 1 and 2 by calling action.
    location = locat;
    notify();
  }
  void notify()
  {
    //notify can access subjects listeners since it is inheriting
    int count = listeners.size();//get listeners size
    for(int i = 0; i < count; i++)//loop thorugh listeners
      {
        listeners[i]->action("fire alarm near "+location);//call action thorugh listeners
      }

  }
};

class PoliceDept: public subject
{
  
public:
  
  //compiler complained about these values being private so moved them to public
  string location;

  PoliceDept()
  {
    //nothing
  }
  void setAlarm(string locat)
  {
    //we set location to locat
    //then call notify since once the alarm is triggered notify notifies subs 1 and 2 by calling action.
    location = locat;
    notify();
  }
  //call notify fucntion
  void notify()
  {
    //notify can access subjects listeners since it is inheriting
    int count = listeners.size();//get listeners size
    for(int i = 0; i < count; i++)
      {
        listeners[i]->action("fire alarm near "+location);//call action thorugh listeners
      }
  }
};

int main()
{
  //create observer class which we will pass a new people called sam
  //we do this so we can put sam inot the listeners array
  observer* obs = new People("Sam");    
  FireDept FD;//cretae fire dpt
  FD.attach(obs);//pass/push obs to it
  observer* obs2 = new Organization("UCLA");//create obs2 which we assign a new poorg called UCLA.
  FD.attach(obs2);//pass/push obs2
  FD.setAlarm("San Diego");//pass location to set alarm
  
  //create observer class which we will pass a new people called Mary
  //we do this so we can put sam inot the listeners array
  observer* obs3 = new People("Mary");
  PoliceDept PD;//cretae police dpt
  PD.attach(obs3);//pass/push obs3 to it
  observer* obs4 = new Organization("UCLA");//create obs4 which we assign a new poorg called UCLA.
  PD.attach(obs4);//pass/push obs4 to it
  PD.setAlarm("Irvine");//pass location to set alarm

}
