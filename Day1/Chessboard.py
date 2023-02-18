# Enter your code here. Read input from STDIN. Print output to STDOUT

'''
Description: Above is the standard representation of a chessboard.

This could be imagined as a 2D cartesian plane, with the x axis being represented by the alphabets and y axis by the numbers.

Given coordinates in the form of string, print if that cell is white or black.
'''
location = input()
col = location[0]
row = int(location[1])

if col in ['a','c','e','g']:
    if row%2 == 0:
        print('White')
    else:
        print('Black')
else:
    if row%2 == 0:
        print('Black')
    else:
        print('White')