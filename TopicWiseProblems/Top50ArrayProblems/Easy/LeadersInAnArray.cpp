/*
Given an array arr[] of size n, the task is to find all the Leaders in the array. An element is a Leader if it is greater than or equal to all the elements to its right side.

Note: The rightmost element is always a leader.

Examples:

    Input: arr[] = [16, 17, 4, 3, 5, 2]
    Output: [17 5 2]
    Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2], therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.

    Input: arr[] = [1, 2, 3, 4, 5, 2]
    Output: [5 2]
    Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(vector<int> &arr)
{
    vector<int> result;
    int maxElem{arr.back()};

    result.push_back(maxElem);
    for (int i = arr.size() - 2; i >= 0; --i)
    {
        if (arr[i] >= maxElem)
        {
            maxElem = arr[i];
            result.push_back(maxElem);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> items{1, 2, 3, 4, 5};
    leaders(items);

    return 0;
}