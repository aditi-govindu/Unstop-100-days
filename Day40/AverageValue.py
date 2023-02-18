# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Ram has n coins of distinct values.He wants to calculate the average value of the coins,But he has to exclude the maximum value coin and Minimum Value coins.
'''

n = int(input())
coins = [int(x) for x in input().split()]
# Sort coins in ascending order
coins.sort()
# Remove first and last element while computing average
avg = sum(coins[1 : n-1]) / (n-2)
# Display final answer upto 5 decimal spaces
print('%.5f'%avg)