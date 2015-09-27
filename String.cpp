/*
 * String.cpp
 *
 *  Created on: 07-Sep-2011
 *      Author: Alok
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

std::vector<std::string> Tokenize(const std::string &, const std::string &);
void print(const std::string str);
void justTest(int x);

int main()
{
	//string **str = new (string*);

	//2x2 string array
	string **str = new string*[2];
	for (int i = 0; i<2; i++)
		*(str + i) = new string[2];

	str[0][0] = "alok";
	str[0][1] = " singh";

	str[1][0] = "avinash";
	str[1][1] = " singh";

	str[0][0] += 9+48;  //48 ascii value of 0
	str[0][0] += 49.2;

	cout<<"str: "+str[0][0]<<endl;

	for(string::iterator itr = (*str[0]).begin(); itr != (*str[0]).end(); itr++)
		cout<<"char: "<<*itr<<endl;

	cout<<"size: "<<(*str[0]).size()<<endl;
	char *chaStr = const_cast<char *>(str[0][0].c_str());
	cout<<"chaStr: "<<chaStr<<endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout<<str[i][j]<<" ";
		cout<<endl;
	}


	for (int i = 0; i < 2; i++)
		delete *(str + i);
	delete[] str;

	//string line = "02|List Of Action|ICCID|FOSS_Branch_Code|Expiry_Date|Activation_Flag";
	//string line = "02|List Of Action|ICCID|FOSS_Branch_Code|Expiry_Date|Activation_Flag|Default_MSISDN|Nominal_Value";
	//string line = "02|List Of Action|ICCID|FOSS_Branch_Code|Expiry_Date|Activation_Flag|Default_MSISDN";
	//string line = "02|List Of Action|ICCID|FOSS_Branch_Code|Expiry_Date|Activation_Flag||Nominal_Value";
	string line = "02|List Of Action|ICCID|FOSS_Branch_Code|Expiry_Date|Activation_Flag|||";

	size_t charIndex;
	while ((charIndex = line.find("||")) != string::npos)
	{
		line.insert(charIndex + 1, " ");
	}

	cout<<line<<endl;

	vector<string> tokens = Tokenize(line, "|");

	for_each(tokens.begin(), tokens.end(), print);
    cout<<"Size: "<<tokens.size()<<endl;

    justTest(100);
    justTest(100);
	return 0;
}


/* Tokenize a input string based on the delimiter string */

std::vector<std::string> Tokenize(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t p0 = 0, p1 = std::string::npos, p2=0;
    while(p0 != std::string::npos)
    {
        p1 = str.find_first_of(delim,p0);
        if(p1 != p0)
        {
            std::string token = str.substr(p0, p1 - p0);
            tokens.push_back(token);
        }
        p0 = str.find_first_not_of(delim, p1);
    }


    return tokens;
}

void print(const std::string str)
{
	static int i;
	if (str != " ")
	std::cout<<i<<": "<<str<<std::endl;

	i++;
}

void justTest(int x)
{
	static int y = x;
	cout <<"y: "<<y<<endl;
	while (y)
	{
		cout<<"a"<<endl;
		y = y % 100;
	}
}
