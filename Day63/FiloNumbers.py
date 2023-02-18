'''
Ravi learned about various kinds of numbers when he came across a special type called the Filo Numbers.

A Filo Number is any number that can be expressed as a sum of consecutive natural numbers.

As he studied more, he became more interested after knowing that every positive integer can be expressed as a Filo Number.

 However, after thinking for a while, he thought that a positive integer could be expressed as a Filo Number in more than one way, and later, he got confused about how he could calculate those ways.

Given a positive integer, determine the number of ways in which it can be expressed as a Filo Number.
'''

n = int(input())
count = 0
k = 1

while (2*n) > (k*(k-1)):
    num = n - (k*(k-1)) // 2

    # Remaining number is valid combination, increment count
    if(num % k == 0):
        count += 1
    k += 1
    
print(count)