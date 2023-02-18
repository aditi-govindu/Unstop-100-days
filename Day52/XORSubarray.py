# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elementsfrom lefti to righti (that is, arr[lefti]XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.
'''

n = int(input())
data = [int(x) for x in input().split()]
m = int(input())
k = int(input())

# XOR subarray in given range
for i in range(m):
    start, end = map(int, input().split())
    xor = 0

    for num in data[start : end + 1]:
        xor ^= num
    print(xor)
