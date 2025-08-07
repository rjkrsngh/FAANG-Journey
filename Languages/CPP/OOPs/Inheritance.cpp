#include <iostream>

using namespace std;

class Parent {
	private:
		int _x, _y;
		// Private members are accessible only inside the class
	protected:
		// These members are accessible only by itself and the class inheriting it
		int getY(){return _y;}
	public:
		//These members are accessible everywhere
		Parent(int x, int y) : _x{x}, _y{y} {}
		int getX(){return _x;}
};

/* If a class is inherited :
	a. public : All public and protected members of the Parent class become availabe publicly in the child class
	b. protected : All public and protected members of the Parent class become availabe as protected in the child class
	c. private : All public and protected members of the Parent class become availabe as private in the child class*/

class Child : protected Parent{
	int _a, _b;

	public:
		Child(int a, int b) : Parent(a, b), _a{a}, _b{b} {}
		// int getA(){return getX();}
		// int getB(){return getY();}
};

class Test : protected Child{
	private:

	protected:

	public:
		Test(int a, int b) : Child(a, b) {}
};

int main(){
	Test t(1,2);
	cout<<t.getX()<<endl;
	return 0;
}