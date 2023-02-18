'''
Description: You are given an array of integers arr, which represents the numbers on a 
chalkboard. Alice and Bob alternatingly, erase one number from the chalkboard.
If erasing a number causes the bitwise XOR of all the chalkboard elements to become 0, 
the player who is playing the current turn loses.
The bitwise XOR of one element equals that element, and the bitwise XOR of no elements equals 0.
Also, if any player begins their turn with the bitwise XOR of all the chalkboard 
elements equal to 0, that player wins.
Given the array arr, find who will win the game, if Alice goes first to 
erase the number if both players play optimally.
'''

# Input from user
n = int(input())
numbers = [int(x) for x in input().split()]

xor = 0
for num in numbers:
    xor ^= num

# If array has even length or xor is 0, Alice wins
if n%2 == 0 or xor == 0:
    print("ALICE")
else:
    print("BOB")