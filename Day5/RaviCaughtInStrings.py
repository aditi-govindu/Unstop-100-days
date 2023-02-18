# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Ravi was playing with strings. One day he came across a string that reads the same if read from the forward to the backward or from backward to forward. On searching online, he found that these are the unique strings called palindromes.

Later, he found that every string he came across had some or the other palindromic substrings. Later, he wondered how to calculate the longest palindromic substring possible in every string he came across.

Given a string, help Ravi find out the length of the longest palindromic substring of that string.
'''
def Palindromes(string, n):
    res = set()

    for i in range(n):
        for j in range(i+1, n+1):
            # Add length of substrings that are equal to reverse string to set
            if string[i:j] == string[i:j][::-1]:
                res.add(len(string[i:j]))
    return max(res)

# Driver code
n = int(input())
string = input()
print(Palindromes(string, n))
