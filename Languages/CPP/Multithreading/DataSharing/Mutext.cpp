#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>
#include <list>

std::mutex mtx;

std::list<int> d_list;

void add_to_list(int data){
    mtx.lock();
    d_list.push_back(data);
    mtx.lock();
}

bool contains(int data){
    bool result = false;
    
    mtx.lock();
    result = (d_list.find(d_list.begin(), d_list.end(), data) != d_list.end());
    mtx.unlock();

    return result;
}