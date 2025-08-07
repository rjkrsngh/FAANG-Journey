#include <iostream>

using namespace std;

/*
	1. Pointer holds the memory address whereas refs are aliases for already existing vars
	2. Initialization:
		  Pointers: int* a = &b;
		  Refs: int& x = b; Refs must be initialized during declaration
	3. Reasssignment:
		  Pointers: Can be reassigned
		  Refs: Cannot be reassigned
	4. Memory address:
		  Pointers: Have theri own memory address
		  Refs: Shares the same memory address
	5. NULL:
		  Pointes: Can be assigned with NULL
		  Refs: Cannot be assigned with NULL
	6. Arithmetic Operations:
		  Pointes: Arithmetic Operations can be performed
		  Refs: Cannot be performed

	Refs are internally implemented as pointers and both have the same level of performance.
*/

int main() {
	int a = 5;
	int &ref = a;
	int* ptr = &a;

	cout<< &ref << " "<<&ptr << " " << &a << endl;

	return 0;
}