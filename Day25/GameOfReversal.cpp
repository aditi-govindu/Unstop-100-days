#include <bits/stdc++.h>
using namespace std;

/*
Description: Alice loves to play games with strings so one day she took a string and started playing Game of Reversal with it. In the game she reverses the order of character of every single word in the sentence but maintains the initial word order. She wins the game if she reverses the string in the correct order. Your task is to help Alice in winning the game.
*/

string reverseWords(string s) 
{
    istringstream ss(s);
    
    vector<string>vstr;
    
    string word;
    while(ss>>word)
        vstr.push_back(word);
    
    string ans="";
    
    for(auto word:vstr)
    {
        reverse(begin(word),end(word));
        ans+=word;
        ans+=" ";
    }
    ans.pop_back();
    
    return ans;
    }

int main() 
{
  string s;
  getline(cin,s);

  string ans=reverseWords(s);
  cout<<ans<<endl;
	
   return 0;
}