#include<iostream>

using namespace std;

class Parent{};

class Child: public Parent{};

int main(){
	//Parent* p = new Child();
	Child* c = new Parent();
	return 0;
}