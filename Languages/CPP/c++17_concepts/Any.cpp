#include <iostream>
#include <any>

using namespace std;

int main() {
	std::any item = 1;
	std::cout<<item.type().name()<<" : "<< std::any_cast<int>(item)<<std::endl;

	item = 3.14;
	std::cout<<item.type().name()<<" : "<<std::any_cast<double>(item)<<std::endl;

	item = true;
	std::cout<<item.type().name()<<" : "<<std::any_cast<bool>(item)<<std::endl;

	//If there is a type mismatch while casting, bad_any_cast exception is thrown
	try {
		item = 5;
		std::cout<<std::any_cast<float>(item)<<std::endl;
	}catch(std::bad_any_cast& e) {
		std::cout<<std::endl<<e.what()<<std::endl;
	}

	//use has_value() to check if an obj of any type contains a value
	item = 1;
	if(item.has_value()) {
		std::cout<<item.type().name()<<" : "<<std::any_cast<int>(item)<<std::endl;
	}

	// use reset() to remove the value contained in the obj of any type
	// after this operation, has_value() will return false
	item.reset();
	if(!item.has_value()) {
		std::cout<<"Object is empty"<<std::endl;
	}

	std::any var = 1;
	std::cout<<typeid(var).name()<<std::endl;

	return 0;
}