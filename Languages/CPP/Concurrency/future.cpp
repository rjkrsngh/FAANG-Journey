

/* future: provides a mechanism to access the result of asynchronous operations
	
   1. An asynchronous operation(created via std::async, std::packaged_task, or std::promise) 
      can provide a std::future obj to the creator of the async task.
   2. The creator of the async operation can then use a variety of methods to query, wait for 
      or extract a value from the std::future obj. These methods may block if the async operation
      has not yet yielded a value.
   3. When the async operation is ready to send a result to std::future obj of the creator, it can 
      do so by modifying the shared state(eg: std::promise::set_value) that is linked to the 
      std::future obj of the creator.

   Note that std::future references shared state that is not shared with any other asynchronous 
   return objects (as opposed to std::shared_future).

   IMP: To reference the shared state with other shared objects, use std::shared_future

   Member functions:
   1. share: transfers the shared state from *this to a std::shared_future object and returns it
   2. get: Waits until the std::future obj has a valid result and returns the result when available.

   State:
   1. valid: Checks if a std::future obj refers to a shared state
   2. wait: Block further execution until the result is available
   3. wait_for(timeout_duration): Wait for a specified duration or until the result is available, 
   				whichever occurs first. The return value identifies the state of the result.

   				timeout_duration: maximum duration to block for

   4. wait_until(timeout_time): waits for the result until specified time point has been reached 
   				or the result is available, whichever is first

				timeout_time: maximum time point to block until

   		NOTE:	If the future is the result of a call to async that used lazy evaluation, 
   				this function returns immediately without waiting.
*/


#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main()
{
	std::promise<int> p; //create a promise object
	std::future<int> f_obj = p.get_future();

	std::cout<<"Created future object\n";
	std::thread th([&p]{
		try{
			std::this_thread::sleep_for(10000ms);
			p.set_value(5);
		}
		catch(...)
		{
			std::cout<<"Exception caught\n";
		}
	});

	std::cout<<"breakpoint 1\n";
	try{
		int result = f_obj.get();
		std::cout<<"result received: "<<result<<std::endl;
	}
	catch(...){
		std::cout<<"Exception caught while getting future value"<<std::endl;
	}

	std::cout<<"breakpoint 2\n";
	th.join();

	return 0;
}