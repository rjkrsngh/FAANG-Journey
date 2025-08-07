#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
int curr_value = 1;
std::condition_variable cv;

void PrintOdd(int u_lim) {
    std::unique_lock<std::mutex> lk{mtx};
    while(curr_value < u_lim) {
        // cv.wait(lk, []{ 
        //     return (curr_value%2!=1) ? true : false;
        // });
        cv.wait(lk,[] {return (curr_value%2!=0) ? true : false;});
        std::cout<<curr_value++<<std::endl;
        cv.notify_one();
    }
}

void PrintEven(int u_lim) {
    std::unique_lock<std::mutex> lk{mtx};
    while(curr_value <= u_lim) {
        // cv.wait(lk, []{ 
        //     return (curr_value%2!=0) ? true : false;
        // });
        cv.wait(lk,[] {return (curr_value%2==0) ? true : false;});
        std::cout<<curr_value++<<std::endl;
        cv.notify_one();
    }
}

int main() {
    std::thread th1(PrintOdd, 20);
    std::thread th2(PrintEven, 20);

    th1.join();
    th2.join();

    return 0;
}