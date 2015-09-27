/*
 * MyString.cpp
 *
 *  Created on: 24-Sep-2011
 *      Author: Alok
 */

#include <iostream>
#include <cstring>

using namespace std;

void my_reverse(const char *, char *);

int my_atoi(const char *);

int main()
{
	char ip[] = "Alok the great";
	char *op = new char[strlen(ip) + 1];

	my_reverse(ip, op);

	cout<<"Actual: "<<ip<<endl;
	cout<<"Reverserd: "<<op<<endl;

	int total = my_atoi("-25") + my_atoi("-30.2");

	cout<<"Total: "<<total<<endl;

	return 0;
}

void my_reverse(const char * ip, char * op)
{
	int i = 0;
	for (; ip[i] && ip[i] != ' '; i++);

	if(ip[i])
		my_reverse((ip + i + 1), op);

	strncat(op, ip, i);
	strcat(op, " ");
}

int my_atoi(const char *a)
{
	int total = 0, mult = 0;
	for(int i = 0; a[i]; i++)
	{
		if (a[i] == '.')
			break;
		if (a[i] >= '0' && a[i] <= '9')
		{
			mult *= 10;
			total = ((mult * total) + a[i] - '0');
		}
	}

	if (a[0] == '-')
		total = -total;

	return total;

}

