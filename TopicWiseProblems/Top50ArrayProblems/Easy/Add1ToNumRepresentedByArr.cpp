/*
Given a non-negative number represented as an array of digits. The is to add 1 to the number (increment the number represented by the digits by 1). The digits are stored such that the most significant digit is the first element of the array.

Examples :

    Input : [1, 2, 4]
    Output : 125
    Explanation: 124 + 1 = 125

    Input : [9, 9, 9]
    Output: 1000
    Explanation: 999 + 1 = 1000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> addOne(vector<int> &arr)
{
    int carry{1};
    vector<int> result;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        int sum = arr[i] + carry;
        carry = sum > 9 ? 1 : 0;

        int digit = sum % 10;
        result.push_back(digit);
    }

    if (carry == 1)
        result.push_back(carry);

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    std::vector<int> items{9, 9, 9};
    addOne(items);

    std::cout << "Number after adding 1: ";
    for (const auto &elem : items)
        std::cout << elem;

    std::cout << std::endl;

    return 0;
}