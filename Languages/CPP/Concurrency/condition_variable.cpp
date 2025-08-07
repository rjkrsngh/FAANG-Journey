#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


/* Condition variable: A synchronization primitive used with std::mutex to block one or more
   threads untill a thread modifies a shared variable(the condition) and notifies the cv

   Any thread that tries to modify a shared variable must:
   1. Acquire a std::mutex(typically via std::lock_guard)
   2. Modify the shared variable while the lock is acquired.
      Even if the shared variable is atomic, the modification must be done only while owning
      the std::mutex to correctly publish the modification to the waiting thread
   3. Call notify_one or notify_all on the cv object(can be done after releasing the lock)

   Any thread that intends to wait on a condition_variable must:
   1. Acquire a std::unique_lock<std::mutex> on the mutex used to protect the shared variable
   2. Do one of the following:
      a. Check the condition, in case it was already update on notified
      b. Call wait, wait_for or wait_until on the cv object to atomically to release the mutex 
         and suspend the thread execution until the cv object is notified, a timeout expires,
         or a spurious wakeup occurs, then atomically acquires the mutex before returning
      c. Check the condition and resume waiting if not satisfied 

   Condition variable works only with std::unique_lock<std::mutex> which allows for maximum 
   efficiency on some platforms.

   std::condition_variable_any provides a cv object that works with any BasicLockable object 
   like shared_lock

   Condition variable permits concurrent invocation of wait, wait_for, wait_until, notify_one
   and notify_all member functions

   Waiting methods:
   1. wait(lock, stop_waiting): blocks the current thread until the cv is awakened.
   2. wait_for(lock, rel_time, stop_waiting): blocks the current thread until the cv is  
   			   awakened or until specified time has been elapsed
   3. wait_until(lock, timeout_time, stop_waiting): causes the current thread to block until the cv is notified or a specific
                  time is reached or a spurious wakeup occurs, optionally looping until a 
                  predicate is satisfied.

      a. lock: an instance of std::unique_lock<std::mutex> which must be locked by the
      		   current thread.
      b. stop_waiting: predicate to determine if waiting should be stopped or not
               if true, stop waiting else continue waiting.
      c. rel_time: an object of type std::chrono::duration representing the maximum time to 
                spend waiting. Note that rel_time must be small enough not to overflow when 
                added to std::chrono::steady_clock::now().
      d. timeout_time: an objec of std::chrono::time_point representing the time when to 
      			stop waiting.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

// std::mutex mtx;
// std::condition_variable cv;
// bool isEven{true};
// int cnt{0};
// const int MAX_VALUE = 100;

// void printEven()
// {
// 	while(cnt < MAX_VALUE)
// 	{
// 		std::unique_lock<std::mutex> ulk;
// 		cv.wait(ulk, [&]{return isEven;});

// 		if(cnt >= 100) break;
		
// 		std::cout<<cnt++<<" ";
// 		isEven = false;

// 		cv.notify_one();
// 	}
// }

// void printOdd()
// {
// 	while(cnt < MAX_VALUE)
// 	{
// 		std::unique_lock<std::mutex> ulk;
// 		cv.wait(ulk, [&]{return !isEven;});

// 		if(cnt >= 100) break;
		
// 		std::cout<<cnt++<<" ";
// 		isEven = true;

// 		cv.notify_one();
// 	}
// }

