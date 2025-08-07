#include <iostream>
#include <thread>
#include <memory>

using namespace std;

class Thread {
    public:
    std::string name;

    Thread(std::string name): name{name} {}
    ~Thread() {}

    void PrintName(std::string str) {
        std::cout<<"My name is : "<<str<<std::endl;
    }
};

int main() {
    //passing a unique pointer to the thread gives compilation error as the 
    //thread tries to make a copy of the unique pointer taking away its uniqueness.
    //std::unique_ptr<Thread> t = std::make_unique<Thread>("bac");


    std::shared_ptr<Thread> t = std::make_shared<Thread>("bac");
    //Thread *t = new Thread("abc");
    std::thread th(&Thread::PrintName, t, "Raj kumar");
    th.join();
    return 0;
}