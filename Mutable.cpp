/*
 * Mutable.cpp
 *
 *  Created on: 26-Aug-2011
 *      Author: Alok
 */

class A
{
  public:
    A() : x(4), y(5) { };
    mutable int x;
    int y;

    void modify() const
    {
    	//since this method is const declare the method only can modify mutable storage variable
    	x = 1;		//possible
    	//y = 1;	//not possible
    }
};

int main()
{
  const A var2;
  var2.x = 345;		//this is mutable so can be modified
  //var2.y = 2345;	//this is not possible

  var2.modify();
  return 0;
}
