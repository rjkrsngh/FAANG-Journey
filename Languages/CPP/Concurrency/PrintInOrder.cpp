/*
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}

The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

Example 1:

Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

Example 2:

Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <condition_variable>

using namespace std;
class Foo {
public:
    std::atomic<int> curr_turn;
    Foo() {
        curr_turn = 1;
    }

    void first() {
        while(curr_turn != 1) this_thread::yield();
        // printFirst() outputs "first". Do not change or remove this line.
        std::cout<<"First";
        curr_turn++;
    }

    void second() {
        while(curr_turn != 2) this_thread::yield();
        // printSecond() outputs "second". Do not change or remove this line.
        std::cout<<"Second";
        curr_turn++;
    }

    void third() {
        while(curr_turn != 3) this_thread::yield();
        // printThird() outputs "third". Do not change or remove this line.
        std::cout<<"Third";
    }
};

int main() {
	Foo obj;
    std::vector<int> test{1,3,2};
        
    std::thread th2(&Foo::third, &obj);
    std::thread th3(&Foo::second, &obj);
    std::thread th1(&Foo::first, &obj);

    th1.join();
    th2.join();
    th3.join();
    

	return 0;
}