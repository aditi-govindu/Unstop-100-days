/*
Description: There is an n x n grid, with a Robot named Dare, whose start and the 
end position is given as an integer array Pos where Pos = [Posrow, Poscol].

You are also given string Instructions of length m where s[i] is the ith 
instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 
'D' (move down). The robot can begin executing from any ith instruction in s. 
It executes the instructions one by one towards the end of s 
but it stops if either of these conditions is met:

The next instruction will move the robot off the grid.
There are no more instructions left to execute.

Print an array answer of length m where answer[i] is the number of instructions 
the robot can execute if the robot begins executing from the ith instruction in s.
*/

#include <bits/stdc++.h>
using namespace std;

// check how many steps you can go
int findSteps(int &n,string &s,int row,int col,int pos){
   int ans=0;
    for(int i=pos;i<s.size();i++){
        if(s[i]=='L')
            col--;
        else if(s[i]=='R')
            col++;
        else if(s[i]=='U')
            row--;
        else
            row++;
            // if it is true then this move is invalid,return ans
        if(row<0 || col<0 || row>=n || col>=n)
            return ans;
            // else go to next move.
        ans++;
    }
    return ans;
}

vector<int> executeInstructions(int n, vector<int>& pos, string s) {
    int size=s.size();
    vector<int>ans(size,0);
    // for finding answer iterate over all points one by one
    for(int i=0;i<size;i++)
       ans[i]= findSteps(n,s,pos[0],pos[1],i);
    return ans; 
}

signed main() {
    int n;//size of the grid(n*n)
    cin>>n;
    
    vector<int> pos(2);
    cin>>pos[0]>>pos[1];

    int m;
    cin>>m;
    string instruction;
    cin>>instruction;

    vector<int> ans = executeInstructions(n, pos,instruction);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}