/*
 * CastingDynamic.cpp
 *
 *  Created on: 15-Apr-2012
 *      Author: Alok
 */

#include <iostream>

//http://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
//http://msdn.microsoft.com/en-US/library/cby9kycs(v=vs.80).aspx
//dynamic_cast is used for cases where you don't know what the dynamic type of the object is.
//You cannot use dynamic_cast if you downcast and the argument type is not polymorphic.
//The following code is not valid, if Base is not polymorphic (doesn't contain a virtual function):
//dynamic_cast returns a null pointer if the object referred to doesn't contain the type casted to as a base class
//(when you cast to a reference, a bad_cast exception is thrown in that case).
class Base {

	//if you remove this method, the error will be thrown during dynamice_cast:
	//error: cannot dynamic_cast `b' (of type `class Base*') to type `class Derived*' (source type is not polymorphic)
	//but there wont be any problem with static_cast
public:
	virtual void func1() {
		std::cout<<"base::func1 called"<<std::endl;
	}

};

class Derived1 : public Base {
public:
	void func1() {
		std::cout<<"derive::func1 called"<<std::endl;
	}
};

int main() {
  Derived1 d;
  Derived1 d2;
  Base *b = &d;
  //here if the base class is not polymorphic  an error will be thrown.
  dynamic_cast<Derived1*>(b);

  b = new Base();
  Derived1 *d3 = static_cast<Derived1*>(b); // Valid, but it was supposed to be invalid!
  d3->func1();
  Derived1 *d4 = dynamic_cast<Derived1*>(b); // Valid, but d2 is now a null pointer
  if (d4 != NULL)
	  d4->func1();
  else
	  std::cout<<"d4 is null"<<std::endl;


	/*
	 //here doesnt matterather the base class is polymorphic or not, because this upcasting

  Base *b;
  Derived1 *d = new Derived1;
  b = dynamic_cast<Base*>(d);
*/
}

