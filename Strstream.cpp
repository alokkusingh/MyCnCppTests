/*
 * Strstream.cpp
 *
 *  Created on: 08-Sep-2011
 *      Author: Alok
 */

#include <iostream>
#include <sstream>

using namespace std;

int main()
{

	stringstream sstr(stringstream::in | stringstream::out);

	sstr << "1 20 3 4 5";
	sstr << " 25 27";
	int num;
	char *str;

	for (int i = 0; i < 9; i++)
	{
		//sstr >> num;
		//num = num * 2;
		//cout<<num<<" ";
		sstr >> str;
		cout<<str<<" ";
	}

	return 0;
}
