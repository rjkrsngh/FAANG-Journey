// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(std::string str, int start, int end, std::vector<std::vector<int>> &table)
{
    int ind1 = start, ind2 = end;
    if (table[start][end] == -1)
    {
        while ((end != std::string::npos) && (start < end))
        {
            if (str[start] != str[end])
            {
                table[ind1][ind2] = 0;
            }

            ++start;
            --end;
        }

        table[ind1][ind2] = 1;
    }
    else
    {
        std::cout << "already computed for indices: " << ind1 << ", " << ind2 << ", result: " << table[ind1][ind2] << std::endl;
    }

    return table[ind1][ind2] == 1;
}

void countMinSteps(std::string str, int start, int end, int steps, int &count, std::vector<std::vector<int>> &table)
{
    std::cout << str << ", start: " << start << ", end: " << end << std::endl;
    if (start == end)
    {
        count = std::min(count, steps);
        std::cout << "start==end. New count: " << count << ", steps: " << steps << std::endl;
        return;
    }

    if (str.empty())
    {
        std::cout << "string is empty!" << ", count: " << count << ", steps: " << steps << std::endl;
        count = std::min(count, steps);
        return;
    }

    // if (str.size() == 1)
    // {
    //     count = std::min(steps + 1, count);
    //     return;
    // }

    // if (str.size() == 2)
    // {
    //     if (str[0] == str[1])
    //     {
    //         count = std::min(steps + 1, count);
    //     }
    //     else
    //     {
    //         count = std::min(steps + 2, count);
    //     }

    //     return;
    // }

    bool found{false};
    for (int i = start; i < end; ++i)
    {
        for (int j = i + 1; j < end; ++j)
        {
            if (isPalindrome(str, i, j, table))
            {
                found = true;
                std::string s = str.substr(start, i - start) + str.substr(j + 1);
                std::cout << "new string: " << s << ", i: " << i << ", j: " << j << std::endl;
                countMinSteps(s, 0, s.size(), steps + 1, count, table);
            }
        }
    }

    if (!found)
    {
        std::string s = str.substr(start + 1);
        countMinSteps(s, 0, s.size(), steps + 1, count, table);
    }
}

int minStepToDeleteString(std::string s)
{
    // Your code goes here
    std::cout << "Entered minStepToDeleteString\n";
    int count{INT_MAX};
    std::vector<std::vector<int>> table(s.size(), std::vector<int>(s.size(), -1));
    countMinSteps(s, 0, s.size(), 0, count, table);

    return count;
}

int main()
{
    // Write C++ code here
    // int count = minStepToDeleteString("455336653");
    int count = minStepToDeleteString("2553432");
    // int count = minStepToDeleteString("1234");
    std::cout << "count: " << count << std::endl;

    return 0;
}