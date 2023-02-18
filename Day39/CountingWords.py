# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Sid is reading a paragraph of a story. There he notices various sentences and he is curious about the length of the longest sentence.
Help Sid find the length of the longest sentence in the paragraph.
Two sentences are differentiated by a full stop or a comma, and there are no other symbols used except these two.
'''
# Import module
import re

string = input()
# Separate strings based on , or .
parts = re.split(', |\.',string)
ans = []

# Count words in every part
for part in parts:
    ans.append(len(part.split()))
print(max(ans))