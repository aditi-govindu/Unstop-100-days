'''
Description: Ashish is provided with a collection of n strings in which some strings are of repeating nature but he has been given with a number k. His task is to find the kth unique string. Also before finding the kth unique string he has to sort each individual string beforehand. If there are fewer unique strings than k return empty string. As his best friend, your task is to help Ashish in accomplishing the task.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())

hashmap = {}
for i in range(n):
    letter = input()
    if letter in hashmap:
        hashmap[letter] += 1
    else:
        hashmap[letter] = 1
k = int(input())

distinct = [key for key, val in hashmap.items() if val == 1]

if len(distinct) < k:
    print('')
else:
    print(distinct[k-1])

