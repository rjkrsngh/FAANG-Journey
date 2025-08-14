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