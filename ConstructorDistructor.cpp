/*
 * ConstructorDistructor.cpp
 *
 *  Created on: 31-Aug-2011
 *      Author: Alok
 */
#include <iostream>
#include <typeinfo>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;
class base {

public:
	base()
	{
		cout<<"1 base constructor called"<<endl;
	}
	base(int i)
	{
		cout<<"2 base constructor called"<<endl;
	}
	virtual ~base()
	{
		cout<<"base destructor called"<<endl;
	}

	virtual void print() const = 0;
};

void base::print() const
{
	cout<<"base: Hello World!!!"<<endl;
}

class derive : public base {
	int i;
public:
	derive ()
	{
		cout<<"1 derive constructor called"<<endl;
	}
	derive (int i): base(i)
	{
		this->i = i;
		cout<<"2 derive constructor called"<<endl;
		print();
	}

	explicit derive (const derive & c)
	{
		cout<<"3 derive constructor called"<<endl;
	}

	~derive()
	{
		cout<<"derive destructor called"<<endl;
	}

	void print() const
	{
		cout<<"i: "<<i<<endl;
		cout<<"derive const print: Hello World!!!"<<endl;
		base::print();    //if method is const then can access only const method, so i modified base print to const
	}

	void print1()
	{
		cout<<"i: "<<i<<endl;
		cout<<"derive non const print: Hello World!!!"<<endl;
		base::print();    //here doesnt matter whether base::print is const or not
	}
};

void print(const derive &d)  //if & is removed implicit copy constructor will be called
{
	d.print();  //via const object only const method can be called
	//d.print1();  //here it will have error: passing `const derive' as `this' argument of `void derive::print1()' discards qualifiers
					// this is because d is const object, but print1 in non const method
}

int main ()
{
	const derive d, a(1);  //destructor will get called before main gets end
	//a.print();
	//derive b = d;  //Error: since its implicit copy constructor called, but copy constructor is declared "explicit"
	derive b(d);   // no issue, here explicit copy constructor is called
	cout<<"Calling print"<<endl;
	print(d);

	d.print();
	//d.print1();   //error: here since d is const object can not call non-const method
	//base* b = new derive();
	//auto_ptr<base> b(new derive());
	//boost::scoped_ptr<base> b(new derive());
	//boost::shared_ptr<base> b(new derive());
	//cout<<"typeid: "<<typeid(b).name()<<endl;
	//cout<<"typeid: "<<typeid(*b).name()<<endl;

	//delete b; //then only destructor will get called


	derive *ptrDerive = new derive[10];

	for (int i = 0; i< 10; i++)
			(ptrDerive + i)->print();

	cout<<"Calling delete for ptrDerive"<<endl;
	delete[] ptrDerive;

    cout<<"after this d and a destructor will get called"<<endl;
	return 0;
}
