#include <iostream>

using namespace std;

class test
{
	//int _i;
public:
	//test(int i): _i{i} {}
	test() = default;

	void* operator new(std::size_t size)
	{
		std::cout<<"Called new with size: "<<size<<std::endl;
		return malloc(size);
	}

	void operator delete(void* p)
	{
		std::cout<<"Called delete\n";
		free(p);
	}

	//void printData() {std::cout<<_i<<std::endl;}

	~test() {}
};

int main()
{
	test* t = new test();
	//t->printData();
	delete t;

	return 0;
}


//Global overloading of new and delete operators
// void* operator new(size_t size) {
// 	std::cout<<"Invoked new operator with size: "<<size<<std::endl;
// 	return malloc(size);
// }

// void operator delete(void* p) {
// 	std::cout<<"Invoked delete operator\n";
// 	free(p);
// }


// void* operator new [](size_t size) {
// 	std::cout<<"Invoked new[] operator with size: "<<size<<std::endl;
// 	return malloc(size);
// }

// void operator delete [](void* p) {
// 	std::cout<<"Invoked delete[] operator\n";
// 	free(p);
// }

// int main() {
// 	//int* i = new int;
// 	int* i_arr = new int[5];

// 	//delete i;
// 	delete[] i_arr;

// 	return 0;
// }