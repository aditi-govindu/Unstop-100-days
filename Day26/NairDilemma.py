# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Nair is given an array of numbers. All numbers occur twice in the array except one number. Nair has been assigned the task to find that number occurring only once.

Your task is to help Nair find the required number.
'''

from collections import Counter

n = int(input())
numbers = [int(x) for x in input().split()]

count = Counter(numbers)

# Display key if value is 1
for k, v in count.items():
    if v == 1:
        print(k)
        break