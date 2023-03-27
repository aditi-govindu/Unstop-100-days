def can_segment(s, word_set):
    n = len(s)
    max_length = max(len(word) for word in word_set)

    dp = [False] * (n+1)
    dp[0] = True

    for i in range(1, n+1):
        for j in range(1, min(i, max_length)+1):
            if s[i-j:i] in word_set and dp[i-j]:
                dp[i] = True
                break

    return dp[n]


# Read input
s = input().strip()
n = int(input().strip())
word_set = set()
for i in range(n):
    word_set.add(input().strip())

# Check if s can be segmented into words from the dictionary
if can_segment(s, word_set):
    print("true")
else:
    print("false")
