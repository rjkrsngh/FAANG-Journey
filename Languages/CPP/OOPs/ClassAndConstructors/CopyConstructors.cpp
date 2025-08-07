#include <bits/stdc++.h>

using namespace std;

/* Copy Constructors:
	- Helps to create a new object using already existing object
	- The default or compiler generated copy constructor performs shallow copy of objects
	- Always define your own copy constructor whenever a pointer is involved

	Shallow Copy: Copy all data members as it is(no new memory allocation)
	Deep Copy: First allocates new memory dynamically, then copies the data members

*/

// class CopyConstTest{
// 	public:
// 		int a, b;
// 		CopyConstTest(int a, int b) : a{a}, b{b} {};
// 		CopyConstTest(CopyConstTest& obj){
// 			this->a = obj.a;
// 			this->b = obj.b;
// 		}
		
// 		void PrintVal(){
// 			cout<<a<<" "<<b<<endl;
// 		}
// };

// int main(){
// 	CopyConstTest obj1(1,2);
// 	CopyConstTest obj2 = obj1; //Copy constructor works here
// 	obj2 = obj1; //Copy constructor doesnt work here
// 	obj1.PrintVal();
// 	obj2.PrintVal();
	
// 	return 0;
// }



// Shallow Copy
class CopyClass{
	int data;
	int* ptr;

public:
	CopyClass() : data{0}, ptr{new int(0)} {}

	//If this copy constructor is commented, shallow copy is performed, else deep copy
	CopyClass(const CopyClass& obj){
		data = obj.data;
		ptr = new int;
		*ptr = *obj.ptr;
	}

	void SetData(int d){
		this->data = d;
		cout<<"data set\n";
	}

	void SetPtr(int val){
		*ptr = val;
	}

	void PrintVals(){
		cout<<data<<" "<<*ptr<<endl;
	}
};


int main(){
	cout<<"Inside main\n";

	CopyClass c;
	c.SetPtr(1);
	c.SetData(2);

	c.PrintVals();

	CopyClass nc = c;
	nc.PrintVals();

	nc.SetPtr(5);
	
	c.PrintVals();
	nc.PrintVals();

	return 0;
}
