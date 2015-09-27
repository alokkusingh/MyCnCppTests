/*
 * Vector.cpp
 *
 *  Created on: 07-Sep-2011
 *      Author: Alok
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> vecStrName;
	int arr[] = {1,2,3,4};

	vecStrName.push_back("Alok");
	vecStrName.push_back("Manash");
	vecStrName.push_back("Amit");
	vecStrName.push_back("Ashish");

	for(vector<string>::iterator itr = vecStrName.begin(); itr != vecStrName.end(); itr++)
		cout<<*itr<<endl;

	try {
		int *myarray= new int[1000000000];
		//int *myarray= new (nothrow) int[1000000000];  //if nothrow is not mentioned there is a chance to thow exception bad_alloc
		//throw const_cast<string*>(new string("hello"));
		//throw new string("hello");
		//throw string("hello");
		cout<<vecStrName[4]<<endl;  //here it will be core dumped
		//this is not an exception, it generates SIGSEGV signal.
	}
	catch (char x)
	{
		cout<<"exception Char: "<<x<<endl;
	}
	catch (long x)
	{
		cout<<"exception long: "<<x<<endl;
	}
	catch (int x)
	{
		cout<<"exception int: "<<x<<endl;
	}
	catch (string x)
	{
		cout<<"exception string: "<<x<<endl;
	}
	catch (string* x)
	{
		cout<<"exception string pointer: "<<*x<<endl;
	}
	catch (bad_alloc&)
	{
	  cout << "Error allocating memory." << endl;
	}
	catch (...)
	{
		//control wont come to here
		cout<<"excetion cought"<<endl;
	}

	//cout<<arr[4]<<endl;  //here it wont be core dumped

	return 0;
}
