#include <iostream>
#include <thread>

using namespace std;

std::thread::id main_thread_id;

void PrintEven(){
    for(int i=0; i<=10; ++i){
        std::cout<<" From Even ->"<< std::this_thread::get_id()<< " i: "<<i<<std::endl;
    }
}

void PrintOdd(){
    for(int i=0; i<=10; ++i){
        std::cout<<" From Odd ->"<< std::this_thread::get_id()<< " i: "<<i<<std::endl;
    }
}

int main() {
    std::cout<<"Id of main thread: "<<std::this_thread::get_id()<<std::endl;

    std::thread th1(PrintEven);
    //std::cout<<"id of th1: "<<th1.get_id()<<std::endl;
    std::thread th2(PrintOdd);

    th1.join();
    th2.join();

    //Get the number of threads supported by your system
    unsigned int num_of_threads = std::thread::hardware_concurrency();
    std::cout<<"Number of concurrent threds: "<<num_of_threads<<std::endl;

    return 0;
}