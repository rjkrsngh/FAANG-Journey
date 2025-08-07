#include <iostream>
#include <mutex>

using namespace std;

std::mutex mtx;

class Singleton {
    static Singleton* obj;
    Singleton() {}

    public:
    static Singleton* getInstance(); 
};

Singleton* Singleton::obj = nullptr;

// Singleton* Singleton::getInstance() {
//     //This method fails in multithreaded environment
//     if(nullptr == obj) {
//         obj = new Singleton();
//     }

//     return obj;
// }


Singleton* Singleton::getInstance() {
    //This is a thread safe implementation of retrieving Singleton obj
    
    ////Method 1
    // mtx.try_lock();
    // if(nullptr == obj) {
    //     obj = new Singleton();
    // }
    // mtx.unlock();

    //Method 2
    {
        std::lock_guard<std::mutex> lock(mtx);
        if(nullptr == obj) {
            obj = new Singleton();
        }
    }

    return obj;
}
