'''
Description: Alice and Bob both are friends and are playing with each other. Alice receives a new typewriter and is very excited to type the words on it. He challenged Bob to write the same word as his on the typewriter. Both are kids and are making some mistakes in typing and are making use of the ‘#’ key on a typewriter to delete the last character printed on it.

Note that after backspacing an empty text, the text will continue empty.
'''

def deleteString(s):
    stack = []
    # If current letter is #, remove previous one from top of stack
    for letter in s:
        if stack and letter == '#':
            stack.pop()
        else:
            stack.append(letter)
    return ''.join(stack)

bob = input().strip()
alice = input().strip()

bob_s = deleteString(bob)
alice_s = deleteString(alice)

# Display YES if equal
if bob_s == alice_s:
    print('YES')
else:
    print('NO')
