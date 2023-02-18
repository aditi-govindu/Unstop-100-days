'''
Description: Melisa likes XOR operation very much. Recently her teacher gave her a beautiful array ‘a’ – a1, a2, . . ., an where ‘n’ is the size of the array and asked her to find the XOR of all the subarray XOR's. The subarray XOR’s is the XOR of all the subarray elements. She is confused about how to solve the problem? Now your task is to help her to find the total XOR.
'''

n = int(input())
data = [int(x) for x in input().split()]
xor = 0

for i, num in enumerate(data):
    # Count frequency of occurence of number in subarrays
    freq = (i + 1) * (n - i)
    # If occurence is odd, consider number for XOR
    if freq % 2 != 0:
        xor ^= num
# Display final result to user
print(xor)
