#include <bits/stdc++.h>
using namespace std;

/*
Description: Ram has given a exactly one white rook ('R') and a certain number of white bishops ('B'), black pawns ('p'), and empty squares ('.') on an 8 x 8 chessboard.

When a rook moves, it chooses one of four cardinal directions (north, east, south, or west) and travels in that direction until it stops, reaches the board's edge, captures a black pawn, or is blocked by a white bishop. If a rook can take a pawn in the rook's turn, the rook is considered to be attacking the pawn. The number of pawns the white rook is attacking determines the number of available captures.

The number of captures available for the white rook should be returned, but ram is fool so help him out to find the answer.
*/

 int numRookCaptures(vector<vector<char>>& board) 
 {
        int count=0,x,y;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                // FInd location of rook
                if(board[i][j]=='R')
                {
                    x=i;y=j;
                }
            }
        }
        for(int i=y+1;i<8;i++)
        {
            // Check for pawn in all columns to right
            if(board[x][i]=='p')
            {
                count++;
                break;
            }
            // If bishop in column, exit
            else if(board[x][i]=='B')
                break;
        }
        for(int i=y-1;i>=0;i--)
        {
            // Check for pawn in all columns to left
            if(board[x][i]=='p')
            {
                count++;break;
            }
            // If bishop in column, break
            else if(board[x][i]=='B')
                break;
        }
        for(int i=x+1;i<8;i++)
        {
            // Check for pawn in rows below
            if(board[i][y]=='p')
            {
                count++;break;
            }
            else{
                if(board[i][y]=='B')
                    break;
            }
        }
        // Check for pawn in rows above
        for(int i=x-1;i>=0;i--){
            if(board[i][y]=='p'){
                count++;break;
            }
            else{
                if(board[i][y]=='B')
                    break;
            }
        }
        return count;
    }

int main() {
     // Chess board is 8*8
      vector<vector<char>> b(8,vector<char> (8));
      
      for(int i=0;i<8;i++)
      {
        for(int j=0;j<8;j++)
            cin>>b[i][j];
      }
      int ans=numRookCaptures(b);
      
      cout<<ans<<endl;
      return 0;
}