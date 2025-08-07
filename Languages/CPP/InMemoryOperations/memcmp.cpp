#include <iostream>
#include <cstring>

using namespace std;

/*  memcmp(buff1, buff2, std::size_t n): compares the first n bytes of buff1 against buff2. 
	The comparison is done lexicographically.

	signature: memcmp(const void* buff1, const void* buff2, std::size_t n)

	int result = memcmp(arr1, arr2, n)
	result < 0 : first different byte in arr1 is less than the corresponding byte in arr2
	result > 0 : first different byte in arr1 is greater than the corresponding byte in arr2
	result == 0: n bytes of arr1 and arr2 are same.
*/

struct test{
	std::string name_;
	int age_;
	int ssn_;
	test(std::string name, int age, int ssn)
	{
		name_ = name;
		age_ = age;
		ssn_ = ssn;
	}

	~test() {}
};

int main()
{
	char arr1[] = {'a', 'b', 'c'};
	char arr2[] = {'a', 'b', 'd'};
	size_t sz = sizeof(arr1);

	int result = memcmp(arr1, arr2, sz);
	if(result < 0) 
	{
		std::cout<<std::string(arr1, sz)<<" precedes "<<std::string(arr2, sz)<<std::endl;
	}
	else if(result == 0)
	{
		std::cout<<std::string(arr1, sz)<<" is same as "<<std::string(arr2, sz)<<std::endl;
	}
	else
	{
		std::cout<<std::string(arr1, sz)<<" comes after "<<std::string(arr2, sz)<<std::endl;
	}

	test obj1("abc", 1,1);
	test obj2("bbc", 1,0);
	
	result = memcmp(&obj1, &obj2, sizeof(test));
	if(result < 0) 
	{
		std::cout<<"Obj with ssn: "<<obj1.ssn_<<" comes first"<<std::endl;
	}
	else if(result == 0)
	{
		std::cout<<"Objects are same"<<std::endl;
	}
	else
	{
		std::cout<<"Obj with ssn: "<<obj2.ssn_<<" comes first"<<std::endl;
	}
	return 0;
}