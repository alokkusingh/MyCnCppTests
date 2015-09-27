/*
 * CopyConstructor.cpp
 *
 *  Created on: 08-Sep-2011
 *      Author: Alok
 */
#include <iostream>

using namespace std;

class abc {
	int i, j;

public:
	abc(int i, int j)
	{
		cout<<"Normal constructor called"<<endl;
		this->i = i;
		this->j = j;
	}

	abc(const abc& a)
	{
		cout<<"Copy Constructor called"<<endl;
		i = a.i;
		j = a.j;
	}


	void myFunc(const abc& a)
	{
		cout<<"myFunc called"<<endl;
		cout<<a.i<<" "<<a.j<<endl;

	}

	friend void myFriend(abc& a);
};

void myFriend(abc& a)
{
	//friend can access private memeber also
	a.i = 10;
}

int main()
{
	abc a(1, 2);
	abc b = a;

	b.myFunc(a);

	myFriend(a);

	b.myFunc(a);

	return 0;
}
