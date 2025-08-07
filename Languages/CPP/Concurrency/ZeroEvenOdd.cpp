/*You have a function printNumber that can be called with an integer parameter and prints it to the console.

    For example, calling printNumber(7) prints 7 to the console.

You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

    Thread A: calls zero() that should only output 0's.
    Thread B: calls even() that should only output even numbers.
    Thread C: calls odd() that should only output odd numbers.

Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

    ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
    void zero(printNumber) Calls printNumber to output one zero.
    void even(printNumber) Calls printNumber to output one even number.
    void odd(printNumber) Calls printNumber to output one odd number.

 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.

Example 2:

Input: n = 5
Output: "0102030405"
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool isZero;
    int currNum;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->isZero = true;
        this->currNum = 0;
    }

    void printNumber(int num) {
        std::cout<<num;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero() { //function<void(int)> printNumber) {
        int i=0;
        while(i<n) {
            std::unique_lock<std::mutex> ulk{mtx};
            cv.wait(ulk, [&]{ return isZero; });
            printNumber(0);
            i++;
            isZero = false;
            currNum++;
            ulk.unlock();
            cv.notify_all();
        }
    }

    void even() {//function<void(int)> printNumber) {
        int j = 2;
        while(j<=n) {
            std::unique_lock<std::mutex> ulk{mtx};
            cv.wait(ulk, [&]{ return (!isZero && (currNum%2==0)); });
            printNumber(currNum);
            isZero = true;
            j+=2;
            ulk.unlock();
            cv.notify_all();
        }
    }

    void odd() {//function<void(int)> printNumber) {
        int k = 1;
        while(k<=n) {
            std::unique_lock<std::mutex> ulk{mtx};
            cv.wait(ulk, [&]{ return (!isZero && (currNum%2==1)); });
            printNumber(currNum);
            isZero = true;
            k+=2;
            ulk.unlock();
            cv.notify_all();
        }   
    }
};


int main() {
    ZeroEvenOdd obj(5);

    std::thread th1(&ZeroEvenOdd::zero, &obj);
    std::thread th2(&ZeroEvenOdd::even, &obj);
    std::thread th3(&ZeroEvenOdd::odd, &obj);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}