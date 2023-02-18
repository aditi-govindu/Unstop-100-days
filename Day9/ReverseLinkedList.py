# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Ram gave Shyaam a challenge, he gave shyaam the head of a linked list.

He asked Shyaam to reverse the nodes of the linked list.
'''
n = int(input())
data = [int(d) for d in input().split()]
data.reverse()
for val in data:
    print(val, end=' ')