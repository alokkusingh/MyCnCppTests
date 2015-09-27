/*
 * Const.cpp
 *
 *  Created on: 30-Apr-2012
 *      Author: Alok
 */

/*
 * Why can't I have a non-integral static const member in a class?
 * The problem is that with an integer, the compiler usually doesn't have to ever create a memory address for the constant.
 * It doesn't exist at runtime, and every use of it gets inlined into the surrounding code.
 * It can still decide to give it a memory location - if its address is ever taken
 * (or if it's passed by const reference to a function), that it must.
 * In order to give it an address, it needs to be defined in some translation unit.
 * And in that case, you need to separate the declaration from the definition,
 * since otherwise it would get defined in multiple translation units.
 *
 * Using g++ with no optimization (-O0), it automatically inlines constant integer variables but not constant double values.
 * At higher optimization levels (e.g. -O1), it inlines constant doubles.
 * Thus, the following code compiles at -O1 but NOT at -O0
 */

#include <iostream>
#include <string>

class CConst {

public:
	CConst ()
	{
        String2 = "India";
	}

	const char& operator[](std::size_t position) const
	{
		std::cout<<"Const version of [] called"<<std::endl;
		return String[position];
	}

	char& operator[](std::size_t position)
	{
		std::cout<<"Non-Const version of [] called"<<std::endl;
		return String2[position];
	}

	void print()
	{
		std::cout<<"Number: "<<Number<<std::endl;
		std::cout<<"Decimal: "<<Decimal<<std::endl;
		std::cout<<"String: "<<String<<std::endl;
	}
private:
	std::string String2;
	const static int Number = 5;
	//it was supposed to be an error (for non-integral type), but there is no error
	const static double Decimal = 5.0;

	//this is an error
	//const static std::string String = "Hello";

protected:
	//this is not an error
	const static std::string String;
};

//since for non-integral type definition is mandatory
const std::string CConst::String = "Hello";

int main()
{
	CConst obj;
	obj.print();
	//if non-const [] is not ther than const [] will be called
	std::cout<<obj[2]<<std::endl;

	const CConst constObj;
	//if const [] is not ther than error
	std::cout<<constObj[2]<<std::endl;

	return 0;
}
