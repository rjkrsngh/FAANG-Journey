//Upcasting : Converting the Derived class pointer/reference to Base class pointer/reference
//Always allowed in public inheritance without explicit cast
//Performs is-a relationship between Base and Derived class

#include <iostream>  
using namespace std;  
class Base  
{  
    public:  
        void disp1()  
    {  
        cout << " It is the Super function of the Base class ";  
    }  
};  
  
class Derived : public Base  
{  
    public:  
        void disp()  
        {  
            cout << "\n It is the derive class function ";  
        }  
      
};  
  
int main ()  
{  
    Base b;
    Derived d;

    Base* b1 = &d;

    b1->disp1();
    d.disp();

    return 0;  
}  