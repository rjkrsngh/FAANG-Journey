/*
Product of Array Except Self
Last Updated : 23 Jul, 2025

Given an array arr[] of n integers, construct a product array res[] (of the same size) such that res[i] is equal to the product of all the elements of arr[] except arr[i].

Problem link: https://www.geeksforgeeks.org/dsa/a-product-array-puzzle/

Example:

    Input: arr[] = [10, 3, 5, 6, 2]
    Output: [180, 600, 360, 300, 900]
    Explanation:

        For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
        For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
        For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
        For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
        For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

    Input: arr[] = [12, 0]
    Output: [0, 12]
    Explanation:

        For i = 0, res[i] = 0.
        For i = 1, res[i] = 12.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &arr)
{
    int numOfZeros{0}, totalProd{1}, zeroInd{-1};
    vector<int> result(arr.size(), 0);

    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 0)
        {
            zeroInd = i;
            ++numOfZeros;
        }
        else
        {
            totalProd *= arr[i];
        }
    }

    if (numOfZeros == 0)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            result[i] = totalProd / arr[i];
        }
    }
    else if (numOfZeros == 1)
    {
        result[zeroInd] = totalProd;
    }

    return result;
}