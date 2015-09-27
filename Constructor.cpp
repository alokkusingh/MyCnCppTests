/*
 * Constructor.cpp
 *
 *  Created on: 17-Apr-2012
 *      Author: Alok
 */

#include <iostream>

class Base {
	int a;
public:
	Base()
	{

	}
	Base (int a)
	{
		std::cout<<"Base::IntParamConstructor called"<<std::endl;
		this->a = a;
	}

	Base (const Base & b)
	{
		std::cout<<"Base::CopyConstructor called"<<std::endl;
		this->a = b.a;
	}

	~Base()
	{
		std::cout<<"Destructor called"<<std::endl;
	}

	Base& operator=(const int a)
	{
		::std::cout<<"= Operator called"<<std::endl;
		this->a = a;
		return *this;
	}

	Base& operator+(const int a)
	{
		::std::cout<<"+ Operator called"<<std::endl;
		this->a = this->a + a;
		return *this;
	}

	void print()
	{
		std::cout<<"a = "<<a<<std::endl;
	}
};

int main()
{
	Base b(10), c(20);

	b.print();
	std::cout<<"Directely assigning some value to the object"<<std::endl;
	(b = 20) = 30; //if oerator= is defined than Operator will be called otherwise Base(const int) constructor will be called
	b.print();

	std::cout<<"Directely assigning object to the object"<<std::endl;
	b = c; //if oerator= for object is defined than it will be otherwise implict Operator= will be called and result will be shallo copy

	b.print();

	std::cout<<"Going out of reach"<<std::endl;
	return 0;
}
