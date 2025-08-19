/*
3175. Find The First Player to win K Games in a Row
A competition consists of n players numbered from 0 to n - 1.

You are given an integer array skills of size n and a positive integer k, where skills[i] is the skill level of player i. All integers in skills are unique.

All players are standing in a queue in order from player 0 to player n - 1.

The competition process is as follows:

    The first two players in the queue play a game, and the player with the higher skill level wins.
    After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.

The winner of the competition is the first player who wins k games in a row.

Return the initial index of the winning player.

Problem link: https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row/description/?envType=problem-list-v2&envId=array

Example 1:

Input: skills = [4,2,6,3,9], k = 2

Output: 2

Explanation:

Initially, the queue of players is [0,1,2,3,4]. The following process happens:

    Players 0 and 1 play a game, since the skill of player 0 is higher than that of player 1, player 0 wins. The resulting queue is [0,2,3,4,1].
    Players 0 and 2 play a game, since the skill of player 2 is higher than that of player 0, player 2 wins. The resulting queue is [2,3,4,1,0].
    Players 2 and 3 play a game, since the skill of player 2 is higher than that of player 3, player 2 wins. The resulting queue is [2,4,1,0,3].

Player 2 won k = 2 games in a row, so the winner is player 2.

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*Approach: If k>=skills.size(), then return the index of candidate with highest skill.
            Else, keep comparing candidates. Push the loser to the end of the q and keep the
            winner at the front incresing its win streak.

Complexities: Time: O(n), Space: O(n) */
int findWinningPlayer(vector<int> &skills, int k)
{
    deque<pair<int, pair<int, int>>> q;
    for (int i = 0; i < skills.size(); ++i)
    {
        q.push_back({skills[i], {i, 0}});
    }

    while (true)
    {
        auto item1 = q.front();
        q.pop_front();

        auto item2 = q.front();
        q.pop_front();

        auto winner = item1.first > item2.first ? item1 : item2;
        auto loser = item1.first < item2.first ? item1 : item2;

        loser.second.second = 0;
        q.push_back(loser);

        ++winner.second.second;
        if ((winner.second.second > skills.size()) || (winner.second.second == k))
        {
            return winner.second.first;
        }
        else
        {
            q.push_front(winner);
        }
    }

    return -1;
}

/*Approach 2: Same idea, cleaner implementation */
int findWinningPlayer(vector<int> &skills, int k)
{
    const int n = skills.size();
    if (k >= n)
        return max_element(skills.begin(), skills.end()) - skills.begin();

    int winner{0}, streak{0};
    for (int player = 1; player < n; ++player)
    {
        if (skills[winner] > skills[player])
        {
            ++streak;
        }
        else
        {
            winner = player;
            streak = 1;
        }
    }

    return winner;
}