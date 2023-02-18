#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: There is a debate in the classroom for selecting one out of the 2 
syllabuses available. Syllabus 1 and syllabus 2 consist of an equal number of chapters. 
After a lot of debate and discussion, it was finally decided that the syllabus with more 
interest valuewould be selected for teaching.

The interest valueof a particular syllabus is the sum of the intent 
value of each chapter included in a particular syllabus. The intent value of a 
particular chapter is defined as the number of chapters in the other syllabus which 
have an intrinsic value lesser than or equal to the intrinsic value of the current 
chapter in the current syllabus.
*/

int intrinsicValues(vector<int> arr1, vector<int> arr2, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
      count += upper_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
    return count;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    vector<int> syllabus1(n);
    vector<int> syllabus2(n);

    for(int i = 0; i < n; i++)
        cin >> syllabus1[i];
    
    for(int i = 0; i < n; i++)
        cin >> syllabus2[i];
    
    sort(syllabus1.begin(), syllabus1.end());
    sort(syllabus2.begin(), syllabus2.end());


    int intrinsic1 = intrinsicValues(syllabus1, syllabus2, n);
    int intrinsic2 = intrinsicValues(syllabus2, syllabus1, n);

    int result = intrinsic1 > intrinsic2 ? intrinsic1 : intrinsic2;
    cout << result << endl;

    return 0;
}