/*
 * for_each.cpp
 *
 *  Created on: 01-Sep-2011
 *      Author: Alok
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct functor {
	void operator()(string str)
	{
		cout<<"String: "<<str<<endl;
	}
};

int main()
{
	vector<string> vNames;
	vNames.push_back("Alok");
	vNames.push_back("Singh");

	for_each(vNames.begin(), vNames.end(), functor());

	return 0;
}
