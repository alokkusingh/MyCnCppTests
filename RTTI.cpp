/*
 * RTTI.cpp
 *
 *  Created on: 17-Apr-2012
 *      Author: Alok
 */
//RTTI: run-time type information...

#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
	public:
		virtual void funct(){}
};

class Derived:public Base{};

int main()
{
	Derived* Test1 = new Derived;
	Base* Test2 = Test1;

	cout<<"The type name of Test1 is: ";
	cout<<typeid(Test1).name()<<endl;

	cout<<"The type name of *Test1 is: ";
	cout<<typeid(*Test1).name()<<endl;

	cout<<"The type name of Test2 is: ";
	cout<<typeid(Test2).name()<<endl;

	cout<<"The type name of *Test2 is: ";
	cout<<typeid(*Test2).name()<<endl;

	delete Test1;

	return 0;
}
