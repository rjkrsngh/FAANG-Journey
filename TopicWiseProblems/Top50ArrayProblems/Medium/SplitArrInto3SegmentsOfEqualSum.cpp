/*
Split array into three equal sum segments
Last Updated : 29 Oct, 2024

Given an integer array arr[], the task is to divide the array into three non-empty contiguous segments with equal sum. In other words, we need to return an index pair [i, j], such that sum(arr[0...i]) = sum(arr[i+1...j]) = sum(arr[j+1...n-1]).

Note: If it is impossible to divide the array into three non-empty contiguous segments, return [-1, -1].

Examples:

    Input: arr[] = [1, 3, 4, 0, 4]
    Output: [1, 2]
    Explanation: 3 equal sum segments are: arr[0...1], arr[2...2] and arr[3...4] each having sum = 4.

    Input: arr[] = [2, 3, 4]
    Output: [-1, -1]
    Explanation: No three segments exist which has equal sum.

    Input: arr[] = [1, -1, 1, -1, 1, -1, 1, -1]
    Output: [1, 3]
    Explanation: 3 equal sum segments are: arr[0...1], arr[2...3] and arr[4...7] each having sum = 0.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/* Simple 2 pointer approach. Time Complexity: O(n), Space Complexity: O(1) */
vector<int> findSplit(vector<int> &arr)
{
    // code here
    int sum1{0}, sum2{0};
    int sum3 = accumulate(arr.begin(), arr.end(), 0);

    vector<int> res(2, -1);
    if (sum3 % 3 != 0)
    {
        return res;
    }

    int n = arr.size();
    int ind1{0}, ind2{n - 1};
    while (ind1 < ind2)
    {
        if (sum1 < sum2)
        {
            sum1 += arr[ind1];
            sum3 -= arr[ind1++];
        }
        else if (sum1 > sum2)
        {
            sum2 += arr[ind2];
            sum3 -= arr[ind2--];
        }
        else
        {
            sum1 += arr[ind1];
            sum3 -= arr[ind1++];
        }

        if ((sum1 == sum3) && (sum2 == sum3))
        {
            res[0] = ind1 - 1;
            res[1] = ind2;
            break;
        }
    }

    return res;
}