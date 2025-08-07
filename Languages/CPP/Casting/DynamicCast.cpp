#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* dynamic_cast is mainly used for proper downcasting at runtime, can also be used for up-casting

	Note0 : Works only in Polymorphic scenario i.e, Needs at least one virtual function in the base class
	Note1 : If the cast is successful, it returns the value of the new type
	Note2 : If the cast fails and the new_type is a pointer type, it returns a NULL pointer of that type
	Note3 : If the cast fails and the new_type is a reference type, it throws an exception that matches
			a handler of type std::bad_cast  
	Note4 : Inter-child conversion results in NULL
*/

class Parent{
	public:
		virtual void PrintVal(){
			cout<<"From Parent\n";
		}

};

class Child : public Parent{
	public:
		void PrintVal() {
			cout<<"From Child\n";
		}
};

class Child1 : public Parent{
	public:
		void PrintVal() {
			cout<<"From Child1\n";
		}
};

int main()
{
	// Child c;
	// Parent* p = dynamic_cast<Parent*>(&c);  //Base class object holding Child class object 

	// //This is Dynamic Casting, typically downcasting
	// Child* c1 = dynamic_cast<Child*>(p);
	// if(NULL != c1){
	// 	cout<<"c1 is not NULL\n";
	// 	c1->PrintVal();
	// }else{
	// 	cout<<"c1 is NULL\n";
	// }


	// Child c;
	// Parent* p = dynamic_cast<Parent*>(&c);  //This is Dynamic Casting, typically downcasting
	
	// Child1* c1 = dynamic_cast<Child1*>(p);
	// if(NULL != c1){
	// 	cout<<"c1 is not NULL\n";
	// 	c1->PrintVal();
	// }else{
	// 	cout<<"c1 is NULL\n";
	// }


	// Parent p1;
	// //Child Class objects holds Parent class object
	// Child* c2 = dynamic_cast<Child*>(&p1);
	// Parent* p2 = dynamic_cast<Parent*>(c2);
	// if(NULL != p2){
	// 	cout<<"p2 is not NULL\n";
	// 	p2->PrintVal();
	// }else{
	// 	cout<<"p2 is NULL\n";
	// }

	return 0;
}

// int main() {
// 	Child c;
// 	Parent* p = dynamic_cast<Parent*>(&c); // Allowed
// 	if(p){
// 		cout<<"p -> Not Null\n";
// 		p->PrintVal();
// 	}
// 	else{
// 		cout<<"p -> Null\n";
// 	}

// 	Parent p1;
// 	Child* c1 = dynamic_cast<Child*>(p1);   // Allowed
// 	if(c1){
// 		cout<<"c1 -> Not Null\n";
// 		c1->PrintVal();
// 	}
// 	else{
// 		cout<<"c1 -> Null\n";
// 	}
	
// 	Child1* c2 = dynamic_cast<Child1*>(p);  // Not Allowed, results in NULL
// 	if(c2){
// 		cout<<"C2 -> Not Null\n";
// 		c2->PrintVal();
// 	}
// 	else{
// 		cout<<"C2 -> Null\n";
// 	}

// 	Child1* c3 = dynamic_cast<Child1*>(c1); // Not Allowed, results in NULL
// 	if(c3){
// 		cout<<"c3 -> Not Null\n";
// 		c3->PrintVal();
// 	}
// 	else{
// 		cout<<"c3 -> Null\n";
// 	}

// 	return 0;
// }