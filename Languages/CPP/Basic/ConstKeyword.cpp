#include <iostream>

using namespace std;

class Test{
int x=0;
public:
	int test() const {
		//Produces error as we are trying to modify a member variable in a read-only method
		x++;
		return x;
	}

	//Even if this is a read-only method, this does not produce error as var y is not a member variable
	int IncY(int y) const {
		y++;
		return y;
	}
};

// auto test(char c) -> int {
// 	return c;
// } 

auto main() -> int {
	Test t;
	cout<<t.test()<<endl;
	cout<<t.IncY(6)<<endl;
	return 0;
}