#include <iostream>
using namespace std;

class MoveConstructor
{
	int* _data;
public:
	MoveConstructor() { _data = new int(0);}
	MoveConstructor(int d){
		std::cout<<"Object created"<<std::endl;
		_data = new int;
		*_data = d;
	}

	//Copy constructor
	MoveConstructor(const MoveConstructor& obj) {
		std::cout<<"Copy Ctor"<<std::endl;
		_data = new int;
		*_data = *obj._data;
	}

	MoveConstructor& operator=(const MoveConstructor& obj){
		std::cout<<"Copy = invoked"<<std::endl;
		if(_data == nullptr){
			_data = new int;
		}

		*_data = *obj._data;
		return *this;
	}

	//Move constructor
	MoveConstructor(MoveConstructor&& obj) {
		std::cout<<"Move Ctor"<<std::endl;
		_data = new int;
		*_data = *obj._data;

		obj._data = nullptr;
	}

	MoveConstructor& operator=(MoveConstructor&& obj) {
		std::cout<<"Move = invoked"<<std::endl;
		delete _data;

		_data = obj._data;
		obj._data = nullptr;

		return *this;
	}

	~MoveConstructor()
	{
		delete _data;
		_data = nullptr;
	}

	int getData() { return *_data; }
};

int main()
{	
	MoveConstructor mv(5);
	std::cout<<mv.getData()<<std::endl;

	MoveConstructor obj = mv;
	std::cout<<obj.getData()<<std::endl;

	MoveConstructor obj1 = std::move(obj);
	std::cout<<obj1.getData()<<std::endl;

	obj = obj1;//should invoke copy assignment operator
	obj1 = std::move(obj); //should invoke move assignment operator

	return 0;
}