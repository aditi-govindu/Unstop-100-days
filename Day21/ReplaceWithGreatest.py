# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description:  Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1 as there is no element to the right of it.

After doing so, display the array thus formed.
'''
def nextLargerElement(arr, n):
    i = n - 1
    nextGreater = -1

    while i >= 0:
        if(arr[i] > nextGreater):
            arr[i], nextGreater = nextGreater, arr[i]
            i -= 1
            continue

        arr[i] = nextGreater
        i -= 1
    return arr

n = int(input())
numbers = [int(x) for x in input().split()]
result = nextLargerElement(numbers, n)
for val in result:
    print(val, end = ' ')