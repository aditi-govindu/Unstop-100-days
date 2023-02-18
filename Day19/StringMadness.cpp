#include<bits/stdc++.h>
using namespace std;

/*
Description: Ravi was learning string data structure by searching online and 
solving problems related to strings when he got stuck. He asked you to help.
The problem defined the madness of the string as the length of the longest 
non-palindromic substring in the given string. Given a string print its madness.
*/

int main()
{
   string s;
   cin>>s;
   bool allsame = true; //checking if all characters are the same
   for(int i=1; i<s.size(); i++)
   {
      if(s[i] != s[0])
         allsame = false;
   }

   bool ispalindrome = true; //checking if the current string is a palindrome or not
   int st = 0, e = s.size()-1;
   while(st < e)
   {
      if(s[st] != s[e])
      {
         ispalindrome = false;
         break;
      }
      st++;
      e--;
   }
   if(allsame) //if all are same print 0
      cout<<0<<endl;
   else if(ispalindrome) //if palindrome print n-1
      cout<<(s.size()-1);
   else              //if not palindrom print n
      cout<<s.size(); 
   return 0;
}