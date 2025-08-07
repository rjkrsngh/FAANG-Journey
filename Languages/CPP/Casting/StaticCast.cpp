#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Static Cast - It is a compile time cast

/* 
 1. It performs implicit conversion between types
	Though we have C-Style conversion, we need static_cast because it is hard to detect C-Style conversion in code
	and it is easier to search static_cast in code and handle issues releated to it.

    If Inheritance not involved, casting does not happpen and it results in error
	In case of Inheritance, upcasting is proper, downcasting is not proper and inter-child casting raises error.
*/

// int main() {
// 	int x = 10;
// 	float f = 10.7f;

// 	int r = static_cast<int>(f);
// 	int r1 = f; // will perform the same operation as static_cast


// 	cout<<r<<endl;
// 	return 0;
// }



/* 2. Use static_cast when conversion between types is provided through conversion operator or conversion constructor */

// class Int {
// 	int _x;
// 	public:
// 		Int(int x = 0) : _x{x} {}

// 		operator string(){
// 			cout<<"Converting to string\n";
// 			return to_string(_x);
// 		}

// 		int getX(){
// 			return _x;
// 		}
// };

// int main(){
// 	Int obj(5);

// 	string st = obj;
// 	obj = 20;

// 	cout<<st<<" "<<obj.getX()<<endl;
	
// 	string s = static_cast<string>(obj);
// 	cout<<s<<endl;

// 	obj = static_cast<Int>(78);
// 	cout<<obj.getX()<<endl;
// 	return 0;
// }




/* 3. Use for upcasts but dont use for downcasts */
class Parent {
public:
	Parent(){
		cout<<"Parent constructor called\n";
	}

	void test(){
		cout<<"test called from parent\n";
		return;
	}
};

class Child : public Parent {
public:
	Child(){
		cout<<"constructor of Child\n";
	}

	void testChild(){
		cout<<"test from child\n";
	}
};

class Child1 : public Parent {
public:
	Child1(){
		cout<<"constructor of Child1\n";
	}

	void testChild1(){
		cout<<"test from child1\n";
	}
};

int main() {
	Child c;
	Child1 c1;

	//Block 1 : Works as expected
	// Parent* p = static_cast<Parent*>(&c);
	// p->test();
	// Parent* p1 = static_cast<Parent*>(&c1);
	// p1->test();
	//Block 1 ends

	//Block 2: Results in Error as conversion not possible from parent to child
	Parent pa;
	
	Child* ca = static_cast<Child*>(pa);
	Child1* cb = static_cast<Child1*>(pa);
	//Block 2 ends

	return 0;
}


/* 4. Use static_cast to converto to and from void* */

