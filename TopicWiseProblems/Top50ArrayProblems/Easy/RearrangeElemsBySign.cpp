/*
Rearrange Array Elements by Sign
Last Updated : 23 Jul, 2025

Given an array arr[] of size n, the task is to rearrange it in alternate positive and negative manner without changing the relative order of positive and negative numbers. In case of extra positive/negative numbers, they appear at the end of the array.

Note: The rearranged array should start with a positive number and 0 (zero) should be considered as a positive number.

Examples:

    Input:  arr[] = [1, 2, 3, -4, -1, 4]
    Output: arr[] = [1, -4, 2, -1, 3, 4]

    Input:  arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
    Output: arr[] = [5, -5, 2, -2, 4, -8, 7, 1, 8, 0]
*/

#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int> &arr)
{
    vector<int> positive, negative;
    for (const auto elem : arr)
    {
        if (elem >= 0)
        {
            positive.push_back(elem);
        }
        else
        {
            negative.push_back(elem);
        }
    }

    int posInd{0}, negInd{0}, resInd{0};
    bool posTurn{true};
    while ((posInd < positive.size()) && (negInd < negative.size()))
    {
        if (posTurn)
        {
            arr[resInd++] = positive[posInd++];
        }
        else
        {
            arr[resInd++] = negative[negInd++];
        }

        posTurn = !posTurn;
    }

    if (posInd >= positive.size())
    {
        while (negInd < negative.size())
        {
            arr[resInd++] = negative[negInd++];
        }
    }

    if (negInd >= negative.size())
    {
        while (posInd < positive.size())
        {
            arr[resInd++] = positive[posInd++];
        }
    }
}