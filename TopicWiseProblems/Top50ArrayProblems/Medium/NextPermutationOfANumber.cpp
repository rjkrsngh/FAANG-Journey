/*
Next Permutation
Last Updated : 25 Jun, 2025

Given an array of integers arr[] representing a permutation (i.e., all elements are unique and arranged in some order), find the next lexicographically greater permutation by rearranging the elements of the array.
If such a permutation does not exist (i.e., the array is the last possible permutation), rearrange the elements to form the lowest possible order (i.e., sorted in ascending order).

Examples:

    Input: arr[] = [2, 4, 1, 7, 5, 0]
    Output: [2, 4, 5, 0, 1, 7]
    Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [2, 4, 5, 0, 1, 7].

    Input: arr[] = [3, 2, 1]
    Output: [1, 2, 3]
    Explanation: This is the last permutation, so we return the lowest possible permutation (ascending order).

    Input: arr[] = [1, 3, 5, 4, 2]
    Output: [1, 4, 2, 3, 5]
    Explanation: The next lexicographically greater arrangement of the elements in the array arr[] is [1, 4, 2, 3, 5].

    Problem link: https://www.geeksforgeeks.org/dsa/next-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &arr)
{
    // code here
    if (arr.size() <= 1)
        return;

    int n = arr.size();
    int ind = arr.size() - 2;
    for (ind; ind >= 0; --ind)
    {
        if (arr[ind] < arr[ind + 1])
        {
            break;
        }
    }

    if (ind < 0)
    {
        sort(arr.begin(), arr.end());
        return;
    }

    sort(arr.begin() + ind + 1, arr.end());
    for (int i = ind + 1; i < arr.size(); ++i)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[ind], arr[i]);
            break;
        }
    }
}