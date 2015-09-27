/*
 * Map_class.cpp
 *
 *  Created on: 29-Aug-2011
 *      Author: Alok
 */

/*
 * Note: The insert() function will not insert the element if the element is already in the map,
 * whereas operator []() will update the element if it already exists.
 */
#include <iostream>
#include <map>

using namespace std;

struct compare;

class keyValue {
	string name;
	int age;

public:
	class key {
		int id;
		int comp_id;
	public:
		key()
		{
			id = 0;
			comp_id = 0;
		}

		key (int id, int comp_id)
		{
			this->id = id;
			this->comp_id = comp_id;
		}

		key (const key& k)
		{
			this->id = k.id;
			this->comp_id = k.comp_id;
		}

		bool operator<(key k) const
		{
			std::cout<<"key::operator< called to compare this["<< *this<<"] with ["<<k<<"]"<<std::endl;
			if (comp_id == k.comp_id)
			{
				if(this->id < k.id)
					return true;

				return false;
			}
			else
			{
				if(this->comp_id < k.comp_id)
					return true;

				return false;
			}
		}

		int getId () const
		{
			return id;
		}

		int getComp_id() const
		{
			return comp_id;
		}
		friend ostream& operator<<(ostream&, keyValue::key);
	}; //close of class key

	keyValue()
	{

	}

	keyValue(int comp_id, int id, string name, int age)
	{
		this->name = name;
		this->age = age;
		ke = key(id, comp_id);
	}

	keyValue(const keyValue& kv)
	{
		this->name = kv.name;
		this->age = kv.age;
		ke = kv.ke;
	}

	key getKey()
	{
		return ke;
	}

	void setAge(int age)
	{
		this->age = age;
	}
	friend ostream& operator<<(ostream&, keyValue);
private:
	key ke;
};

ostream& operator<<(ostream& out, keyValue::key k)
{
	out<<"Comp ID: "<<k.comp_id<<", ID: "<<k.id;
	return out;
}

ostream& operator<<(ostream& out, keyValue a)
{
	out<<a.ke<<", Name: "<<a.name<<", Age: "<<a.age<<endl;
	return out;
}

struct compare {
	bool operator()(const keyValue::key a, const keyValue::key b) const
	{
		std::cout<<"compare called to compare ["<< a<<"] with ["<<b<<"]"<<std::endl;
		if (a.getComp_id() == b.getComp_id())
		{
			if(a.getId() < b.getId())
				return true;

			return false;
		}
		else
		{
			if(a.getComp_id() < b.getComp_id())
				return true;

			return false;
		}
	}
};

int main ()
{
	map<keyValue::key, keyValue> mapKeyValue;
	map<keyValue::key, keyValue>::iterator itr;

	keyValue keyVal(1, 1203, "alok", 28);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue[keyVal.getKey()] = keyVal;

	keyVal = keyValue(1, 1204, "ashish", 29);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue[keyVal.getKey()] = keyVal;

	keyVal = keyValue(2, 1202, "amit", 29);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue[keyVal.getKey()] = keyVal;

	keyVal = keyValue(2, 1203, "abhijeet", 29);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue[keyVal.getKey()] = keyVal;

	std::cout<<"Calling size"<<std::endl;
	cout<<"Size: "<<mapKeyValue.size()<<endl;

	mapKeyValue[keyVal.getKey()].setAge(10);
	//std::cout<<"Calling find from: "<<mapKeyValue<<std::endl;
	itr = mapKeyValue.find(keyVal.getKey());
	if (itr != mapKeyValue.end())
		cout<<itr->second;

	//here I am passing functor to comare 2 elements
	map<keyValue::key, keyValue, compare> mapKeyValue2;
	keyVal = keyValue(4, 1205, "test", 28);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue2[keyVal.getKey()] = keyVal;

	//since I passed functor so < will not be called to comapre, intead functor "comapre" will get called
	keyVal = keyValue(3, 1206, "test2", 28);
	std::cout<<"Adding in map: ["<<keyVal<<"]";
	mapKeyValue2[keyVal.getKey()] = keyVal;

	std::cout<<"Iterating MAP"<<std::endl;
	for (map<keyValue::key, keyValue>::iterator itr = mapKeyValue.begin(); itr != mapKeyValue.end(); itr++)
	{
		cout<<itr->second;
	}



	return 0;
}


