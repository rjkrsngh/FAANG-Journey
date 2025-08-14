/*
Given an array arr[] consisting of n integers, find all the array elements which occurs more than floor(n/3) times.
Note: The returned array of majority elements should be sorted.

Examples:

    Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
    Output: [1, 2]
    Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

    Input: arr[] = [-5, 3, -5]
    Output: [-5]
    Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

    Input: arr[] = [3, 2, 2, 4, 1, 4]
    Output: [ ]
    Explanation: There is no majority element.

    Link: https://www.geeksforgeeks.org/dsa/find-all-array-elements-occurring-more-than-floor-of-n-divided-by-3-times/
*/

#include <iostream>
#include <vector>

using namespace std;

/*Approach 1: Using nested loops. TC: O(n^2), SC: O(1)*/
/*Approach 2: Using sorting. TC: O(nlogn), SC: O(1)*/
/*Approach 3: Using unordered map. TC: O(1), SC: O(n)*/

/*Approach 4: Modified Moore's algorithm*/
vector<int> majorityElement(vector<int> &nums)
{
    int elem1{-1}, cnt1{0};
    int elem2{-1}, cnt2{0};
    int n = nums.size();
    int minCnt = n / 3;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == elem1)
        {
            ++cnt1;
        }
        else if (nums[i] == elem2)
        {
            ++cnt2;
        }
        else if (cnt1 == 0)
        {
            elem1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            elem2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            --cnt1;
            --cnt2;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == elem1)
        {
            ++cnt1;
        }
        else if (nums[i] == elem2)
        {
            ++cnt2;
        }
    }

    vector<int> result;
    if (cnt1 > minCnt)
        result.push_back(elem1);

    if ((cnt2 > minCnt) && (elem2 != elem1))
        result.push_back(elem2);

    return result;
}