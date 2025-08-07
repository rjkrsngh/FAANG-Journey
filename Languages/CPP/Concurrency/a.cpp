#include <iostream>

using namespace std;


class test {
	int* i;
public:
	test(int value) {
		i = new int;
		*i = value;
		std::cout<<"Default ctor called\n";
	}

	test(const test& obj) {
		std::cout<<"Copy ctor called\n";
		i = new int;
		*i = *obj.i;
	}

	void operator=(const test& obj) {
		std::cout<<"Assignment operator called\n";
		//i = new int;
		i = obj.i;
	}

	int PrintData() {
		return *i;
	}

	void SetData(int value) {
		*i = value;
	}
};

int main() {
	test obj1(5);
	test obj2 = obj1;
	test obj3(obj1);

	obj3 = obj2;
	std::cout<<obj2.PrintData()<<" "<<obj3.PrintData()<<std::endl;
	obj3.SetData(10);
	std::cout<<obj2.PrintData()<<" "<<obj3.PrintData()<<std::endl;

	return 0;
}