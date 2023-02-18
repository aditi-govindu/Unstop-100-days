# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Priya is given an integer n and an integer start. 
Her teacher told her to make  an array nums where nums[i] = start + 2 * i (0-indexed) 
and n == nums.length. After that she needs to do the bitwise XOR of all elements of nums. 
Let this be x. 
Finally she needs to print the number of primes which are less than or equal to x.
'''

def Primes(n):
    # Sieve of erathoneses
    prime = [True for i in range(n+1)]
    count = 0
    p = 2

    while(p*p <= n):
        if(prime[p] == True):
            for i in range(p*p, n+1, p):
                prime[i] = False
        p += 1

    for p in range(2, n+1):
        if prime[p]:
            count += 1    
            
    return count


n, start = map(int, input().split())
xor = 0

for i in range(n):
    xor = xor ^ (start + 2*i)

print(Primes(xor))
