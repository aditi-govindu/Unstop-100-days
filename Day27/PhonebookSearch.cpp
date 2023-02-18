/*
Description: Henry is searching for his friend's name in his phone book to contact him, but it is very difficult for him to search in his phonebook because there are too many names in his phonebook, and he is fed up by searching in it. Now he wants to make a searching system to search any name in his phone book easily in less time. But he is busy making his cupcakes, so he needs your help to build a searching system.

Your task is to design a system that suggests at most three names from the phone book after each character of the search name is typed. Suggested names should have a common prefix with search name. If more than three names have a common prefix, return the three lexicographically minimum names.

If there are no matched names finds for a given prefix of search name, then simply print -1.

*/

#include<bits/stdc++.h>
using namespace std;
 vector<vector<string>> suggestedProducts(vector<string>& P, string S) 
 {
        sort(P.begin(), P.end()); // sort the phone book
        vector<vector<string>> ans; // declare the answer array
        int left = 0, right = P.size() - 1;
        for (int i = 0; i < S.length(); i++) {
            vector<string> res; // result array
            char c = S[i];
           // we'll iterate through the characters (c) of S.
           // At each iteration, we'll first want to move left forward and 
           //right back to narrow the range of matches based on the new value of c.
            while (left <= right && (P[left].length() == i || P[left][i] < c)) left++; 
            while (left <= right && (P[right].length() == i || P[right][i] > c)) right--;
            for (int j = 0; j < 3 && left + j <= right; j++)
                res.push_back(P[left+j]);
                if(res.size() == 0){ 
                ans.push_back({"-1"}); 
                }
          else  ans.push_back(res);
        }
        return ans;
    }
int main(){ 
         
         string s; 
           cin >> s; 
             int n ; 
             cin >> n; 
        vector < string > str(n); 
          for(int i = 0 ; i<n  ; i++){  string t; cin >>t; str.push_back(t); }
          
          vector < vector < string > > ans = suggestedProducts(str, s); 
          
       for(auto a : ans){ 
        for(auto b : a){ 
          cout << b << " "; 
        }  cout << endl; 
       }
         
return 0; 
}