/*
 * VirtalFunction.cpp
 *
 *  Created on: 23-Sep-2011
 *      Author: Alok
 */

#include <iostream>

using namespace std;

class base {

public:
	virtual void myFunc(const int &x) = 0;

};

class derA : public base {

public:
	derA()
	{
		myFunc(10);
	}

	virtual void myFunc(const int & x)
	{
		cout<<"derA::myFunc"<<endl;
	}

	void myFunc2()
	{
		cout<<"derB::myFunc2"<<endl;
	}
};

class derB : public base {
	void myFunc(const int & x)
	{
		cout<<"derB::myFunc"<<endl;
	}


};

int main()
{
		//base * b = new derA();
	base  * b = new derA();

		b->myFunc(10);

		//b->myFunc2(); //it will throw error: clas base has no member myFunc2

		int a = 10, c = 20;
		const int & x = a;

		//x = c;  //error

cout <<"x: "<<x<<endl;
		return 0;
}
