# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Ram is provided with a sequence of numbers by wizard betaal. His task is to sort that sequence and concatenate with it. When he presents the doubled sequence only then he will be freed from the wizard. Your task is to help him in concatenating the sequence with itself.
'''

n = int(input())
original = [int(x) for x in input().split()]
# Sort the input
original.sort()
# Duplicate the sorted array
original.extend(original)
# Display result for Ram's freedom
for freedom in original:
    print(freedom, end=' ')