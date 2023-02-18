/*
Description: You are given two integers memory1 and memory2 representing the available 
memory in bits on two memory sticks. There is currently a faulty program running that 
consumes an increasing amount of memory every second.

At the ith second (starting from 1), i bits of memory are allocated to the stick 
with more available memory (or from the first memory stick if both have the same 
available memory). If neither stick has at least i bits of available memory, the 
program crashes.

Print an array containing [crashTime, memory1crash, memory2crash], where 
crashTime is the time (in seconds) when the program crashed and memory1crash and 
memory2crash are the available bits of memory in the first and second sticks respectively. 
Also create and display a prefix sum array for the created array containing 
[crashTime, memory1crash, memory2crash]
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int stick1, stick2;
    cin >> stick1 >> stick2;

    int seconds = 1;

    // If stick memory is greater than allocated time, decrement memory
    while(stick1 >= seconds || stick2 >= seconds)
    {
        if(stick1 >= stick2)
            stick1 -= seconds;
        else
            stick2 -= seconds;
        ++seconds;
    }
    // Display results to user
    cout << seconds << " " << stick1 << " " << stick2 << endl;
    cout << seconds << " " << (seconds + stick1) << " " << (seconds + stick1 + stick2) << "\n";
    cout << endl;
    return 0;
}