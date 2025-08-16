/*
Maximum Consecutive Ones After Flipping Zeroes
Last Updated : 05 Aug, 2025

Given a binary array arr[] and an integer k, find the maximum length of a subarray containing all ones after flipping at most k zeroes to 1's.

Problem link: https://www.geeksforgeeks.org/dsa/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/

Examples:

    Input: arr[] = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1], k = 2
    Output: 8
    Explanation: By flipping the zero at index 1, all the array elements become one.

    Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
    Output: 5
    Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1's.
*/

#include <iostream>
#include <vector>

using namespace std;

/*Approach: 2 Pointers + variable size sliding window
  Time Complexity: O(n), Space Complexity: O(1)
*/
int maxOnes(vector<int> &arr, int k)
{
    int start{0}, end{0}, zeroCnt{0}, maxlen{0};
    while (end < arr.size())
    {
        if (arr[end] == 0)
            ++zeroCnt;

        if (zeroCnt > k)
        {
            maxlen = max(maxlen, end - start);
            while ((start <= end) && (zeroCnt > k))
            {
                if (arr[start] == 0)
                {
                    --zeroCnt;
                }

                ++start;
            }
        }

        ++end;
    }

    maxlen = max(maxlen, end - start);

    return maxlen;
}