#include <iostream>

using namespace std;

class A{
public:
	virtual void Print()
	{
		std::cout<<"Print from A\n";
	}
};

class B: public A{
public:
	void Print()
	{
		std::cout<<"Print from B\n";
	}
};

class C: public B{
public:
	void Print()
	{
		std::cout<<"Print from C\n";
	}
};

int main()
{
	A* a = new A();
	B* b = new B();
	C* c = new C();

	a = c;
	a->Print();

	return 0;
}