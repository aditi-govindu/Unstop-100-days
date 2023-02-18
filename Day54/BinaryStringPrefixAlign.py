'''
Description: Marco likes strings a lot. His friend has a 1-indexed binary string of length n where all the bits are 0 initially and will flip all the bits of this binary string (i.e., change them from 0 to 1) one by one. He has given him a 1-indexed integer array flips where flips[i] indicates that the bit at index i will be flipped in the ith step.

A binary string is prefix-aligned if, after the ith step, all the bits in the inclusive range [1, i] are ones and all the other bits are zeros.

Marco has been asked to return the number of times the binary string is prefix-aligned during the flipping process.
'''

def checkPrefixAlign(string, i):
    part1 = string[0 : i + 1]
    part2 = string[i + 1: ]

    # 1 part must have all 1 and the other all 0
    return all(i == '1' for i in part1) and all(i == '0' for i in part2)

# Driver code
n = int(input())
data = [int(x) for x in input().split()]
string = ['0'] * n
count = 0

for index, i in enumerate(data):
    string[i - 1] = '1'
    # If function is true, increment count
    if(checkPrefixAlign(string, index)):
        count += 1
print(count)