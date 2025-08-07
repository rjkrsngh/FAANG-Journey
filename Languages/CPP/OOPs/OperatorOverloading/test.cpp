#include <iostream>

using namespace std;

void* operator new(size_t size)
{
	std::cout<<"Called new with size: "<<size<<std::endl;
	return malloc(size);
}

void* operator new[](std::size_t size)
{
	std::cout<<"Called new[] with size: "<<size<<std::endl;
	return malloc(size);
}

void operator delete(void* ptr)
{
	std::cout<<"Called delete"<<std::endl;
	free(ptr);
}

void operator delete[](void* ptr)
{
	std::cout<<"Called delete[]"<<std::endl;
	free(ptr);
}

int main()
{
	int* i_obj = new int;
	int* i_arrObj = new int[10];
	delete i_obj;
	delete[] i_arrObj;

	return 0;
}