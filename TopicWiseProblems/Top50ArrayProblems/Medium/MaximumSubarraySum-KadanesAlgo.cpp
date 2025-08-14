/*
Maximum Subarray Sum - Kadane's Algorithm
Last Updated : 22 Jul, 2025

Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, and return that sum.
Note: A subarray is a continuous part of an array.

Examples:

    Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
    Output: 11
    Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

    Input: arr[] = [-2, -4]
    Output: -2
    Explanation: The subarray [-2] has the largest sum -2.

    Input: arr[] = [5, 4, 1, 7, 8]
    Output: 25
    Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

    Problem link: https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/
*/

#include <iostream>
#include <vector>

using namespace std;
int maxSubarraySum(vector<int> &arr)
{
    int currSm{arr[0]}, maxSm{arr[0]};
    for (int i = 1; i < arr.size(); ++i)
    {
        currSm = max(arr[i], arr[i] + currSm);
        maxSm = max(maxSm, currSm);

        if (currSm < 0)
            currSm = 0;
    }

    return maxSm;
}