/*
Find 0 with Farthest 1s in a Binary Array
Last Updated : 22 Mar, 2025

Given a string (seats) of 1s and 0s, where 1 represents a filled seat and 0 represents an empty seat in a row. Find an empty seat with maximum distance from an occupied seat. Return the maximum distance.

Problem link: https://www.geeksforgeeks.org/dsa/find-a-seat-with-distance-between-nearest-occupied-seats-maximised/

Examples:

    Input: Seats = "1000101"
    Output: 2
    Explanation: Geek can take 3rd place and have a distance of 2 in left and 2 in right.

    Input: Seats = "1000"
    Output: 3
    Explanation: Geek can take the rightmost seat to have a distance of 3.
*/

#include <iostream>
#include <vector>

using namespace std;