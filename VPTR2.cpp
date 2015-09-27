/*
 * VPTR2.cpp
 *
 *  Created on: 13-Apr-2012
 *      Author: Alok
 */

#include <iostream>

using namespace std;

class base1
{
	virtual void abc()
	{
		cout<<"Called base1::abc"<<endl;
	}
	virtual void xyz()
	{
		cout<<"Called base1::xyz"<<endl;
	}
};

class base2 : public base1
{
	virtual void abc()
	{
		cout<<"Called base2::abc"<<endl;
	}
	virtual void xyz()
	{
		cout<<"Called base2::xyz"<<endl;
	}
};

class derive1 : public base2
{

};

typedef void(*Func)(void);

int main()
{
	derive1 obj;

	//size should be for 1 pointer data type, so only one table
	cout << "size of obj: "<<sizeof(obj)<<endl;
	Func func;

	//1st table's 1st function called
	func = (Func)*(((int*)*(int*)((int*)&obj + 0)) + 0);
	func();
	cout<<"\tAddress: "<<(int*)*func<<endl;

	//1st table's 2nd function called
	func = (Func)*(((int*)*(int*)((int*)&obj + 0)) + 1);
	func();
	cout<<"\tAddress: "<<(int*)*func<<endl;

	return 0;
}
