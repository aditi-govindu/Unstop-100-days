#include <bits/stdc++.h>
using namespace std;

/*
Description: Lewis is a computer teacher in a high school, 
and he is preparing a problem for giving in the test for his computer class students. 
He has a string ‘S’ with English letters and some brackets. 
He asks to reverse the strings in each pair of matching parentheses, 
starting from the innermost one. But he has some other work to complete so 
he wants your help to find the solution to this problem.
*/

 string reverseParentheses(string s) 
 {
        int n = s.length();  // length of string
        vector<int> opened, pair(n);
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == '(') // when we encountered the open bracket
                opened.push_back(i);
            if (s[i] == ')') 
            {  // when we encountered the closing bracket
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string res;
        for (int i = 0, d = 1; i < n; i += d) 
        {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;  // change the d when reaching the opposite brackets
            else
                res += s[i];
        }
        return res;
    }

int main()
{
	string s; 
    cin >> s; // input string
    cout << reverseParentheses(s); 
	return 0;
}