/*
 * Map.cpp
 *
 *  Created on: 29-Aug-2011
 *      Author: Alok
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, string> mapPhoneDirec;

	mapPhoneDirec.insert(make_pair("alok", "9916661247"));
	mapPhoneDirec.insert(pair<string, string>("singh", "9945739428"));
	mapPhoneDirec.insert(map<string, string>::value_type("papa", "9431191688"));

	for (map<string, string>::iterator itr = mapPhoneDirec.begin(); itr != mapPhoneDirec.end(); itr++)
		cout<<"Name: "<<itr->first<<", number: "<<itr->second<<endl;

	cout<<"Size: "<<mapPhoneDirec.size()<<endl;
	cout<<"Max Size: "<<mapPhoneDirec.max_size()<<endl;
	cout<<"Size: "<<mapPhoneDirec.size()<<endl;
	cout<<"Empty: "<<mapPhoneDirec.empty()<<endl;

	mapPhoneDirec.erase("alok");
	mapPhoneDirec.erase(mapPhoneDirec.begin());

	for (map<string, string>::iterator itr = mapPhoneDirec.begin(); itr != mapPhoneDirec.end(); itr++)
			cout<<"Name: "<<itr->first<<", number: "<<itr->second<<endl;

	cout<<"Empty: "<<mapPhoneDirec.empty()<<endl;

	mapPhoneDirec["aloks"] =  "9916661247";
	mapPhoneDirec["alok"] = "9916661248";

	map<string, string>::iterator itr = mapPhoneDirec.find("alok");
	map<string, string>::iterator itr1 = mapPhoneDirec.find("aloks");
	if (itr != mapPhoneDirec.end())
		cout<<"Find (alok): "<<itr->second<<endl;

	int count = mapPhoneDirec.count("aloks");
	cout<<"Count: "<<count<<endl;

	//cout<<"Value Comapre: "<<mapPhoneDirec.value_comp()(*itr, *itr1)<<endl;

	mapPhoneDirec.clear();

	return 0;
}
