# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.
'''

string = input()
n = len(string)

# Split string into 2 parts
part1 = string[:n//2]
part2 = string[n//2:]

part1_vowels = 0
part2_vowels = 0

# Count no. of vowels in part 1
for letter in part1:
    if letter in 'aeiouAEIOU':
        part1_vowels += 1

# Count no. of vowels in part 2
for letter in part2:
    if letter in 'aeiouAEIOU':
        part2_vowels += 1

# IF count of vowles are equal, print true for alike
if(part1_vowels == part2_vowels):
    print('true')
else:
    print('false')