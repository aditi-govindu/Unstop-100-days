#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstdlib>
using namespace std;

/*
Description: In a room, there are n seats and n students. You are provided an array seats of length n, with seats[i] representing the position of the ith seat. You are also provided the n-dimensional array students, where students[j] represents the jth student's position.

You may repeat the following move as many times as you like:

Increase or reduce the ith student's position by one (i.e., move the ith student from position x to x + 1 or x - 1).
Return the smallest number of moves required to shift each student to a seat where no two students are seated together.

It should be noted that there may be many seats or students in the same place at the start.
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int>positions;
    vector<int>students;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        positions.push_back(temp);
    }    

    for(int i = 0; i < n; i++)
    {   
        int temp;
        cin >> temp;
        students.push_back(temp);
    }
    
    int moves = 0;
    for(int i = 0; i < n; i++)
    {
        // Minimum moves of student are absolute difference of current - next
        moves += abs(students[i] - positions[i]);
    }
    cout << moves << endl;
    return 0;
}