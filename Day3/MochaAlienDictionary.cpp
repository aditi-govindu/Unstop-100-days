/*
Description: John and Mocha are two friends. Mocha made his dictionary of strings of length n and called it Alien dictionary. John tries to test Mocha's Alien dictionary by giving one string s to Mocha. Help Mocha check if John's string can be segmented into a sequence of one or more words from Mocha's Alien dictionary.

Note: The words in the dictionary contain unique words of lowercase English letters and can be found multiple times in the segmentation.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool wordbreak(string s, vector<string>& worddict)
{
    if(worddict.size()==0) return false;// if the size of the dictionary is 0, return false
    set <string> dict;
    for(int i=0;i<worddict.size();i++)
    {
        dict.insert(worddict[i]); // store the strings of dictionary into set dict
    }
    vector<bool> dp(s.size()+1,false);// decalre a dp of size 1+s.size() and put false at every position
    dp[0]=true;

    for(int i=1;i<=s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j])
            {
                string word=s.substr(j,i-j);
                if(dict.find(word)!=dict.end()) // if the string word is present in the set dict
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[s.size()]; //return the last index of dp
}

int main()
{
    string s;
    cin>>s;
    int n; 
    cin>>n;
    vector<string> worddict;  
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        worddict.push_back(str);
    }
    wordbreak(s,worddict)?cout<<"true":cout<<"false";
    return 0;	
}
