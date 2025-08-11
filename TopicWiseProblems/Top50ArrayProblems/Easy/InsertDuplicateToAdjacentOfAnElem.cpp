/*
    Given an array arr[] of size n and an integer k, the task is to insert a duplicate of k adjacent to its every occurrence. Keep array's original length same by removing the elements from the back.

    Examples:

        Input: arr[] = [1, 0, 2, 3, 0, 4, 5, 0], K = 0
        Output: [1, 0, 0, 2, 3, 0, 0, 4]
        Explanation: The given array [1, 0, 2, 3, 0, 4, 5, 0] is modified to [1, 0, 0, 2, 3, 0, 0, 4] after insertion of two 0's and truncation of two extra elements.

        Input: arr[] = [7, 5, 8], K = 8
        Output: [7, 5, 8]
        Explanation: After inserting an adjacent 8 into the array, it got truncated to restore the original size of the array.
*/

#include <iostream>
#include <vector>

using namespace std;

/*Time Complexity: O(n^2), Space Complexity: O(1)*/
vector<int> duplicateK(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == k)
        {
            if (i + 1 < arr.size())
            {
                for (int j = arr.size() - 1; j > i; --j)
                {
                    arr[j] = arr[j - 1];
                }

                arr[i + 1] = k;
            }
        }
    }
}

/*Time Complexity: O(n), Space Complexity: O(1)*/
vector<int> duplicateK(vector<int> &arr, int k)
{
    const int n = arr.size();

    int cnt = count(arr.begin(), arr.end(), k);

    int write_idx = n + cnt - 1;

    int curr = n - 1;

    while (curr >= 0 && write_idx >= 0)
    {
        if (write_idx < n)
            arr[write_idx] = arr[curr];

        write_idx -= 1;

        if (arr[curr] == k)
        {
            if (write_idx < n)
                arr[write_idx] = k;

            write_idx -= 1;
        }

        --curr;
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    int k = 0;
    vector<int> ans = duplicateK(arr, k);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
