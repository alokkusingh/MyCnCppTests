/*
 * Set.cpp
 *
 *  Created on: 26-Apr-2012
 *      Author: Alok
 */

/*
 * Map_class.cpp
 *
 *  Created on: 29-Aug-2011
 *      Author: Alok
 */

#include <iostream>
#include <set>
#include <string>
#include <cstdlib> //for atoi
#include <algorithm> //for atoi

using namespace std;

struct compare;

class CKey {
	string id;
	int value;
public:
	CKey()
	{
		id = "0";
		value = 0;
	}
	CKey(const string id, const int value)
	{
		this->id = id;
		this->value = value;
	}
	CKey (const CKey& k)
	{
		this->id = k.id;
		this->value = k.value;
	}
	bool operator<(CKey k) const
	{
		std::cout<<"CKey::operator< called to compare this["<< *this<<"] with ["<<k<<"]"<<std::endl;
		if (id < k.id)
		{
			return true;
		}
		return false;
	}
	string getId () const
	{
		return id;
	}
	int getValue() const
	{
		return value;
	}
	friend ostream& operator<<(ostream&, CKey);
}; //close of class CKey

ostream& operator<<(ostream& out, CKey k)
{
	out<<"ID: "<<k.id<<", Value: "<<k.value;
	return out;
}

void print(const CKey k)
{
	std::cout<<"ID: "<<k.getId()<<", Value: "<<k.getValue()<<std::endl;
}

struct compare {
	bool operator()(const CKey a, const CKey b) const
	{
		std::cout<<"compare called to compare ["<< a<<"] with ["<<b<<"]"<<std::endl;
		if(atoi(a.getId().c_str()) < atoi(b.getId().c_str()))
			return true;
		else
			return false;
	}
};

int main ()
{
	//set<CKey> setKey;			//since "operator<" is comparing key as string the the key 10 will be after 1 and before 2
	set<CKey, compare> setKey;	//since "compare" is comparing key as int the the key 10 will be after 9
	set<CKey>::iterator itr;

	CKey key("1", 1203);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("1", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	//this should not be added because key is same
	setKey.insert(key);

	key = CKey("2", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("7", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("6", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("5", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("4", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("3", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("8", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("9", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

	key = CKey("10", 1204);
	std::cout<<"Adding in set: ["<<key<<"]"<<std::endl;
	setKey.insert(key);

    //lets iterate and see what happened
	std::cout<<"Now lets iterate"<<std::endl;;
	for (itr = setKey.begin(); itr != setKey.end(); ++itr)
		std::cout<<*itr<<std::endl;

	std::cout<<"Iterating using for_each"<<std::endl;
	for_each(setKey.begin(), setKey.end(), print);

	std::cout<<"Iterating using for_each"<<std::endl;
	for_each(setKey.begin(), setKey.end(), print);

	return 0;
}


