#include <iostream>

using namespace std;

class Parent {
	public:
		Parent() {
			cout<<"parent constructor called\n";
		};

		virtual void Func(int x) {
			cout<<"From parent\n";
		}

		~Parent() {
			cout<<"parent destructor called\n";
		}
	protected:

	private:
		int _x;
};

class Child : public Parent {
	public:
		Child() : Parent() {
			cout<<"Child constructor called\n";
		};

		void Func(int x) override{
			cout<<"From Child\n";
		}

		~Child() {
			cout<<"child destructor called\n";
		}
	protected:

	private:
		int _x;
};

auto main() -> int {
	Parent* p;
	Child c;

	p = &c;
	p->Func(4);

	return 0;
}