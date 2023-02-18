'''
Description: Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings and encapsulate them in ‘(’ and ‘)’. For example RRLL is balanced so you have to return “(RRLL)”.

Return the string such that maximum amount of balanced encapsulated strings are there.
'''
def balancedStringSplit(s):
    count = 0
    ans = ''
    result = '('

    # Increment count when R seen
    for letter in s:
        if letter == 'R':
            count += 1
        else:
            count -= 1
        # Add letter to temp variable
        result += letter

        # If all R and L matched, put brackets
        if(count == 0):
            ans += result + ')'
            result = '('
    return ans

s = input()
print(balancedStringSplit(s))
