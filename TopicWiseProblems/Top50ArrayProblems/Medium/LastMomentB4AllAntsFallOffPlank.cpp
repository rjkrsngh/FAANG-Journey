/*
Last Moment Before All Ants Fall Out of a Plank

Given a plank of length n with ants moving left and right at 1 unit per second. When ants collide, they reverse their directions and if an ant reaches either end of the plank, it falls off immediately.

Given two integer arrays, left[] and right[] denoting the positions of ants moving left and right respectively, find the time when the last ant falls off the plank.

Problem link: https://www.geeksforgeeks.org/dsa/last-moment-before-all-ants-fall-out-of-a-plank/

Input: n = 4, left[] = [2], right[] = [0, 1, 3]
Output: 4
*/

#include <iostream>
#include <vector>

using namespace std;

int getLastMoment(int n, vector<int> &left, vector<int> &right)
{
    int res{0};
    for (const auto elem : left)
    {
        res = max(res, elem);
    }

    for (const auto elem : right)
    {
        res = max(res, n - elem);
    }

    return res;
}