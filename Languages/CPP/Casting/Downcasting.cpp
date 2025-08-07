//Downcasting : Converting the Base class pointer/reference to Derived class pointer/reference
//This needs to be done explictly

#include <iostream>  
using namespace std;  
class Base  
{  
    public:  
        void disp()  
    {  
        cout << "It is the Super function of the Base class\n";  
    }  
};  
  
class Derived : public Base  
{  
    public:  
        void disp()  
        {  
            cout << "It is the derive class function\n";  
        }  
      
};  

int main()
{
    Base b;
    Derived d;

    Derived* d1 = (Derived*)(&b);
    d1->disp();
    
    return 0;
}