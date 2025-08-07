#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

int curr_val = 1;
std::mutex mtx;

void PrintOdd(int upper_limit) {
    std::lock_guard<std::mutex> lk(mtx);
    while(curr_val<=upper_limit) {
        std::cout<<curr_val++<<std::endl;
    }
}

void PrintEven(int upper_limit) {
    std::lock_guard<std::mutex> lk(mtx);
    while(curr_val <= upper_limit) {
        std::cout<<curr_val++<<std::endl;
    }
}
int main() {
    std::thread th1(PrintOdd, 20);
    std::thread th2(PrintEven, 20);

    th1.join();
    th2.join();

    return 0;
}