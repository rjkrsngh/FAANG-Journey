#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintEven(int x){
    std::cout<<&x<<std::endl;
    for(int i=0; i<=10; ++i){
        continue;
    }
}

int main() {
    int x = 9;
    std::cout<<&x<<std::endl;
    std::thread th(PrintEven, x);

    th.join();
    
    return 0;
}