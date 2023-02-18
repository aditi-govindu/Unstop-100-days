/*
Description: Students of St. Mary school stands in an Assembly Line. 
All the students of the school are of different heights. 
The school has N students. 
In the assembly the students stand in line in such a way that ∀ (i,j ) ,
hi<hj where i<j where hi denotes the height of ith student (indexing starts from 0) and 
i,j ∈[0,N-1]. Nidhi Sharma, a teacher of that school wants to make k queries 
so that for each query she will enquire about the height H of a student. 
Your task is to tell the position of that student if present and if absent what 
will be the proper position to place the student.
*/

#include <bits/stdc++.h>
#define MOD (int)1e9 + 7
#define int long long


using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;
    cin >> k;

    while(k--)
    {
        int target;
        cin >> target;
        int flag=0;
        int hi=n-1;
        int lo=0;
        int ans=0;

        // Binary search to insert element
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==target){
                flag=1;
                ans=mid;
                break;
            }
            if(arr[mid]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(flag==1)cout<<ans<<endl;
        else cout<<lo<<endl;
    }
    return 0;
}