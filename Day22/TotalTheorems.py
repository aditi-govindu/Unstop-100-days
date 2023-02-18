# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Larry is reading a math book for his class test, which contains ‘n’ chapters. In each of ith chapters, there are ‘ai’ theorems in it. He wants to mark the number of theorems he has to learn until the ith chapter end. Your task is to help him calculate the number of theorems till each of ith chapter.
'''

n = int(input())
theorems = [int(x) for x in input().split()]
total = 0

for ai in theorems:
    # Display prefix sum of every term
    total += ai
    print(total, end = ' ')
