#include <iostream>

using namespace std;

// References are internally implemented as pointers
// Their performances are almost same however they have certain differences

// DIFFERENCES
// References cannot have NULL values
// A pointer has its own memory on the stack but a reference has a shared memory alongwith some space on the stack

int main() {
	int a = 5;
	int &ref = a;

	cout<<a<<" "<<ref<<endl; //5 5
	a = 7;
	cout<<a<<" "<<ref<<endl; //7 7
	ref = 9;
	cout<<a<<" "<<ref<<endl;// 9 9

	int b = 11;
	ref = b; // This does not make ref a reference to b, it just takes the value of b and put it in the shared space 
	cout<<a<<" "<<ref<<" "<<b<<endl; // Here a = ref = b = 11

	a = 12;
	b = 13;

	cout<<a<<" "<<ref<<" "<<b<<endl; // Here a = ref = 12, b = 13

	return 0;
}