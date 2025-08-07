#include <iostream>
#include <thread>

using namespace std;

void ChangeName(std::string& name) {
    name = "@rks";
}

int main() {
    std::string name = "Raj Kumar";
    
    //to pass a variable by reference, always wrap it in std::ref(var)
    //else it throws a compilation error
    std::thread th(ChangeName, std::ref(name));
    th.join();

    std::cout<<name;
    return 0;
}