# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: A string is called an AB string if and only if all the a’s (if present), appear before all of the b’s (if present) in the string.

Given a string, your task is to tell whether it is an AB string or not.
'''
def location(string):
    # Get first index of letter b in string
    idxb = string.index('b')
    # Get all indexes of a in string:
    idxa = [i for i, letter in enumerate(string) if letter == 'a']
    # If any a appears after first b, return False
    for loc in idxa:
        if loc > idxb:
            return False
    return True

string = input()
# Consider string with all a, all b
if string == 'a' or string == 'b' or string.find('b') == -1 or string.find('a') == -1:
    print('YES')
elif location(string):
    print('YES')
else:
    print('NO')