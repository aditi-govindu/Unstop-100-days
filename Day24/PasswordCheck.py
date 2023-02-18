'''
Description: You are given a password of length N in form of an array. You have to check if the password is valid or not.

A valid password is a password in which the occurrence of each element is unique (Refer to sample I/O).

Print true if the password is valid, otherwise print false.
'''

n = int(input())
data = [int(x) for x in input().split()]
numbers = {}
counter = []

# Count no. of times every digit is seen in password
for digit in data:
    if digit in numbers:
        numbers[digit] += 1
    else:
        numbers[digit] = 1

# Get count of digits
for k, v in numbers.items():
    counter.append(v)

# If any digit is repeated, set size will not be equal to list size
if len(counter) != len(set(counter)):
    print('false')
else:
    print('true')