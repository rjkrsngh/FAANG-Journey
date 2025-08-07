#include <iostream>
#include <thread>

using namespace std;

/* Function call op is a binary operator.
	Syntax: primary-expression ( expression-list )
			primary-expression : Operand 1
			expression-list: Operand 2, possibly an empty list of arguments

	1. function-call operator is applied to the name of an object, not the name of a function.
*/

// class test {
// public:
// 	int value;
// 	test() = default;
// 	// 1. void operator() (int n) {
// 	// 	std::cout<<"Function call oerator invoked with value: "<<n<<std::endl;
// 	// }

// 	void operator() (int a, int b, int c) {
// 		test m_obj;
// 		std::cout<<t.value<<std::endl;
// 		m_obj.value = t.value;
// 		return m_obj;
// 	}

// 	int PrintVal() {
// 		std::cout<<"value: "<<value<<std::endl;
// 		return value;
// 	}
// };

// int main() {
// 	test t, t1;
// 	t.value = 5;
// 	// 1. t(5); //object can be used as a function, called functors
// 	t(1,2,3);
// 	//std::cout<<t.PrintVal()<<" "<<t1.PrintVal()<<std::endl;
// 	return 0;
// }

class test 
{
	int _i;
public:
	test(int i): _i{i} {}
	void operator() (int a, int b, int c)
	{
		std::cout<<"Invoked function call op: "<<std::this_thread::get_id()
		<<" "<<t._i<<" "<<a<<" "<<b<<" "<<c<<std::endl;
	}
};

int main() {
	test t(5);
	test t1(90);
	std::thread th1(t1, 1,2,3);

	th1.join();
	return 0;
}