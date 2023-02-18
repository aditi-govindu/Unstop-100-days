# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Marco likes words a lot. He got a book from his friend where many words are written, his friend Alice gave him a pattern and challenged him to find the words from the book having the same pattern given by him.

Help Marco, so that he can win the challenge.
'''

def findAndReplacePattern(words, pattern):
    def match(word):
        forward = {}
        reverse = {}
        
        for w, p in zip(word, pattern):
            # if mapping of forward not same as reverse, permutation not found
            if w not in forward: 
                forward[w] = p
            if p not in reverse: 
                reverse[p] = w
            if(forward[w], reverse[p]) != (p, w):
                return False
        return True
        
    return list(filter(match, words))

n = int(input())
words = [s for s in input().split()]
pattern = input()
result = findAndReplacePattern(words, pattern)

# Display results to user
print(len(result))
for ans in result:
    print(ans, end = ' ')