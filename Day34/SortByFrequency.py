'''
Description: Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string. If two characters have the same frequency the lexicographically larger alphabet will appear first.
'''

from collections import Counter

def frequencySort(s: str) -> str:
    count = Counter(s)
    # Store count of letter and letter in an array
    arr = [(count[c], c) for c in count.keys()]
    # Sort array in descending order of count
    arr.sort(reverse = True)
    # Store count of letters, as many times as it appears
    return ''.join(x[1]*x[0] for x in arr)  

string = input()
print(frequencySort(string))