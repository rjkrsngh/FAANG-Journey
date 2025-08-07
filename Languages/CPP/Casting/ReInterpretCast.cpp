#include <iostream>

using namespace std;

/*  Def: reinterpret_cast is a very special and dangerous type of casting operator. 
		And is suggested to use it using proper data type i.e., (pointer data type should be same as original data type).
	
	Note0: It can typecast any pointer to any other data type.
	Note1: It is used when we want to work with bits.
	Note2: If we use this type of cast then it becomes a non-portable product. 
		   So, it is suggested not to use this concept unless required.
	Note3: It is only used to typecast any pointer to its original type.
	Note4: Boolean value will be converted into integer value i.e., 0 for false and 1 for true.
*/

class Parent {
	public:
		void PrintValParent(){
			cout<<"From Parent\n";
			return;
		}
};

class Child {
	public:
		void PrintValChild(){
			cout<<"From Child\n";
			return;
		}
};

class Child1 {
	public:
		void PrintValChild1(){
			cout<<"From Child1\n";
			return;
		}
};


int main() {
    // int* ptr = new int(65);
    // char* ch = reinterpret_cast<char*>(ptr);
    // cout << *ptr << endl;
    // cout << *ch << endl;
    // cout << ptr << endl;
    // cout << ch << endl;

	Parent* p = new Parent();
	Child* c = new Child();

	Child* c1 = reinterpret_cast<Child*>(p);
	c1->PrintValChild();
	if(NULL == c1){
		cout<<"c1 -> Not Null\n";
		c1->PrintValChild();
	}else{
		cout<<"c1 -> Null\n";
	}

	return 0;
}