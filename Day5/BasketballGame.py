# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You are keeping score for a basketball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.

"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.

"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.

"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Return the sum of all the scores on the record.
'''
n = int(input())
data = input().split()
scores = []

for i in data:
    try:
        # If input is a number, push to stack
        val = int(i)
        scores.append(val)
    except:
        # Remove last score
        if i == 'C':
            scores.pop()
        elif i == 'D':
            # Duplicate last score and add to stack
            scores.append(scores[-1]*2)
        elif i == '+':
            # Add last 2 records and push result to stack
            scores.append(scores[-1] + scores[-2])
# Final score is total stack sum
print(sum(scores))