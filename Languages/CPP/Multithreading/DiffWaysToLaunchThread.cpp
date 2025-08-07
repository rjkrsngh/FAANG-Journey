#include <iostream>
#include <thread>

using namespace std;

class ThreadClass {
public:
	ThreadClass() {
		std::cout<<"Inside ctor\n";
	}

	void operator() () const {
		std::cout<<"Inside f_call operator\n";
	}
};

void func() {
	for(int i=0; i<5; ++i) {
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
}

int main() {
	/* Method 1: Function call */
	//std::thread my_thread(func/*param list*/);

	/* Method 2: Using function objects */
	// ThreadClass t;
	// //t(); //this make the object as a function object
	// std::thread my_thread(t); //this invokes the function call operator
	
	/* Method 3: The extra parantheses prevents its interpretation as a function declaration 
	   and allows my_thread to be a variable of type std::thread*/
	// std::thread my_thread((ThreadClass()));

	/* Method 4: Uniform Initialization*/
	// std::thread my_thread{ThreadClass()}; 

	/* Method 5: Using lambda expression */
	// std::thread my_thread([/*capture clause*/](/*params list*/){
	// 	/*operation to be performed on the thread */
	// });

	if(my_thread.joinable()){
		my_thread.join();
	}

	return 0;
}