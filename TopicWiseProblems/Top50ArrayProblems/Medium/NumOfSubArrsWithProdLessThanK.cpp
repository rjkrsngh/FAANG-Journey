/*
Given an array of positive numbers, calculate the number of possible contiguous subarrays having product lesser than a given number K.

Problem link: https://www.geeksforgeeks.org/dsa/number-subarrays-product-less-k/

Examples :

    Input : arr[] = [1, 2, 3, 4]
                K = 10
    Output : 7
    The subarrays are {1}, {2}, {3}, {4}, {1, 2}, {1, 2, 3} and {2, 3}


    Input  : arr[] = [1, 9, 2, 8, 6, 4, 3]
                 K = 100
    Output : 16


    Input  : arr[] = [10, 5, 2, 6]
                 K = 100
    Output : 8
*/

#include <iostream>
#include <vector>

using namespace std;

/*Approach 1: Brite Force - Time Complexity: O(n^2), Space Complexity: O(1)*/
long long countSubArrayProductLessThanK(const vector<int> &arr, int n, long long k)
{
    long long count{0};
    for (int i = 0; i < n; ++i)
    {
        long long prod{1};
        for (int j = i; j < n; ++j)
        {
            if (prod * arr[j] < k)
            {
                prod *= arr[j];
                ++count;
            }
            else
            {
                break;
            }
        }
    }

    return count;
}

/*Approach 2: variable size sliding window + 2 Pointers
  Core logic: For each possible ending point of a subarray, we slide the starting point forward until the product is valid.
              The number of subarrays ending there is just the size of that valid window. Add them up to get the total.

  Time Complexity: O(n), Space Complexity: O(1)
*/
long long countSubArrayProductLessThanK(const vector<int> &arr, int n, long long k)
{
    long long res{0}, chunks{0}, prod{1}, start{0};
    for (int i = 0; i < n; ++i)
    {
        prod *= arr[i];

        while ((start <= i) && (prod >= k))
        {
            prod /= arr[start++];
        }

        res += i - start + 1;
    }

    return res;
}