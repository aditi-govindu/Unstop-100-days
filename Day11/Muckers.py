# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description:  Muckers, also known as ring toss (not to be confused with the ring toss carnival game) or circle horseshoes, is an outdoor game, commonly played at summer camps, in which players take turns throwing circular rings at a stick, standing about one foot high. George goes to one of the stalls in his city fair, where he finds the game of muckers, and there is a prize if he wins the game. There are ‘n’ rings, and each ring is either red, green, or blue. The rings are distributed across 10 rods labeled from 0 to 9. Now, if he can place all the colors of the rings onto the rod, he will get some prize. The prize is given based on the number of rods with all three colors of rings at the end of the game.

Now your task is to number of rods that have all three colors of rings on them.You are given a string rings of length 2n that describes the n rings that are placed onto the rods. Every two characters in rings forms a color-position pair that is used to describe each ring where:

The first character of the ith pair denotes the ith ring's color ('r', 'g', 'b').
The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').
'''

from collections import defaultdict

throws = input()
rod_colors = defaultdict(list)

for index, char in enumerate(throws):
    if char.isalpha():
        # If current input is a letter, next is rod it is thrown on
        rod_colors[int(throws[index + 1])].append(char)

count = 0
for rod, colors in rod_colors.items():
    # If rod has all 3 colors - red, blue, green - increment count
    if 'r' in rod_colors[rod] and 'g' in rod_colors[rod] and 'b' in rod_colors[rod]:
        count += 1
print(count)
