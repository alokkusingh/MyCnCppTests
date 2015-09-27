/*
 * Explicit1.cpp
 *
 *  Created on: 17-Apr-2012
 *      Author: Alok
 */
// Keyword explicit used to avoid a single argument constructor from defining an automatic type conversion.
// A typical explicit usage example is in a collection class in which you can pass the initial size as constructor argument. For example, you could declare a constructor that has an argument for the initial size of a stack as shown below:
//simple class
//compiled using visual C++ .Net
#include <iostream>
using namespace std;
class MyStack
{
	public:
	//create a stack with initial size
	MyStack(int initsize);
	~MyStack(void);
};

MyStack::MyStack(int initsize)
{
	static int x;
	cout<<"Constructor: Pass #"<<x<<endl;
	x++;
}

MyStack::~MyStack(void)
{
	static int y;
	cout<<"Destructor: Pass #"<<y<<endl;
	y++;
}

//----main program----
int main()
{
	//The initial stack size is 10
	MyStack p(20);
	//but, there will be new stack objects
	//with size of 30!
	cout<<"Calling implicit constructor"<<endl;
	p = 30;

	cout<<"Without the explicit keyword!\n";
	return 0;
}
