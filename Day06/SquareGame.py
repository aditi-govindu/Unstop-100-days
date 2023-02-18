# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: John and Johnny are playing a square-square game. John gives a task to Johnny. If Johnny completes the task in a given time, she will win the game.

Johnny has an array of numbers sorted in non-decreasing order. She has to do the squares of numbers of the array and return the array in non-decreasing order.

Help Johnny so that she can win the game.
'''

n = int(input())
data = [int(n)**2 for n in input().split()]
data.sort()
for d in data:
    print(d, end=' ')
