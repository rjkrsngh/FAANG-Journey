/*
Given an array arr[] of size n, find the element that appears more than ⌊n/2⌋ times. If no such element exists, return -1.

Examples:

    Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
    Output: 1
    Explanation: Element 1 appears 4 times. Since ⌊7/2⌋ = 3, and 4 > 3, it is the majority element.

    Input: arr[] = [7]
    Output: 7
    Explanation: Element 7 appears once. Since ⌊1/2⌋ = 0, and 1 > 0, it is the majority element.

    Input: arr[] = [2, 13]
    Output: -1
    Explanation: No element appears more than ⌊2/2⌋ = 1 time, so there is no majority element.

    Link: https://www.geeksforgeeks.org/dsa/majority-element/
*/

#include <iostream>
#include <vector>

using namespace std;

/*Approach 1: Using nested loops. TC: O(n^2), SC: O(1)*/
/*Approach 2: Using sorting. TC: O(nlogn), SC: O(1)*/
/*Approach 3: Using unordered map. TC: O(1), SC: O(n)*/

/*Approach 4: Single pass count + validation - Moore's voting algorithm. TC: O(n), SC: O(1)*/
int majorityElement(vector<int> &arr)
{
    if (arr.size() == 1)
        return arr[0];

    int elem{arr[0]}, cnt{1};
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == elem)
        {
            ++cnt;
        }
        else
        {
            if (--cnt == 0)
            {
                cnt = 1;
                elem = arr[i];
            }
        }
    }

    if (cnt > 0)
    {
        cnt = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == elem)
            {
                ++cnt;
            }
        }

        if (cnt > arr.size() / 2)
            return elem;
    }

    return -1;
}