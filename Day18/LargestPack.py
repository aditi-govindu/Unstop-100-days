# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: A toy manufacturing factory produced n marbles in a day. According to the factory rules, the number of marbles in a pack must be a power of 2. Find the size of the largest pack of marbles that can be produced using n or fewer marbles.
'''
def power2(n):
    for i in range(n):
        if(2**i == n):
            return 2**i
        elif(2**i > n):
            return 2**(i-1)

n = int(input())
print(power2(n))
