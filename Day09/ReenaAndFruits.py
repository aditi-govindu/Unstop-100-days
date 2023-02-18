# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Reena is given a basket array containing 2n fruits. She needs to pair these fruits into n pairs (a1,b1) ,( a2,b2).....,(an,bn) such that the sum of the min(ai,bi) for all i is maximized.Print the maximized sum.
'''
n = int(input())
data = [int(x) for x in input().split()]
# Sort data in ascending order
data.sort()
maxSum = 0
# Minimum element of every pair will be at even index
for i in range(0, len(data), 2):
    maxSum += data[i]
print(maxSum)