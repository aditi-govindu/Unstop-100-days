# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Rohit got a sentence consists of a group of words separated by a single space with no leading or trailing spaces. Each word is made up of lowercase and capital letters in English from her ma'am.

Shuffle a sentence by adding the 1-indexed word position to each word and then rearranging the words in the sentence.

The phrase "This is a sentence" can be scrambled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".

Ma'am told rohit to reconstruct and return the original sentence from a scrambled sentence s consisting no more than 9 words.

Rohit was having lot of task to complete; you think as a best friend of rohit to figure out the solution for the task given by ma'am.
'''

string = input()
word_location = {}
expected = ''

for word in string.split():
    # Location of the word is the last character in word
    position = int(word[-1])
    # Store a hashmap of position and word
    word_location[position] = word[:len(word) - 1]

# Sort hasmap based on location
for i in sorted(word_location.keys()):
    # Append words in order to expected string with whitespace
    expected += word_location[i] + ' '
# Remove space
expected.rstrip()
print(expected)