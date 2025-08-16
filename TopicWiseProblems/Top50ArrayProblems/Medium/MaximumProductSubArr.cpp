/*
Maximum Product Subarray
Last Updated : 22 Jul, 2025

Given an array arr[] consisting of positive, negative, and zero values, find the maximum product that can be obtained from any contiguous subarray of arr[].

Examples:

    Input: arr[] = [-2, 6, -3, -10, 0, 2]
    Output: 180
    Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

    Input: arr[] = [-1, -3, -10, 0, 6]
    Output: 30
    Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

    Input: arr[] = [2, 3, 4]
    Output: 24
    Explanation: For an array with all positive elements, the result is product of all elements.
*/

#include <iostream>
#include <vector>

using namespace std;

/*Solution 1: Time Complexity: O(n^2), Space Complexity: O(1)*/
int maxProduct(vector<int> &arr)
{
    int n = arr.size();

    int maxProd = arr[0];

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

/*Solution 2: Time Complexity: O(n^2), Space Complexity: O(1)
  Approach: When a negative number is encountered, it has the potential to convert the currMax to currMin and vice versa.
  So swap the variables the then compute the currMax and currMin at each step.
*/
int maxProduct(vector<int> &arr)
{
    // code here
    int maxSoFar{arr[0]}, maxEndingHere{arr[0]}, minEndingHere{arr[0]};
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < 0)
        {
            int temp = maxEndingHere;
            maxEndingHere = minEndingHere;
            minEndingHere = temp;
        }

        maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
        minEndingHere = min(arr[i], minEndingHere * arr[i]);

        maxSoFar = max(maxEndingHere, maxSoFar);
    }

    return maxSoFar;
}

/*Approach 3: Traverse the array in both direction and find the current max at each step.*/
int maxProduct(vector<int> &arr)
{
    // Your Code Here
    int max_prod{arr[0]}, curr_prod{arr[0]};
    for (int i = 1; i < arr.size(); ++i)
    {
        (curr_prod == 0) ? curr_prod = arr[i] : curr_prod *= arr[i];
        max_prod = max(max_prod, curr_prod);
    }

    int len = arr.size();
    curr_prod = arr[len - 1];
    for (int ind = len - 2; ind >= 0; --ind)
    {
        (curr_prod == 0) ? curr_prod = arr[ind] : curr_prod *= arr[ind];
        max_prod = max(max_prod, curr_prod);
    }

    return max_prod;
}