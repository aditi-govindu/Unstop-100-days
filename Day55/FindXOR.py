# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You are given two arrays arr1 and arr2 of size n and m respectively consisting of non negative integers. Your task is to perform the AND operation between every pair of those two arrays and find the XOR of all those pair results.
'''

n, m = map(int, input().split())
arr1 = [int(x) for x in input().split()]
arr2 = [int(x) for x in input().split()]

xor1 = 0
xor2 = 0

# XOR array elements first, then AND the results
for n1 in arr1:
    xor1 ^= n1
for n2 in arr2:
    xor2 ^= n2
print(xor1 & xor2)