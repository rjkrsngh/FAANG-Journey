#include<iostream>

using namespace std;

//1. Any class having a constructor that needs only 1 argument is called the conversion constructor

class Test{
	int _x;
public:
	Test(int _x=0){
		cout<<"constructor called with value: "<<_x<<"\n";
		this->_x = _x;
	}

	void display(){
		cout<<_x<<"\n";
	}
};

int main(){
	Test t(10);
	t.display();

	t = 50; // Conversion Constructor called
	t.display();

	return 0;
}

//2. We can also create conversion constructor with multiple parameters using the initializer list
class Test{
	int _x, _y;
public:
	Test(int _x=0){
		cout<<"constructor called with value: "<<_x<<"\n";
		this->_x = _x;
	}

	Test(int _x, int _y){
		cout<<"constructor called with value: "<<_x<<" "<<_y<<"\n";
		this->_x = _x;
		this->_y = _y;
	}

	void display(){
		cout<<_x<<" "<<_y<<"\n";
	}
};

int main(){
	Test t(10);
	//t.display();

	t = {50,90}; // Conversion Constructor called
	t.display();

	return 0;
}