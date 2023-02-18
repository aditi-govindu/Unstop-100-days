/*
Description: Steve is doing some competitive coding, but at any second ‘t’ when he made any submission, the previous submission, which was done 5000 seconds ago, will remove itself from the submission queue. He wants to calculate the maximum queue size he will get at any time ‘t’ after total 'n' submissions.

Help Steve to find the maximum size of queue.

Note: It is guaranteed that every submission uses a strictly larger value of ‘t’ than the previous submission.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int n ; 
      cin >> n ; 
     vector < int > v(n); // initialize the array
     for(int i = 0; i<n ; i++){ 
         cin >> v[i]; // input the element of an array
     }
    
     queue < int > q; 
    int mx = 0; 
         for(int i = 0; i<n; i++){ // run a for loop 
          
           while(!q.empty() && v[i] - q.front() >= 5000){ 
             q.pop(); 
           }
           q.push(v[i]); 
           int cnt = q.size(); 
           mx = max( mx , cnt); 
         }
         cout << mx ;// print the maxmimum size
    
    return 0; 
}