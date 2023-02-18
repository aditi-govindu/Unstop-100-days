# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Bob is an arrogant person and got into an argument with the developer of programming languages. In his fit of rage, he declared that he won’t use any built-in libraries from now on.

Later that day, he started to implement several functions and data structures on his own, but he had trouble in implementing HashMap. After failing several times, he asked you for help.

He wants his HashMap to map unique integer keys to integer values and perform 3 basic operations in response to the following queries:

Insert – Insert a given (key, value) pair into the map. If the key already exists, update its corresponding value. No need to print anything in this type of query.
Get – Print the value corresponding to the given key, and print -1 if the key is not present.
Delete – Delete the key and its corresponding value if the key is present in the map. No need to print anything in this type of query.
Help Bob implement his own HashMap without using any built-in Hash table libraries.
'''

def insert(hashmap, key, value):
    hashmap[key] = value

def get(hashmap, key):
    if key in hashmap:
        print(hashmap[key])
    else:
        print(-1)

def delete(hashmap, key):
    if key in hashmap:
        del hashmap[key]

hashmap = {}
n = int(input())

for i in range(n):
    data = input().split()
    type = int(data[0])
    key = int(data[1])

    if type == 1:
        value = int(data[2])
        insert(hashmap, key, value)
    
    elif type == 2:
        get(hashmap, key)
    
    else:
        delete(hashmap, key)