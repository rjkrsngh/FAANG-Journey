#include <iostream>
#include <vector>

using namespace std;

/*
Given a sorted array arr[] of integers (in ascending order), rearrange the elements in-place to form a wave-like array.
An array is said to be in wave form if it satisfies the following pattern: arr[0] ≥ arr[1] ≤ arr[2] ≥ arr[3] ≤ arr[4] ≥ ...
In other words, every even-indexed element should be greater than or equal to its adjacent odd-indexed elements (if they exist).

Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

    Input: arr[] = [1, 2, 3, 4, 5]
    Output: [2, 1, 4, 3, 5]
    Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.

    Input: arr[] = [2, 4, 7, 8, 9, 10]
    Output: [4, 2, 8, 7, 10, 9]
    Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.
*/

void sortInWave(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i += 2)
    {
        swap(arr[i], arr[i - 1]);
    }
}

int main()
{
    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7};

    sortInWave(arr);
    std::cout << "After sorting in wave form: ";
    for (const auto elem : arr)
        std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}