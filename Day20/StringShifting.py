# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You are given a lowercase English letter string s and an integer array shifts of the same length.

You have toshift each of the characters of the string s[i] by shifts[i] units. If we shift any character it transforms into the next available character in the English alphabets for e.g. ‘a’ become ‘b’, ‘b’ becomes ‘c’, and the last character ‘z’ becomes ‘a’.

Print the final string after all such shifts to s are applied.
'''

n = int(input())
letters = input()
shifts = [int(x) for x in input().split()]
ans = ''

for index in range(n):
    letter = letters[index]
    shift = shifts[index]
    # Shift letter by given places and mod 26
    ans += chr((ord(letter) - ord('a') + shift) % 26 + ord('a'))

print(ans)
