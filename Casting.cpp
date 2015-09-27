/*
 * Casting.cpp
 *
 *  Created on: 06-Sep-2011
 *      Author: Alok
 */
#include <iostream>

using namespace std;

int main()
{

	int x = 10, y = 3;
	double z;

	z = static_cast<double>(x) / y; // same as: (double)x, works similarly to the C style cast, except it will only do standard type conversions

	//z = dynamic_cast<double>(&x) / y;  //error: cannot dynamic_cast 'x' (of type `int') to type 'double' (target is not pointer or reference)

	cout<<"Mod: "<<z<<endl;

	enum color {red, blue, green};
	int c1 = 2, c2 = 1;

	color c = blue;

	cout<<"Color: "<<c<<endl;

	//c = c1;			//error
	c = static_cast<color>(c1);
	cout<<"Color: "<<c<<endl;

	c = static_cast<color>(c2);
		cout<<"Color: "<<c<<endl;

	const int p = 12;

	int q;

	q = const_cast<int&>(p);
	q++;

	cout<<"q: "<<q<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"&q: "<<&q<<endl;
	cout<<"&p: "<<&p<<endl;


	int *p1;

	const int q1 = 10;

	p1 = const_cast<int*>(&q1);   //both are working fine :)
	//p1 = (int *)&q1;
	(*p1)++;

	cout<<"q1: "<<q1<<endl;
	cout<<"*p1: "<<*p1<<endl;
	cout<<"&q1: "<<&q1<<endl;      //amazing the values are diffetrent but addresses are same
	cout<<"p1: "<<p1<<endl;

	int ch = 97;
	//char cha = static_cast<char>(ch);
	char cha = char(ch);
	cout<<"cha: "<<cha<<endl;

	return 0;

}
