#include <iostream>
#include <string>

using namespace std;

/* Conversion Operator : Implicit conversion of one primitive type to another
	It is similar to operator overloading 

	Syntax: operator primitive_type(){
				convert and return
			}
*/

class Int{
	int _x;
public:
	Int(int x = 0) : _x{x} {}

	operator string(){
		return to_string(_x);
	}
} ;

int main(){
	Int x(5);
	string st = x;
	cout<<st<<"\n";

	return 0;
}