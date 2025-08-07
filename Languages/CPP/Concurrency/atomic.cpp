#include <iostream>
#include <syncstream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

/* 1. Objects of atomic types are the only C++ objects that are free from data races; 
      that is, if one thread writes to an atomic object while another thread reads from it, 
      the behavior is well-defined.

   2. In addition, accesses to atomic objects may establish inter-thread synchronization 
      and order non-atomic memory accesses as specified by std::memory_order.

   3. std::atomic is neither copyable nor movable.


   Atomic type aliases: 
   a. atomic<bool> or atomic_bool
   a. atomic<int> or atomic_int
   a. atomic<char> or atomic_char etc...


   Member functions:
   1. is_lock_free: checks if an atomic object is lock free
   2. store: atomically replaces the value of atomic object with non-atomic argument
   3. operator=: stores a value into atomic object
   4. load: atomically loads a value of an atomic object
   5. exchange: atomically replaces the old value with new value and returns the old value
   6. atomic_exchange: atomically replaces the value of the atomic object with non-atomic argument 
   					   and returns the old value of the atomic
   7. wait(since c++20): blocks the thread until notified and the atomic value changes
   8. atomic_wait(since c++20): blocks the thread until notified and the atomic value changes
   9. notify_one(since c++20): notifies at least one object waiting on the atomic object
  10. notify_all(since c++20): notifies all the abjects waiting on the atomic object
  11. atomic_notify_one(c++ 20): notifies a thread blocked on atomic wait
  12. atomic_notify_all(c++ 20): notifies all threads blocked on atomic wait


  Specialized member functions:
  1. fetch_add(arg1, [arg2 - optional]): atomically adds the argument to its value and 
            returns the previously stored value
  2. fetch_sub(arg1, [arg2 - optional]): atomically subtracts the argument to its value and 
            returns the previously stored value
  3. fetch_and(arg1, [arg2 - optional]): atomically perform bitwise AND operation between the 
            argument and the value stored and returns the prevoisly stored value
  4. fetch_or(arg1, [arg2 - optional]): atomicaaly perform bitwise OR operation between the 
            argument and the value stored and returns the previously stored value.
  5. fetch_xor(arg1, [arg2 - optional]): atomically perfomr the bitwise XOR operation between 
            the argument and the value stored and returns the previously stored value.

      a. arg1: value of the second operand
      b. arg2: member of the std::memory model

      Memory models:
         a. std::memory_order_relaxed
         b. std::memory_order_consume
         c. std::memory_order_acquire
         d. std::memory_order_release
         e. std::memory_order_acq_rel
         f. std::memory_order_seq_cst

     operator++
     operator--
     operator+=
     operator-=
     operator|=
     operator&=
     operator^=
*/


/* Example program 1*/
std::atomic_int cntr = {0};
int counter;

void func()
{
	for(int i=0; i<1000000; ++i)
	{
		cntr.fetch_add(1, std::memory_order_relaxed);
		
		// sync writing to prevent from interrupting by other threads
    // osyncstream(std::cout)<<"#id: "<<std::this_thread::get_id()
    // <<", cntr: "<<cntr<<std::endl;

		++counter;
	}
}

int main()
{
	std::vector<std::thread> pool;
	for(int i=0; i<10; ++i) 
	{
		pool.emplace_back(func);
	}
	for(auto& item: pool)
	{
		item.join();
	}

	std::cout<<"cntr: "<<cntr<<", counter: "<<counter<<std::endl;

	return 0;
}



/*Example program 2: use of wait in c++20*/
// int cnt{0};
// std::atomic_bool isEven{true};
// const int MAX_VALUE = 100;

// void printEven()
// {
//    while(cnt < MAX_VALUE)
//    {
//       //std::unique_lock<std::mutex> ulk;
//       isEven.wait(false);

//       if(cnt >= 100) break;
      
//       std::cout<<cnt++<<" ";
//       isEven = false;

//       isEven.notify_one();
//    }
// }

// void printOdd()
// {
//    while(cnt < MAX_VALUE)
//    {
//       //std::unique_lock<std::mutex> ulk;
//       isEven.wait(true);

//       if(cnt >= 100) break;
      
//       std::cout<<cnt++<<" ";
//       isEven = true;

//       isEven.notify_one();
//    }
// }

// int main()
// {
//    std::thread evenThread(printEven);
//    std::thread oddThread(printOdd);

//    evenThread.join();
//    oddThread.join();

//    return 0;
// }