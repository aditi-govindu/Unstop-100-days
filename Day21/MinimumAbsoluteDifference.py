'''
Description: Marco likes numbers a lot. His friend gave him an array of distinct integers arr, and asked him to find all pairs of elements with the minimum absolute difference of any two elements.

He asked him to return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
def minAbsDiffPairs(arr, n):
 
    ans = []
 
    # Sort the array
    arr.sort()
 
    # Stores the minimal absolute difference
    minDiff = 10 ** 9
 
    for i in range(n - 1):
        minDiff = min(minDiff, (arr[i + 1] - arr[i]))
 
    for i in range(n - 1):
        pair = []
        if arr[i + 1] - arr[i] == minDiff:
            pair.append(min(arr[i], arr[i + 1]))
            pair.append(max(arr[i], arr[i + 1]))
            ans.append(pair)
             
    return ans

n = int(input())
numbers = [int(x) for x in input().split()]
solution = minAbsDiffPairs(numbers, n)

print(len(solution))
for sol in solution:
    print(sol[0], sol[1],end = ' ')
    print()