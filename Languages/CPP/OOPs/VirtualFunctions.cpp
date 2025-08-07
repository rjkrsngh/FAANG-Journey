#include <iostream>
#include <memory>

using namespace std;

class Parent{
	int i, j;
public:
	Parent(int i_, int j_) : i{i_}, j{j_} {}

	virtual void PrintFunc(){
		std::cout<<"Printing from Parent\n";
	}
};

class Child : public Parent{
	int i, j;
public:
	Child(int i_, int j_) : Parent(i_, j_) {}

	void PrintFunc(){
		std::cout<<"Print from Child\n";
	}
};	

int main()
{
	unique_ptr<Parent> parent(new Child(1,2));

	parent->PrintFunc();

	return 0;
}