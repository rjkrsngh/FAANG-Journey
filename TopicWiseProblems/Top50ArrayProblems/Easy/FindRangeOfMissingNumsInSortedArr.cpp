
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper)
{
    // code here
    vector<vector<int>> result;
    if (arr[0] != lower)
    {
        result.push_back({lower, arr[0] - 1});
    }

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] - arr[i - 1] > 1)
        {
            result.push_back({arr[i - 1] + 1, arr[i] - 1});
        }
    }

    int n = arr.size() - 1;
    if (upper != arr[n])
    {
        result.push_back({arr[n] + 1, upper});
    }

    return result;
}