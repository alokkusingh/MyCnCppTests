/*
 * DiamonInheritance.cpp
 *
 *  Created on: 31-Aug-2011
 *      Author: Alok
 */
#include <iostream>

class Animal {
 public:
   virtual void eat() {}

};

class Mammal : virtual public  Animal {
 public:
   //virtual void eat() {}
   void walk();
};

class WingedAnimal : virtual public  Animal {
 public:
   //virtual void eat() {}
   void flap();
};

// A bat is a winged mammal
class Bat : public Mammal, public WingedAnimal {
public:
	//void eat() {}
};

int main()
{
	Bat bat;
	bat.eat();
    //bat.Mammal::eat();
	//Animal a = (Animal) (Mammal) Bat();

	return 0;
}
