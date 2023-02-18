# Description: Mohan gave Rohan a challenge. Mohan said “I bet you cannot calculate the total number of set bits in every number from 1 to N under 2 seconds.” In the heat of the moment Rohan accepted the challenge. Now he doesn’t know how to achieve this but he doesn’t wanna lose to Mohan either. He asks for your help in achieving this.

n = int(input())
total = 0

for i in range(1, n+1):
    total += bin(i).count('1')
print(total)