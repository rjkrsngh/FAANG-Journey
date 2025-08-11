/*
Given a sorted array arr[] of size n, the goal is to rearrange the array so that all distinct elements appear at the beginning in sorted order. Additionally, return the length of this distinct sorted subarray.

Note: The elements after the distinct ones can be in any order and hold any value, as they don't affect the result.

Examples:

    Input: arr[] = [2, 2, 2, 2, 2]
    Output: [2]
    Explanation: All the elements are 2, So only keep one instance of 2.

    Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
    Output: [1, 2, 3, 4, 5]

    Input: arr[] = [1, 2, 3]
    Output: [1, 2, 3]
    Explanation : No change as all elements are distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* TC: O(n), SC: O(n)*/
vector<int> removeDuplicates(vector<int> &arr)
{
    unordered_set<int> duplicates;
    vector<int> unique;
    for (const auto elem : arr)
    {
        if (duplicates.find(elem) == duplicates.end())
        {
            duplicates.insert(elem);
            unique.push_back(elem);
        }
    }

    return unique;
}

/* TC: O(n), SC: O(k) where k is the number of unique elements*/
vector<int> removeDuplicates(vector<int> &arr)
{
    int uniqueInd{1};
    for (int ind = 1; ind < arr.size(); ++ind)
    {
        if (arr[ind] != arr[ind - 1])
        {
            arr[uniqueInd++] = arr[ind];
        }
    }

    vector<int> unique{arr.begin(), arr.begin() + uniqueInd};
    return unique;
}
