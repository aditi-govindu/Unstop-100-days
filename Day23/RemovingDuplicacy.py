'''
Description: Given a string, you can perform the below-mentioned operation till the duplicacy of the string is not removed. A string is said to contain duplicacy if any two adjacent characters are the same.

A duplicate removal consists of choosing two adjacent and equal letters and removing them.

You can repeatedly make duplicate removals on the given string until you no longer can.

Print the string after removing the duplicacyof the string.
'''

def recursiveHelper(s):
    stack = []

    for letter in s:
        # If letter same as top of stack, pop
        if stack and letter == stack[-1]:
            stack.pop()
        else:
            stack.append(letter)

    return ''.join(stack)

string = input()
print(recursiveHelper(string))