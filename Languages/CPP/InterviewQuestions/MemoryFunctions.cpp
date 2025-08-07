#include <iostream>
#include <cstring>

using namespace std;

typedef struct test{
	int x;
	std::string name;

	test(): x{-1}, name{""} {}
	test(int x, std::string name) : x{x}, name{name} {}

	void Print(){
		std::cout<<x<<" "<<name<<std::endl;
	}
} Test;

void Memcpy()
{
	//this function implements std::memcpy(addr_destination, addr_source, size_to_be_copied), returns void
	// size_to_be_copied <= sizeof(destination)

	/*//---------------------------------------------------------------------------------------------
	//Example: 1
	char source[] = "This is a test string";
	char destination[5];

	memcpy(destination, source, sizeof(destination));

	for(char c : destination)
	{
		std::cout<<c;
	}

	std::cout<<std::endl;

	//ERROR: Never print this array directly
	//std::cout<<destination<<std::endl; 

    //-----------------------------------------------------------------------------------------------*/

	/*//----------------------------------------------------------------------------------------------
	//Example: 2
	Test obj1(1, "Raj");
	Test obj2;

	obj1.Print();
	obj2.Print();

	memcpy(&obj2, &obj1, sizeof(obj2));
	
	obj1.Print();
	obj2.Print();

	---------------------------------------------------------------------------------------------------*/
}

void Memcmp()
{
	/*this function implements std::memcmp(ptr_buf1, ptr_buf2, size_of_cmp) 
	 returns <0 -> buf1 is less than buff2
	 		  0 -> buf1 is same as buf2
	 		 >0 -> buf1 is greater than buf2*/

	/*char arr1[] = "this is a test array of string";
	char arr2[] = "array 2";

	int result = std::memcmp(arr1, arr2, sizeof(arr1));

	if(result < 0) std::cout<<"Array 1 is less than array \n2";
	else if(result == 0) std::cout<<"Array 1 is equal to array \n2";
	else std::cout<<"Array 1 is greater than array \n2"; */

	Test obj1(2, "Raj");
	Test obj2(1, "Raj");

	int res = std::memcmp(&obj1, &obj2, sizeof(obj1));
	std::cout<<res<<std::endl;

	return;
}

int main()
{
	//Memcpy();
	//Memcmp();

	return 0;
}