#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Test {
public:
    Test() {}
    void Print(){
        std::cout<<"Hello from Print\n";
    }

    void operator() () {
        Print();
    }
};

int main() {
    Test t;
    std::thread th(t);

    th.join();

    return 0;
}
