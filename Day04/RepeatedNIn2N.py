# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Kritika is given an integer array nums with the following properties:

length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Help kritika print the element which is repeated n times
'''

from collections import Counter

n = int(input())
data = input()
arr = []

# Create hashmap of all values seen
for val in data.split():
    arr.append(int(val))
count = Counter(arr)

# If any count is n/2, it has been repeated exactly n times
for key, val in count.items():
    if val == n//2:
        print(key)
        break
    