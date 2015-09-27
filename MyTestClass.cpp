#include <iostream>
#include <cstring>

class MyTestClass {

    public:
        MyTestClass (const char *str) {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        }

        MyTestClass (const MyTestClass &classObj) {
            this->str = new char[strlen(classObj.str) + 1];
            strcpy(this->str, classObj.str);
        }

        MyTestClass& operator=(const MyTestClass &classObj) {
            if (this == &classObj)
                return *this;

            delete this->str;
            this->str = new char[strlen(classObj.str) + 1];
            strcpy(this->str, classObj.str); 
            return *this;
        }
        
        void print() {
            std::cout<<"String: "<<this->str<<std::endl; 
        }

    private:
        char *str;


};

int main() {

    MyTestClass myClass("Alok Singh");
    myClass.print();

    MyTestClass my2ndClass(myClass);
    my2ndClass.print();  

    MyTestClass my3rdClass("Avinash Singh");
    my2ndClass = my3rdClass;
    my2ndClass.print();  

    my2ndClass = my2ndClass;
    my2ndClass.print();  

    return 0;
}
