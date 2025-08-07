#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5,6};
    std::vector<int> v3{7,8,9};

    std::cout<<"Memory address of vectors after creation\n";
    std::cout<<&v1<<std::endl;
    std::cout<<&v2<<std::endl;
    std::cout<<&v3<<std::endl;

    v1 = v2;
    std::cout<<"Address of v1 after assigning v2 with it is: "<<&v1<<", Address of v2: "<<&v2<<std::endl;
    for(int item : v1) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    v1.assign(v3.begin(), v3.end());
    std::cout<<"Address of v1 after assigning v3 with it is: "<<&v1<<", Address of v2: "<<&v3<<std::endl;
    for(int item : v1) {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;

    return 0;
}