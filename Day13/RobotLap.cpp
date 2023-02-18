#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: On a 2D plane, Raju that starts at (0, 0), the origin. Determine whether this robot ends up at (0, 0) after completing its moves given a sequence of its manoeuvres.

You are provided a string moves that represents the raju's move sequence, where moves[i] indicates the robot's ith move. 'R' (right), 'L' (left), 'U' (up), and 'D' (down) are all valid motions (down).

Return true if Raju returns to the origin after completing all of its moves, else false.

It is important to note that the Raju is "facing" is unimportant. 'R' causes the raju  to move to the right once, 'L' causes it to move to the left once, and so on. Assume that the amount of the raju's movement is constant for all moves.

Ravi is busy with his Birthday Party, so he told you to help Raju out.
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int row = 0;
    int col = 0;
    string operations;
    int n;
    
    cin >> n;
    cin >> operations;
    // Iterate over letters to find operation performed

    for(auto &letter: operations)
    {
        // Move up
        if(letter == 'U')
            ++col;
        // Move down
        else if(letter == 'D')
            --col;
        // Move left
        else if(letter == 'L')
            --row;
        // Move right
        else if(letter == 'R')
            ++row;
    } 
    // If original place reached, print YES cycle completed
    if(row == 0 && col == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}