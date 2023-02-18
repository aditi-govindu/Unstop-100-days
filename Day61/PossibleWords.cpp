#include <bits/stdc++.h>
using namespace std;

/*
Description: Vikas saw saurav typing something on his phone and sending a message and deleting it, he wants to know what the message was. But he only remembers the numbers that saurav pressed while typing the keys and not the letters, vikas has a classical keypad phone as shown in an image below. He cannot find out what saurav typed and wants your help in determining all the possibilities of words that could've been typed using the keys on the keypad. Help him by implementing a code that can output all the possible words that could have been typed given the numbers that were pressed.

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in sorted order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

const vector<string> pad = 
{
    // 0 and 1 map to no letter combinations
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

vector<string> letterCombinations(string digits) 
{
    if (digits.empty()) return {};
    vector<string> result;
    result.push_back("");
    
    for(auto digit: digits) 
    {
        vector<string> tmp;
        // Get letter combinations for input
        for(auto candidate: pad[digit - '0']) 
        {
            for(auto s: result)
                tmp.push_back(s + candidate);
        }
        // Swap any letters
        result.swap(tmp);
    }
    return result;
}

int main() 
{ 
    string digits;
    cin >> digits;

    vector<string> result;
    result = letterCombinations(digits);
    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<" ";

    return 0; 
}