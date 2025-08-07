#include <iostream>

using namespace std;

/*Function Pointers:
	- Useful in event-driven applications, callbacks, and even for storing the functions in arrays
	
	Syntax: ret_type (*func_ptrName)(arg_type...)

		Eg: int (*funcPtr)(int, int);
*/

//Address of a function can be found using & just like a variable


// 1. Basic program for function pointer

// int func(int a, int b){
// 	return a+b;
// }

// int main(){
// 	cout<<"Address of main is: "<<main<<"\n";
	
// 	int (*func_ptr)(int, int) = func; // or func_ptr = func;
	
// 	int sm = func_ptr(2,4);
// 	cout<<sm<<endl;
// 	return 0;
// }


//2. Passing a function as a param to another func using func pointer
// void func1(){
// 	cout<<"Inside func1\n";

// 	return;
// }

// void func2(void (*func)()){
// 	cout<<"Inside func2\n";
// 	func();

// 	return;
// }

// int main(){
// 	func2(func1);

// 	return 0;
// }

//3. Return a function pointer from a function
// typedef void (*ptr)();

// void func1(){
// 	cout<<"Insied func1\n";
// }

// ptr func2(){
// 	cout<<"Insied func2\n";
// 	void (*pt)() = func1;

// 	return pt;
// }

// int main(){
// 	ptr p = func2();
// 	cout<<"Returned to main\n";
// 	p();

// 	return 0;
// }