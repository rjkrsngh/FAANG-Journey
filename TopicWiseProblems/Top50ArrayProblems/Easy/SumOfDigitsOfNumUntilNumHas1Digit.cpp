/*
Given an integer n, we need to repeatedly find the sum of its digits until the result becomes a single-digit number.
Examples:

    Input: n = 1234
    Output: 1
    Explanation:
    Step 1: 1 + 2 + 3 + 4 = 10
    Step 2: 1 + 0 = 1

    Input: n = 5674
    Output: 4
    Explanation:
    Step 1: 5 + 6 + 7 + 4 = 22
    Step 2: 2 + 2 = 4
*/

#include <iostream>

// Iterative approach
int findNum(int n)
{
    while (n > 9)
    {
        int num{0};
        while (n > 0)
        {
            num += n % 10;
            n /= 10;
        }

        n = num;
    }

    return n;
}

int repeatedSumOfDigits(int N)
{
    // code here
    if (N <= 9)
        return N;

    return findNum(N);
}