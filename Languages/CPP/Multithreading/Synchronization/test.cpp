#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

#include <queue>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cond_var;

void PopulateQ() {
    //wait for 5 secs
    std::cout<<"thread with th_id: "<<std::this_thread::get_id()<<" sleeping for 5 secs\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"thread with th_id: "<<std::this_thread::get_id()<<" is now awake\n";

    //acquire the lock to push element to queue
    std::lock_guard<std::mutex> lk(mtx);
    q.push(5);

    //notify the waiting thread
    cond_var.notify_one();
}

void PrintQ() {
    std::cout<<"Printing queue value on thread: "<<std::this_thread::get_id()<<std::endl;
    std::unique_lock<std::mutex> ul(mtx);

    //wait here till the queue is empty
    std::cout<<"b4 waiting\n";
    cond_var.wait(ul, []{return !q.empty();});
    
    std::cout<<"wait period over\n";
    int data = q.front();
    q.pop();

    ul.unlock();

    std::cout<<"value got from the queue is: "<<data<<std::endl;
}


int main() {
    std::thread th1(PopulateQ);
    std::thread th2(PrintQ);

    th1.join();
    th2.join();

    return 0;
}