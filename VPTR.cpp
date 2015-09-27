/*
 * VPTR.cpp
 *
 *  Created on: 12-Apr-2012
 *      Author: Alok
 */

#include <iostream>

using namespace std;

class base1
{
	virtual void abc()
	{
		cout<<"Called base1::abc";
	}
	virtual void xyz()
	{
		cout<<"Called base1::xyz";
	}
};

class base2
{
	virtual void abc()
	{
		cout<<"Called base2::abc";
	}
	virtual void xyz()
	{
		cout<<"Called base2::xyz";
	}
	virtual void mno()
	{
		cout<<"Called base2::mno";
	}
};

class base3
{
	virtual void abc()
	{
		cout<<"Called base3::abc";
	}
	virtual void xyz()
	{
		cout<<"Called base3::xyz";
	}
};

class derive1 : public base1, base2, base3
{

/*	void abc()
	{
		cout<<"Called derive1::abc";
	}
	void xyz()
	{
		cout<<"Called derive1::xyz";
	}*/
};

typedef void(*Func)(void);

int main()
{
	derive1 obj;

	//size should be for 3 pointer data type, so 3 tables
	cout << "Size of obj: "<<sizeof(obj)<<", Number of vptr: "<<sizeof(obj)/sizeof(void *)<<endl;
	Func func;

	//1st class address
	cout<<"base1 add: "<<(&obj + 0)<<"\t|\t";
	//1st table's 1st function called
	func = (Func)*(((int*)*(int*)((int*)&obj + 0)) + 0);
	func();
	cout<<"\tAdd: "<<(int*)*func<<"\t|\t";

	//1st table's 2nd function called
	func = (Func)*(((int*)*(int*)((int*)&obj + 0)) + 1);
	func();
	cout<<"\tAdd: "<<(int*)*func<<endl;

	//2nd class address
	cout<<"base2 add: "<<(int*)((int*)&obj + 1)<<"\t|\t";
	//2nd table's 1st function called
	func = (Func)*(((int*)*((int*)((int*)&obj + 1)) + 0));
	func();
	cout<<"\tAdd: "<<(int*)*func<<"\t|\t";

	//2nd table's 2nd function called
	func = (Func)*(((int*)*((int*)((int*)&obj + 1)) + 1));
	func();
	cout<<"\tAdd: "<<(int*)*func<<"\t|\t";

	//2nd table's 3rd function called
	func = (Func)*(((int*)*((int*)((int*)&obj + 1)) + 2));
	func();
	cout<<"\tAdd: "<<(int*)*func<<endl;

	//3rd class address
	cout<<"base3 add: "<<(int*)((int*)&obj + 2)<<"\t|\t";
	//3rd table's 1st function called
	func = (Func)*(((int*)*((int*)((int*)&obj + 2)) + 0));
	func();
	cout<<"\tAdd: "<<(int*)*func<<"\t|\t";

	//3rd table's 2nd function called
	func = (Func)*(((int*)*((int*)((int*)&obj + 2)) + 1));
	func();
	cout<<"\tAdd: "<<(int*)*func<<endl;
	return 0;
}
