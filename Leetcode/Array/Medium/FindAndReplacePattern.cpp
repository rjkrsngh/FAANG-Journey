/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Problem link: https://leetcode.com/problems/find-and-replace-pattern/description/?envType=problem-list-v2&envId=array

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* My Solution
Approach:
    1. Check if the len of word and patter are same. If not, continue
    2. Check if word and patters are anagrams. If not, continue
    3. Iterate over word/patter and generate a map of word[i] to pat[i] and vice versa.
       At this step, if the word[i] or pat[i] have a different char mapped to it, break.
       If all mappings are unique, add it to list.
Complexities: Time: O(n*m), Space: O(n)

*/
vector<string> findAndReplacePattern(vector<string> &words, string pat)
{
    unordered_map<char, int> patMp;
    for (const auto chr : pat)
    {
        ++patMp[chr];
    }

    vector<string> res;
    for (const auto word : words)
    {
        if (word.size() != pat.size())
            continue;

        unordered_map<char, int> wordMp;
        for (const auto chr : word)
        {
            ++wordMp[chr];
        }

        if (patMp.size() != wordMp.size())
            continue;

        bool include{true};
        unordered_map<char, char> patToWordCharMp, wordToPatCharMp;
        for (int i = 0; i < word.size(); ++i)
        {
            if ((patToWordCharMp.find(pat[i]) != patToWordCharMp.end()) && (patToWordCharMp[pat[i]] != word[i]))
            {
                include = false;
                break;
            }
            else
            {
                patToWordCharMp[pat[i]] = word[i];
            }

            if ((wordToPatCharMp.find(word[i]) != wordToPatCharMp.end()) && (wordToPatCharMp[word[i]] != pat[i]))
            {
                include = false;
                break;
            }
            else
            {
                wordToPatCharMp[word[i]] = pat[i];
            }
        }

        if (include)
            res.push_back(word);
    }

    return res;
}

/*
Approach 2: Normalization

*/