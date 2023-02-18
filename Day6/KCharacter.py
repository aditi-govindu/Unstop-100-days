# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: One day jack finds a string of characters. He is very keen to arrange the characters in reverse order, i.e., first characters become the last characters, second characters become the second-last characters, and so on. Now he wants your help  to find the kth character from the new string formed after reverse the original string.
'''

n, k = map(int, input().split())
string = input()
# Display kth character from end of string
print(string[n-k])