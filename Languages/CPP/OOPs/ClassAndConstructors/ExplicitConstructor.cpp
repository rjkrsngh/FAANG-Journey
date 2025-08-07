#include <iostream>

using namespace std;

class Test{
	int _x;
public:
	Test() {}
	explicit Test(int x){
		_x = x;
	}

	int getX(){
		return _x;
	}
};

void fun(Test t){
	return;
}

int main() {
	Test t(10);
	Test t1 = 20;

	cout<<t1.getX()<<endl;

	fun(t);
	fun(30);

	return 0;
}