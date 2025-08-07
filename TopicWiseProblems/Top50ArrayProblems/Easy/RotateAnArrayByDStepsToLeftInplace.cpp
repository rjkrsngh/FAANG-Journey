#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateLeftByDStepsInplace(std::vector<int> &list, int d)
{
    std::reverse(list.begin(), list.end());
    std::reverse(list.begin(), list.end() - d);
    std::reverse(list.end() - d, list.end());
}

int main()
{
    std::vector<int> listOfItems{1, 2, 3, 4, 5};
    rotateLeftByDStepsInplace(listOfItems, 2);

    std::cout << "After rotation: ";
    for (const auto &elem : listOfItems)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}