#include <iostream>
#include <thread>

using namespace std;

struct test {
    int i_;
    test() : i_{0} {}
    test(int i) : i_{i} {}

    void operator() (const int x, int& y) {
        for(int i=0; i<x; ++i) {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        y = 2*x;
    }
};

int main() {
    int x = 50;
    int y = 0;
    test t;
    std::thread th(t, x, std::ref(y));
    
    if(th.joinable()) {
        th.join();
    }

    std::cout<<x<<" "<<y<<std::endl;

    return 0;
}