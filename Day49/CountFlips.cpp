#include <bits/stdc++.h>
using namespace std;
/*
Description: Saurav and Vikas are learning about the sorting algorithms, they are very intrigued by the classical sorting algorithms. Vikas wants to come up with his own sorting algorithm, so he has implemented the following concept and wants to know how many frlips will be needed to sort the given set of integers using this method. Help him find out the answer by writing a code that can give the minimum number of reversals that will be needed.

Given an array of integers arr, sort the array by performing a series of flips.

In one flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the flip at k = 3.

Return an array of the k-values corresponding to a sequence of flips that sort arr.
*/

int getPos(vector<int>& arr, int k)
{
    // Return location of element equal to k
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==k)
            return i;
    }
    return -1;
}

void reverseArr(vector<int>& arr, int k)
{
    // Reverse the array
    int i=0,j=k;
    while(i<j)
    {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
vector<int> pancakeSort(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> res;

    for(int i=n;i>0;i--)
    {
        int pos = getPos(arr,i);
        if(pos==i-1)
            continue;
        else if(pos!=0)
        {
            // Reverse array before and after element at index k
            res.push_back(pos+1);
            reverseArr(arr,pos);
        }
        res.push_back(i);
        reverseArr(arr,i-1);
    }
    return res;
}

int main() 
{ 
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> result;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    result = pancakeSort(arr);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0; 
}