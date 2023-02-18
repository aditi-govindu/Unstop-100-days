/*
Description: Shyam is given a Numpad in which he has some keys broken. 
He has to type a text string given to him. 
Your task is to help Shyam in counting how many words he can type from the given Numpad. 
The broken keys are also given in the form of a string.
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
typedef long long ll;

int canBeTypedWords(string text, string brokenLetters) {
    vector<int> ch(26,0);
    // store the broken letters in ch vector
    for(char c: brokenLetters){
        ch[c-'a']=1;
    }
    int cnt=0,ans=0;
    //traversing the text string
    for(int i=0;i<text.length();i++)
    {
        //if char is ' ' means that we got a new word
        if(text[i]==' ')
        {
            // cnt remain 0 means that there is no broken letter in this word
            if(cnt==0) ans++;
            cnt=0; //reinitialize cnt to 0 as new word start from here
        }
        else if(ch[text[i]-'a'] == 1)
        { 
            //if char is present in ch then just increment the cnt
            cnt++;
        }
    }
    //for last word in string
    if(cnt==0) ans++;
    return ans;
}


void solve()
{
    string text;
    getline(cin,text);
    string brokenLetters;
    cin>>brokenLetters;

    cout<<canBeTypedWords(text,brokenLetters)<<endl;
}


int main()
{
    solve();
    return 0;
}