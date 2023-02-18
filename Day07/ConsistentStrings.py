# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.
'''
permitted = [x for x in input()]
n = int(input())
strings = [s for s in input().split()]
valid

for string in strings:
    for letter in string:
        if letter not in permitted:
            invalid += 1
            break
print(n - invalid)