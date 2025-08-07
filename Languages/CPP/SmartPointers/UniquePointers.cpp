#include <iostream>
#include <memory>

using namespace std;

/* ---------------------------------------------------------------------------------------------------
 	Unique Pointers: 
		-> Concept: there can only be one pointer to an object

	
			Syntax: unique_ptr<Rectangle> p(new Rectangle);

		-> Process: 
			- let p1 be pointing to an object Obj
			- while making p2 to point to Obj, p1 is made NULL and the Obj is assigned to p2
   ----------------------------------------------------------------------------------------------------*/

class Rectangle {
    int length;
    int breadth;
 
public:
	Rectangle() = default;

    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
 
    int area(){
        return length * breadth;
    }
};

int main() {
	unique_ptr<Rectangle> r(new Rectangle(2,3));
	cout<<&r<<" "<<r->area()<<endl;

	unique_ptr<Rectangle> rr;
	rr = move(r);
	cout<<&rr<<" "<<rr->area()<<endl;

	if(!r){
		cout<<"r is NULL";
	}

	return 0;
}