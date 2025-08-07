#include <iostream>

using namespace std;

class Father {
public:
	virtual void Print() {
		std::cout<<"Father says hi!\n";
	}
};

class Child : public Father{
public:
	void Print() override {
		std::cout<<"Child said hello!\n";
	}
};

int main(){
	Father* f = new Child();

	f->Print();

	return 0;
}