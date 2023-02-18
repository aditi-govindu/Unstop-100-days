/*
Description: Luke has a long bookshelf filled with n books numbered from 1 to n, 
and the ith book has the height ai. He recently bought a new shelf to keep some of 
his books since the first one was almost full. To add books to his new shelf, 
he walks across the first bookshelf from left to right, i.e., starting from book 1 towards 
book n. 

For each book in the shelf, he can do one of the following operations:
* Leave the book as it is and move on to the next one.
* Take the book out and place it on the new shelf at the leftmost available space.
* To make his new shelf look good, he wants the books in the new shelf to be in strictly 
increasing order of height from left to right. 

In other words, if the new shelf has m books numbered from 1 (leftmost) to m (rightmost), 
then for any i > 1, the height of the ith book should be strictly greater than the 
height of the  book. Help him find out the maximum number of books that he can 
place on his new shelf.
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
    int n;
    cin >> n;
    vector<int> books;
    vector<int> dp(n);
    
    // Accept input from user
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        books.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(books[j] >= books[i]) 
                continue;
	            // if element at index j is less than the
	            // element at our current index,
	            // we can add our current element on top of 
	            // LIS of element j, increasing its length by 1
	        dp[i] = max(dp[i], dp[j] + 1);
	    }
    }
    int result = 0;

    // Display results to user
    for(int i = 0; i < n; i++)
        result = max(result, dp[i]);
    cout << result << endl;
    return 0;
}