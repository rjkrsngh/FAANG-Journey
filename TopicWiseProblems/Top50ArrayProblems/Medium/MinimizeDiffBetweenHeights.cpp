/*
Minimize the maximum difference between the heights
Last Updated : 23 Jul, 2025

Given the heights of n towers and a positive integer k, increase or decrease the height of all towers by k (only once). After modifications, the task is to find the minimum difference between the heights of the tallest and the shortest tower.

Examples:

    Input: arr[] = [12, 6, 4, 15, 17, 10], k = 6
    Output: 8
    Explanation: Update arr[] as [12 - 6, 6 + 6, 4 + 6, 15 - 6, 17 - 6, 10 - 6] = [6, 12, 10, 9, 11, 4]. Now, the minimum difference is 12 - 4 = 8.

    Input: arr[] = [1, 5, 10, 15], k = 3
    Output: 8
    Explanation: Update arr[] as [1 + 3, 5 + 3, 10 - 3, 15 - 3] = [4, 8, 7, 12]. Now, the minimum difference is 8.

    Problem link: https://www.geeksforgeeks.org/dsa/minimize-the-maximum-difference-between-the-heights/
*/