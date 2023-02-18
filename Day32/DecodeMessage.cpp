/*
Description: Ram and Shyam are two friends belonging from two different cities . They exchange msgs weekly.The msgs are very crucial so that no third person can see the message.

But they sent msg via Jadav , a naughty minded person . He usually reads the given msgs . So, Ram and Shyam started talking in codewords . They set a convention for every letter in the English Alphabet.

Like:   ‘a’ to ‘i’ code is 1 to 9
        ‘j’ to  ‘z’ code is 10# to 26#
*/

#include <bits/stdc++.h>
using namespace std;

string decodemsg(string s)
{
    string ans="";
    int i=s.size()-1;
    string temp="";
    while(i>=0)
    {
        if(s[i]=='#')
        {
            temp=s[i-1];
            temp= s[i-2]+temp;
            int k=stoi(temp);
            ans = char(k-1+'a') + ans;
            temp="";
            i-=3;
        }
        else
        {
            temp=s[i];
            int k=stoi(temp);
            i--;
            temp="";
            ans = char(k-1+'a') + ans;
        }
    }
    return ans;
}

int main() 
{
	string s;
	cin>>s;
	string ans=decodemsg(s);
	cout<<ans;
	return 0;
}