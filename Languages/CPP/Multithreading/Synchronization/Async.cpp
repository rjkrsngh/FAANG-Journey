// #include <iostream>
// #include <future>
// #include <unistd.h>

// int GetValue() {
// 	sleep(3);
// 	return 21;
// }

// int main() {
// 	std::future<int> ret_val = std::async(GetValue);

// 	ret_val.wait();
// 	std::cout<<"Returned value is: "<<ret_val.get() << std::endl;

// 	for(int i=0; i<5; ++i){
// 		std::cout<<i<<std::endl;
// 	}

// 	// ret_val.wait();
// 	// std::cout<<"Returned value is: "<< ret_val.get() <<std::endl;

// 	return 0;
// }









#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>

int GetVal(int a, int b)
{
	//std::this_thread::sleep_for(5);
	sleep(5);
	return a+b;
}

int main()
{
	//std::thread th1(GetVal);
	std::future<int> ret_value = std::async(GetVal, 50, 100);

	for(int i=0; i<50; ++i)
	{
		std::cout<< i << " ";
	}

	std::cout<< std::endl;

	ret_value.wait();
	std::cout<< "Value returned is: "<< ret_value.get() << std::endl;

	return 0;
}


























