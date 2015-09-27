#include <iostream>
#include <memory>

using namespace std;

class abc {
	unsigned int x : 3;
	public:
		abc(unsigned y)
		{
			x = y;
		}
		void print()
		{
			cout<<x<<endl;
		}
};

int main() {

    abc obj(8);

    obj.print();

    auto_ptr<int> one(new int);
    *one = 10;
    auto_ptr<int> two = one; //one is empty now
    cout<<"two: "<<*two<<endl;
    //cout<<"one: "<<*one<<endl;  //segmentation fault

    auto_ptr<int> three(new int);
    three = two;	//two is emty now
    cout<<"three: "<<*three<<endl;
    //cout<<"two: "<<*two<<endl;	//segmentation fault

return 0;
}
