#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <string> //sasur ji: 7549976943
#include <condition_variable>

using namespace std;

std::mutex mtx;
std::condition_variable cv;

std::string str_data;

bool ready {false};
bool processed {false};

void worker_func() {
    //wait until main thread sends data
    std::unique_lock ul(mtx);
    cv.wait(ul, []{return ready;});

    //after waiting, this func owns the lock
    std::cout<<"worker thread is procecssing data\n";
    str_data += " after processing";

    //send data back to main
    processed = true;
    std::cout<<"worker thread signals that data processing is complete\n";

    ul.unlock();
    cv.notify_one();
}

int main() {
    std::thread worker(worker_func);
    
    str_data = "dummy data";
    //send data to worker thread
    {
        std::lock_guard lg(mtx);
        ready = true;
        std::cout<<"main() signals data ready for processing\n";
    }
    cv.notify_one();

    //wait for worker to complete
    {
        std::unique_lock ul(mtx);
        cv.wait(ul, []{return processed;});
    }
    std::cout<<"back to main: data: "<<str_data<<std::endl;

    worker.join();

    return 0;
}