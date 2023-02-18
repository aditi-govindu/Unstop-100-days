#include <bits/stdc++.h>
using namespace std;

/*
Description: Once upon a time, in the game of chess. There was an interesting situation. The king was the only piece alive and surrounded by the enemy queens. This game was being played between saurav and vikas. And saurav wanted to attack vikas's kings with as many queens as possible. But he is busy moving pawns and upgrading them to queens, so he wants your help in counting how many queens are currently attacking vikas's king.

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represent the positions of the Black Queens, and a pair of coordinates king that represent the position of the White King, return the coordinates of all the queens that can attack the King.
*/
  
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) 
{
    bool b[8][8] = {};
    for (auto& q : queens) b[q[0]][q[1]] = true;
    vector<vector<int>> res;
    for (auto i = -1; i <= 1; ++i)
        for (auto j = -1; j <= 1; ++j) 
        {
            if (i == 0 && j == 0) 
                continue;
            auto x = k[0] + i, y = k[1] + j;
            while (min(x, y) >= 0 && max(x, y) < 8) 
            {
                if (b[x][y]) 
                {
                    res.push_back({ x, y });
                    break;
                }
                x += i, y += j;
            }
        }
    return res;
}

int main() 
{ 
    int n;
    cin>>n;
    vector<vector<int>> queen;

    for(int i=0; i<n; i++)
    {
        vector<int> temp(2);
        for(int j=0; j<2; j++)
            cin>>temp[j];
        queen.push_back(temp);
    }
    vector<int> king(2);
    cin>>king[0]>>king[1];
    vector<vector<int>> result;
    result =  queensAttacktheKing(queen, king);
    for(int i=0; i< result.size(); i++)
    {
        for(int j=0; j<2; j++)
            cout<<result[i][j]<<" ";
    }
    return 0; 
}