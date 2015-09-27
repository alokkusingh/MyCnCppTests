#include <iostream>

class abc
{

public:
    abc(int x)
    {
       this->x = x;
    }

    abc(const abc& x)
    {
        this->x = x.x;
    }

    void print()
    {
        std::cout<<x<<std::endl;

    }

    abc operator++(const int)
    {
        abc temp = *this; 
        ++(this->x);
        return temp;
    } 

    abc& operator++()
    {
        (this->x)++;
        return *this;
    }


    friend abc& operator+(const int, const abc&);

    
private:
    int x;

};



abc& operator+(const int x, const abc& a)
{
    int y;
    y =  x + a.x;
    return *(new abc(y));
}

int main()
{

    int x = 10;
    abc a(x);

    a.print();

    (10 + a).print();

    (a++).print();
    a.print();

    (++a).print();
    a.print();

    return 0;
}
