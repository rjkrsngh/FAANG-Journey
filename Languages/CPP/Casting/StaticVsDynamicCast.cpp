#include <iostream>

using namespace std;

/*  Static Cast:

	If Inheritance not involved, casting does not happpen
	In case of Inheritance, upcasting is proper, downcasting is not proper and inter-child casting provides error 
*/

class Parent{
	public:
		virtual void PrintVal(){
			cout<<"From Parent\n";
		}

};

class Child : public Parent{
	public:
		void PrintVal() override {
			cout<<"From Child\n";
		}
};

class Child1 : public Parent{
	public:
		void PrintVal() override {
			cout<<"From Child1\n";
		}
};

/* Dynamic Cast -> Polymorphism must be involved

	Interchild casting results in NULL
*/

int main() {
	Child c;
	Parent* p = dynamic_cast<Parent*>(&c); // Allowed
	Child* c1 = dynamic_cast<Child*>(p);   // Allowed
	
	Child1* c2 = dynamic_cast<Child1*>(p);  // Not Allowed, results in NULL
	Child1* c3 = dynamic_cast<Child1*>(c1); // Not Allowed, results in NULL

	if(p){
		cout<<"p -> Not Null\n";
		p->PrintVal();
	}
	else{
		cout<<"p -> Null\n";
	}

	if(c1){
		cout<<"c1 -> Not Null\n";
		c1->PrintVal();
	}
	else{
		cout<<"c1 -> Null\n";
	}

	if(c2){
		cout<<"C2 -> Not Null\n";
		c2->PrintVal();
	}
	else{
		cout<<"C2 -> Null\n";
	}

	if(c3){
		cout<<"c3 -> Not Null\n";
		c3->PrintVal();
	}
	else{
		cout<<"c3 -> Null\n";
	}

	return 0;
}

//Use to test static_cast

// int main(){
// 	Parent p;
// 	Child1* c1 = static_cast<Child1*>(&p);

// 	Parent* p1 = static_cast<Parent*>(c1);
// 	Child* c = static_cast<Child*>(c1);

// 	if(c1){
// 		cout<<"C1 -> Not null\n";
// 		c1->PrintVal();
// 	}else{
// 		cout<<"C1 -> Null\n";
// 	}

// 	if(p1){
// 		cout<<"P1 -> Not null\n";
// 		p1->PrintVal();
// 	}else{
// 		cout<<"P1 -> Null\n";
// 	}

// 	if(c){
// 		cout<<"C -> Not null\n";
// 		p1->PrintVal();
// 	}else{
// 		cout<<"C -> Null\n";
// 	}

// 	return 0;
// }


