
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> findTwoElement(std::vector<int> &arr)
{
    int duplicate{-1};
    for (int i = 0; i < arr.size(); ++i)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0)
        {
            duplicate = abs(arr[i]);
        }
        else
        {
            arr[index] = -arr[index];
        }
    }

    int missing{-1};
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }

    return std::vector<int>{duplicate, missing};
}

int main()
{
    std::vector<int> list{6, 5, 8, 7, 1, 4, 1, 3, 2};
    auto res = findTwoElement(list);
    std::cout << "num of items: " << res.size() << std::endl;

    return 0;
}