/*
 * DeleteSelf.cpp
 *
 *  Created on: 07-Jun-2012
 *      Author: Alok
 */
#include <iostream>

class test
{
    int i;
    public:
    	~test()
    	{
    		std::cout<<"Destructor called"<<std::endl;
    	}
        void print()
        {
        	std::cout << "value of I = "<<i<<std::endl;
        	//delete this;
        }
        void increment ()
        {
        	i++;
        }

};

void func(int *p)
{ *p = 11; }

void func1(char **t)
{ *t = "Alok";}


int main() {
	test t;
	t.print();
	t.print();

	//int &a = 10; //error: invalid initialization of non-const reference of type `int&' from a temporary of type `int'
	int I = 100;
	int &j = I;
	int &k = j;
	k++;
	std::cout <<I <<j <<k <<std::endl;


    char * p = "Hello";
	*p='M';
	p="Happy";
    std::cout<<p<<std::endl;

    int l=10; func(&l);
    std::cout<<l<<std::endl; //what is the value of l???
    func1(&p);
    std::cout<<p<<std::endl; //what is the value of p???
	return 0;
}
