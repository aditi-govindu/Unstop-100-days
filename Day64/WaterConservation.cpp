#include <iostream>
using namespace std;

/*
Description: A lot of people in India hate rain, but you do not. Rain pacifies puts your thoughts in order. By these years, you have developed a good tradition — when it rains, you go on the street and stay silent for a moment, contemplate all around you, enjoy the freshness, think about big deeds you have to do. Today everything has changed quietly. You are a programmer such that whatever you find interesting, you would immediately convert it into a problem and try to get an algorithm for it. You saw water stagnation in front of your house after heavy rain. So, you got an idea to write a program to find the amount of water that stagnated.

You are given an iron bar which is of dimension 1 unit. Iron bars are placed in a particular format for each test case. You must display the maximum units of accumulation of water between the iron bars if rainfall has occurred in that building.
*/

int maxWater(int arr[], int n)
{
    //indices to traverse the array
	int left = 0;
	int right = n-1;

    // To store Left max and right max  two pointers left and right
	int l_max = 0;
	int r_max = 0;

    // To store the total amount  of rain water trapped
	int result = 0;
	while (left <= right)
	{
        // We need check for minimum of left and right max for each element
        if(r_max <= l_max)
        {
            // Add the difference between current value and right max at index r
            result += max(0, r_max-arr[right]);
            // Update right max
            r_max = max(r_max, arr[right]);
            // Update right pointer
            right -= 1;
        }
        else
        {
            // Add the difference between current value and left max at index l
            result += max(0, l_max-arr[left]);
            // Update left max
            l_max = max(l_max, arr[left]);
            // Update left pointer
            left += 1;
        }
	}
	return result;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    cout << maxWater(arr, n);
    return 0;
}