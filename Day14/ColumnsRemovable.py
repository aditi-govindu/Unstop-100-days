# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Dhrutik is given an array of n strings, all of which are the same length.

The strings can be organised in a grid, with one string on each line. strs = ["abc", "bce", "cae"] can be structured as follows:

abc

bce

cae

Dhrutik wish to get rid of the columns that aren't alphabetically sorted. Columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted in the preceding example (0-indexed), but column 1 ('b', 'c', 'a') is not, thus you should help Dhrutik solve the problem by deleting columns.

Return the total number of columns you'll be deleting.
'''
rows, cols = map(int, input().split())
words = [w for w in input().split()]
column_wise = []
to_delete = []

# Traverse input strings column wise
for i in range(cols):
    temp = ''
    for word in words:
        temp += word[i]
    column_wise.append(temp)

for index, col in enumerate(column_wise):
    for i in range(len(col) - 1):
        # If letter greater than next letter in current column, column must be deleted
        if col[i] > col[i+1]:
            to_delete.append(i)
            break

# Display count of columns deleted
print(len(to_delete))
