#include <iostream>

using namespace std;

class Parent {
	public:
		Parent() {};

		void func(int x) {
			cout<<"Func from parent\n";
		}

		void func(float y){
			cout<<"float from parent\n";
		}
	protected:

	private:
		int _x;
};

class Child : public Parent {
	public:
		Child() {};

	protected:

	private:
};


auto main() -> int {
	Parent* p;
	//Child c;
	//p = &c;

	p->func(3.9f);

	return 0;
}