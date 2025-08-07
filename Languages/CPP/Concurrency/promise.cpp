#include <iostream>
#include <future>
#include <thread>

using namespace std;

/* promise: a facility to store a value or an exception that is later acquired asynchronously
			by a std::future obj created by the std::promise obj.

   NOTE: std::promise obj can be used only once.


   Getting the result:
   1. get_future: Returns a future object associated with the same shared state as *this.

   Setting the result:
   1. set_value(value): Atomically stores the value into the shared state and makes the state ready.
   2. set_value_at_thread_exit(value): Stores the value atomically into the shared state but makes the
   		state ready only when the thread exits after destroying all thread-local memory.
   3. set_exception(p): sets the result to indicate an exception.
   4. set_exception_at_thread_exit(p): Stores the exception pointer p into the shared state but makes
   		the shared state ready only when the thread exits after destroying all thread-local memory.
*/


int main()
{
	std::promise<int> p;
	std::future<int> fObj = p.get_future();

	std::thread th([&]{
		try{
			// Normal scenario to demonstrate promises
			// std::this_thread::sleep_for(5000ms);
			// p.set_value(101);

			// Demonstrate exception in promise
			throw std::runtime_error("Exception example");
		}
		catch(...)
		{
			p.set_exception(std::current_exception());
		}
	});

	try{
		int value = fObj.get();
		std::cout<<"result: "<<value<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<"Exception1: "<<e.what()<<std::endl;
	}

	th.join();

	return 0;
}